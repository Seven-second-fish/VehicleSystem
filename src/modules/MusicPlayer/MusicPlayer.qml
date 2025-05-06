import QtQuick 2.15
import QtQuick.Controls 2.15

Item {
    width: 200; height: 100
    // color: "lightblue"

    anchors.fill: parent
    Text {
        anchors.centerIn: parent
        text: "Music Module"
    }

    function play() {
        console.log("QML 接收到播放命令")
    }
}
