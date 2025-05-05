import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Window {
    visible: true
    width: 800
    height: 480
    title: "Vehicle System"

    // 全屏加载页面用的 Loader（在最顶层）
    Loader {
        id: fullscreenLoader
        anchors.fill: parent
        z: 999 // 保证覆盖整个界面
    }

    Row {
        anchors.fill: parent

        // 左侧 StackView：用于页面切换
        StackView {
            id: stackView
            width: 236
            height: parent.height
            initialItem: startPage
        }

        // 右侧区域（可空着或用于显示其他模块）
        Rectangle {
            width: parent.width - stackView.width
            height: parent.height
            color: "#f0f0f0"
        }
    }

    // 首页面，按钮在这个页面里
    Component {
        id: startPage
        Item {
            width: stackView.width
            height: 600
            Column{
                width: stackView.width
                height: 600
                spacing: 10

                Button{
                    width: parent.width
                    height: 30
                    text: "music"
                    onClicked: {
                        // var component = Qt.createComponent("modules/MusicPlayer/Music.qml");
                        // console.log(component.status === Component.Ready)
                        // if (component.status === Component.Ready) {
                        //     // var page = component.createObject(stackView, { width: stackView.parent.width, height: stackView.height });
                        //     // stackView.replace(page);
                        //     stackView.replace(component)
                        // }
                        fullscreenLoader.source = "modules/MusicPlayer/Music.qml"
                    }
                }
                Button{
                    width: parent.width
                    height: 30
                    text: "setting"
                    onClicked: stackView.push("modules/MusicPlayer/Music.qml")
                }
                Button{
                    width: parent.width
                    height: 30
                    text: "video"
                    onClicked: stackView.push("modules/MusicPlayer/Music.qml")
                }
            }


        }
    }
}
