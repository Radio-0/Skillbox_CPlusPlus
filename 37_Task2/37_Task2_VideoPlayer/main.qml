import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.12

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Video Player")
    Rectangle {
        width: 640
        height: 360
        color: "black"
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: -20
    }
    Text{
        id: video
        text: "Video"
        color: "white"
        font.pointSize: 24
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: -20
    }
    ProgressBar{
        id: progressLine
        width: 400
        value: 0
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: 225
    }
    Button{
        id: play
        text: "▶"
        font.pointSize: 15
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: 190
        onClicked: video.text = "Start"
    }
    Button{
        id: pause
        text: "⏸️"
        font.pointSize: 15
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.horizontalCenterOffset: 110
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: 190
        onClicked: video.text = "Pause"
    }
    Button{
        id: stop
        text: "⏹"
        font.pointSize: 15
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.horizontalCenterOffset: -110
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: 190
        onClicked:{
            video.text = "Stop"
            progressLine.value = 0
        }
    }
    Button{
        id: rewind
        text: "⏪"
        font.pointSize: 15
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.horizontalCenterOffset: -220
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: 190
        onClicked: progressLine.value -= 0.2
    }
    Button{
        id: forward
        text: "⏩"
        font.pointSize: 15
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.horizontalCenterOffset: 220
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: 190
        onClicked: progressLine.value += 0.2
    }
}
