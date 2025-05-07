import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import MusicPlayer 1.0
import Settings 1.0
import VehicleInfo 1.0
import Navigation 1.0

Window {
    visible: true
    width: 800
    height: 480
    title: "Vehicle System"

    // 使用设置控制器的主题
    color: settingsController.darkMode ? "#2c2c2c" : "#f0f0f0"

    // 全屏加载页面用的 Loader（在最顶层）
    Loader {
        id: fullscreenLoader
        anchors.fill: parent
        z: 999 // 保证覆盖整个界面
    }

    MusicView{

    }

    NavigationView{

    }

    Row {
        anchors.fill: parent

        // 左侧导航栏
        Column {
            width: 200
            height: parent.height
            spacing: 10
            padding: 10

            // 导航按钮
            Button {
                width: parent.width
                text: "Music"
                onClicked: stackView.replace("qrc:/modules/MusicPlayer/MusicView.qml")
            }

            Button {
                width: parent.width
                text: "Settings"
                onClicked: stackView.replace("qrc:/modules/Settings/SettingsView.qml")
            }

            Button {
                width: parent.width
                text: "Vehicle Info"
                onClicked: stackView.replace("qrc:/modules/VehicleInfo/VehicleInfoView.qml")
            }

            Button {
                width: parent.width
                text: "Navigation"
                onClicked: stackView.replace("qrc:/modules/Navigation/NavigationView.qml")
            }
        }

        // 右侧内容区域
        StackView {
            id: stackView
            width: parent.width - 200
            height: parent.height
            initialItem: "qrc:/modules/MusicPlayer/MusicView.qml"
        }
    }
}
