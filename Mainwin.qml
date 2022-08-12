import QtQuick 2.0
import QtQuick.Controls 1.2
//import SERIAL 1.0
Rectangle{
    width: 640
    height: 480
    visible: true

    ComboBox {
        id: comboBox1
        x: 258
        y: 54
          model:portsNameModel

 //        }

    }
}
