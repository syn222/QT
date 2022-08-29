#include "serial.h"
#include <QDebug>
#include <QIODevice>

Serial::Serial()
{
    // 定义文本编码
    tc = QTextCodec::codecForName("UTF-8");

}

QStringList Serial::serialScan(void)
{
    QStringList serialPortList;
    serialDescription.clear(); // 每次扫描先清除串口描述信息
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        this->setPort(info);
        serialPortList.append(this->portName());
        serialDescription.append(info.description());
        qDebug() << this->portName();
        //qDebug() << info.description();
    }
    if(serialPortList.size()==0)
    {
    serialPortList.append("None");
    }
    return serialPortList;
}
void Serial::serialPortComboBox(void)
{
    const auto infos = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &info : infos)
        serialPortCombo.addItem(info.portName());

}

bool Serial::serialOpen(QString serialName, int baudRate)
{
    this->setPortName(serialName);
    if(this->open(QIODevice::ReadWrite)) {
        this->setBaudRate(baudRate);
        this->setDataBits(QSerialPort::Data8);
        this->setParity(QSerialPort::NoParity);
        this->setStopBits(QSerialPort::OneStop);
        this->setFlowControl(QSerialPort::NoFlowControl);
        // 下位机发送数据会响应这个槽函数
        connect(this, &QSerialPort::readyRead, this, &Serial::ReadData);
        return true;
    }
    return false;
}
// 读数据
void Serial::ReadData()
{
    dataBuf = this->readAll();
    this->rxByte += tc->toUnicode(dataBuf).length();
    emit this->readSignal(this->rxByte);
}
// 写数据
void Serial::sendData(QByteArray sendData)
{
    int byteTemp;
    byteTemp = this->write(sendData);
    // 发送失败返回-1
    if(byteTemp != -1)
    {
        this->txByte += byteTemp;
        emit this->sendSuccess(this->txByte);
    }
}
// 关闭串口
void Serial::serialClose()
{
    this->clear();
    this->close();
}
