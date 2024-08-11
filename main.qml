import QtQuick 2.12
import QtQuick.Controls 2.12

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Rectangle {
        anchors.centerIn: parent
        width: 200
        height: 100
        color: "lightblue"

        Text {
            anchors.centerIn: parent
            text: qsTr("Hello, WebAssembly!")
            font.pointSize: 24
        }
    }
}
