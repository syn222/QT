#ifndef SERIAL_H
#define SERIAL_H




#include <QObject>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QStringList>
#include <QString>
#include <QByteArray>
#include <QTextCodec>
#include <QComboBox>
class Serial : public QSerialPort
{
    Q_OBJECT
public:
    explicit Serial();
    // 发送字节数
    int txByte = 0;
    // 接收字节数
    int rxByte = 0;
    // 数据缓存区
    QByteArray dataBuf;
    // 串口描述内容
    QStringList serialDescription;
    // 串口扫描函数
    Q_INVOKABLE QStringList serialScan(void);
    bool serialOpen(QString serialName, int baudRate);
    void ReadData();
    void sendData(QByteArray sendData);
    void serialClose();
    Q_INVOKABLE QComboBox serialPortCombo;
    void serialPortComboBox(void);
private:
    QTextCodec *tc;
signals:
    void readSignal(int recByte);
    void sendSuccess(int sendByte);
public slots:
};

#endif // SERIAL_H
