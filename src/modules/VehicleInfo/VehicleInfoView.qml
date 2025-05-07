import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import VehicleInfo 1.0

VehicleInfoView {
    id: root
    anchors.fill: parent

    ColumnLayout {
        anchors.fill: parent
        spacing: 10

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
    }
} 