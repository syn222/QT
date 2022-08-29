import QtQuick 2.0
import QtQuick.Controls 1.2
//import SERIAL 1.0
Rectangle{
    width: 640
    height: 480
    visible: true
    property bool connectflag
    ComboBox {
        id: portid
        x: 76
        y: 71
        enabled: true
        clip: false
        visible: true
        activeFocusOnPress: false
        model:portsNameModel

        //        }

    }

    Text {
        id: portname
        x: 28
        y: 75
        width: 54
        height: 12
        text: qsTr("端口号")
        font.pixelSize: 12
    }

    ComboBox {
        id: bauardid
        x: 76
        y: 135
        layer.enabled: true
        visible: true
        clip: false
        activeFocusOnPress: false
        model: ['9600','19200','115200']
    }

    Text {
        id: bauardname
        x: 28
        y: 139
        text: qsTr("波特率")
        font.pixelSize: 12
    }

    Button {
        id: connect
        x: 76
        y: 188
        text: qsTr("打开")
        onClicked: {
        serial.serialOpen(portid.currentText,bauardid.currentText)
        connectflag=!connectflag
        connect.text=(connectflag===true)?"关闭":"打开"
        portid.enabled=!connectflag
        bauardid.enabled=!connectflag


        }
    }
}
