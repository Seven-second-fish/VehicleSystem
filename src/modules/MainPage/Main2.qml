import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

ApplicationWindow {
    id: window
    visible: true
    width: 800
    height: 480
    title: "Vehicle System"

    // 使用设置控制器的主题
    color: settingsController.darkMode ? "#2c2c2c" : "#f0f0f0"

    ColumnLayout {
        anchors.fill: parent
        spacing: 10

        // 车辆信息显示
        GroupBox {
            title: "Vehicle Information"
            Layout.fillWidth: true

            GridLayout {
                columns: 2
                anchors.fill: parent

                Label { text: "Speed:" }
                Label { text: vehicleInfoController.speed.toFixed(1) + " km/h" }

                Label { text: "Fuel Level:" }
                Label { text: vehicleInfoController.fuelLevel.toFixed(1) + "%" }

                Label { text: "Engine Temp:" }
                Label { text: vehicleInfoController.engineTemp.toFixed(1) + "°C" }

                Label { text: "Odometer:" }
                Label { text: vehicleInfoController.odometer + " km" }
            }
        }

        // 音乐播放器控制
        GroupBox {
            title: "Music Player"
            Layout.fillWidth: true

            RowLayout {
                anchors.fill: parent

                Button {
                    text: "Previous"
                    onClicked: musicController.previous()
                }

                Button {
                    text: musicController.isPlaying ? "Pause" : "Play"
                    onClicked: musicController.isPlaying ? musicController.pause() : musicController.play()
                }

                Button {
                    text: "Next"
                    onClicked: musicController.next()
                }

                Slider {
                    Layout.fillWidth: true
                    from: 0
                    to: 100
                    value: musicController.volume
                    onValueChanged: musicController.setVolume(value)
                }
            }
        }

        // 导航控制
        GroupBox {
            title: "Navigation"
            Layout.fillWidth: true

            ColumnLayout {
                anchors.fill: parent

                TextField {
                    Layout.fillWidth: true
                    placeholderText: "Enter destination"
                    onAccepted: navigationController.setDestination(text)
                }

                RowLayout {
                    Button {
                        text: "Start Navigation"
                        enabled: !navigationController.isNavigating
                        onClicked: navigationController.startNavigation()
                    }

                    Button {
                        text: "Stop Navigation"
                        enabled: navigationController.isNavigating
                        onClicked: navigationController.stopNavigation()
                    }
                }
            }
        }

        // 设置控制
        GroupBox {
            title: "Settings"
            Layout.fillWidth: true

            ColumnLayout {
                anchors.fill: parent

                CheckBox {
                    text: "Dark Mode"
                    checked: settingsController.darkMode
                    onCheckedChanged: settingsController.setDarkMode(checked)
                }

                RowLayout {
                    Label { text: "Brightness:" }
                    Slider {
                        Layout.fillWidth: true
                        from: 0
                        to: 100
                        value: settingsController.brightness
                        onValueChanged: settingsController.setBrightness(value)
                    }
                }

                ComboBox {
                    Layout.fillWidth: true
                    model: ["Default", "Blue", "Green", "Red"]
                    currentIndex: model.indexOf(settingsController.theme)
                    onCurrentTextChanged: settingsController.setTheme(currentText)
                }
            }
        }
    }
}
