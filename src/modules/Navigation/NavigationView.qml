import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import Navigation 1.0

NavigationView {
    id: root
    anchors.fill: parent

    ColumnLayout {
        anchors.fill: parent
        spacing: 10

        GroupBox {
            title: "Navigation"
            Layout.fillWidth: true

            ColumnLayout {
                anchors.fill: parent
                spacing: 10

                // 目的地输入
                TextField {
                    id: destinationInput
                    Layout.fillWidth: true
                    placeholderText: "Enter destination"
                }

                Button {
                    text: "Start Navigation"
                    Layout.fillWidth: true
                    onClicked: navigationController.startNavigation(destinationInput.text)
                }

                // 导航信息显示
                ListView {
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    model: navigationController.navigationSteps
                    delegate: ItemDelegate {
                        width: parent.width
                        text: modelData
                    }
                }
            }
        }
    }
} 