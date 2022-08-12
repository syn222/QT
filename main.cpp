//#include <QGuiApplication>
#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "serial.h"
int main(int argc, char *argv[])
{
  //QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    //QGuiApplication app(argc, argv);
    QApplication app(argc, argv);
        Serial serialtemp;
    QQmlApplicationEngine engine;


     // qmlRegisterType<Serial>("SERIAL", 1, 0, "Serial");

    QQmlContext *context = engine.rootContext();
    context->setContextProperty("portsNameModel",QVariant::fromValue(serialtemp.serialScan()));

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
