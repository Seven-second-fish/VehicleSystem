import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import Settings 1.0

SettingsView {
    id: root
    anchors.fill: parent

    ColumnLayout {
        anchors.fill: parent
        spacing: 10

        GroupBox {
            title: "Settings"
            Layout.fillWidth: true

            ColumnLayout {
                anchors.fill: parent
                spacing: 10

                // 亮度控制
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

                // 主题选择
                ComboBox {
                    Layout.fillWidth: true
                    model: ["Default", "Blue", "Green", "Red"]
                    currentIndex: model.indexOf(settingsController.theme)
                    onCurrentTextChanged: settingsController.setTheme(currentText)
                }

                // 暗黑模式切换
                Switch {
                    text: "Dark Mode"
                    checked: settingsController.darkMode
                    onCheckedChanged: settingsController.setDarkMode(checked)
                }
            }
        }
    }
} 