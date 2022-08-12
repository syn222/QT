import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
ApplicationWindow {
    visible: true
    minimumWidth: 640
    maximumWidth: 640
    minimumHeight:480
    maximumHeight: 480
    title: "SerialPort"
    //property alias mainwin: mainwindow
    Mainwin
    {
     id:mainwindow
     visible: false;
    }

    StackView
    {
        id:mystackview
        anchors.fill: parent
        initialItem: mainwindow
      }
    }

