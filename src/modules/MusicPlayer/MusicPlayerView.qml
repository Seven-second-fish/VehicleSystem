import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import MusicPlayer 1.0

MusicView {
    id: root
    anchors.fill: parent

    ColumnLayout {
        anchors.fill: parent
        spacing: 10

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
            }
        }

        // 播放列表
        ListView {
            Layout.fillWidth: true
            Layout.fillHeight: true
            model: musicController.playlist
            delegate: ItemDelegate {
                width: parent.width
                text: modelData
                highlighted: ListView.isCurrentItem
                onClicked: musicController.playTrack(index)
            }
        }
    }
} 