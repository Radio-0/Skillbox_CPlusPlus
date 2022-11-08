/*Задание 3. Пульт дистанционного управления ТВ
Реализуйте простой симулятор управления телевизором с помощью пульта, представленного в виде графического интерфейса с кнопками.
Интерфейс представляет собой вертикальное окно (в портретной ориентации) размером 240х680 пикселей. На пульте находятся кнопки переключения каналов от 0 до 9, кнопки перехода к следующему и предыдущему каналу, кнопки увеличения и уменьшения громкости с шагом в 10%.
Снизу пульта находится мини-дисплей с отображением текущего статуса: текущий выбранный канал и текущий уровень громкости в процентах.*/

import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.12

Window {
    width: 240
    height: 680
    visible: true
    title: qsTr("TV Controller")

    signal clickSig()

    Button{
        id: numb1
        text: "1"
        objectName: "numb1"
        width: 50
        height: 35
        font.pointSize: 15
        background: Rectangle {
            border.color: "black"
            radius: 10
        }

        anchors.horizontalCenter: parent.horizontalCenter
        anchors.horizontalCenterOffset: -70
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: -300
        //onClicked: canal.text += "1"
        onClicked: clickSig()
    }
    Button{
        id: numb2
        text: "2"
        objectName: "numb2"
        width: 50
        height: 35
        font.pointSize: 15
        background: Rectangle {
            border.color: "black"
            radius: 10
        }
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: -300
        onClicked: canal.text += "2"
    }
    Button{
        id: numb3
        text: "3"
        objectName: "numb3"
        width: 50
        height: 35
        font.pointSize: 15
        background: Rectangle {
            border.color: "black"
            radius: 10
        }
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.horizontalCenterOffset: 70
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: -300
        onClicked: canal.text += "3"
    }
    Button{
        id: numb4
        text: "4"
        width: 50
        height: 35
        font.pointSize: 15
        background: Rectangle {
            border.color: "black"
            radius: 10
        }
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.horizontalCenterOffset: -70
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: -250
        onClicked: canal.text += "4"
    }
    Button{
        id: numb5
        text: "5"
        width: 50
        height: 35
        font.pointSize: 15
        background: Rectangle {
            border.color: "black"
            radius: 10
        }
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: -250
        onClicked: canal.text += "5"
    }
    Button{
        id: numb6
        text: "6"
        width: 50
        height: 35
        font.pointSize: 15
        background: Rectangle {
            border.color: "black"
            radius: 10
        }
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.horizontalCenterOffset: 70
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: -250
        onClicked: canal.text += "6"
    }
    Button{
        id: numb7
        text: "7"
        width: 50
        height: 35
        font.pointSize: 15
        background: Rectangle {
            border.color: "black"
            radius: 10
        }
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.horizontalCenterOffset: -70
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: -200
        onClicked: canal.text += "7"
    }
    Button{
        id: numb8
        text: "8"
        width: 50
        height: 35
        font.pointSize: 15
        background: Rectangle {
            border.color: "black"
            radius: 10
        }
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: -200
        onClicked: canal.text += "8"
    }
    Button{
        id: numb9
        text: "9"
        width: 50
        height: 35
        font.pointSize: 15
        background: Rectangle {
            border.color: "black"
            radius: 10
        }
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.horizontalCenterOffset: 70
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: -200
        onClicked: canal.text += "9"
    }
    Button{
        id: numb0
        text: "0"
        width: 50
        height: 35
        font.pointSize: 15
        background: Rectangle {
            border.color: "black"
            radius: 10
        }
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: -150
        onClicked: canal.text += "0"
    }
    Button{
        id: volUp
        text: "+V"
        width: 70
        height: 40
        font.pointSize: 20
        background: Rectangle {
            border.color: "black"
            radius: 10
        }
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.horizontalCenterOffset: 60
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: -90
        onClicked: {
            proc = volume.text.length
            proc = 5
            volume.text += number(proc)
        }
    }
    Button{
        id: volDown
        text: "-V"
        width: 70
        height: 40
        font.pointSize: 20
        background: Rectangle {
            border.color: "black"
            radius: 10
        }
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.horizontalCenterOffset: -60
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: -90
        onClicked: volume.text = "10%"
    }
    Button{
        id: canalNext
        text: "+C"
        width: 70
        height: 40
        font.pointSize: 20
        background: Rectangle {
            border.color: "black"
            radius: 10
        }
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.horizontalCenterOffset: 60
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: -40
        onClicked: canal.text += "1"
    }
    Button{
        id: canalPrevious
        text: "-C"
        width: 70
        height: 40
        font.pointSize: 20
        background: Rectangle {
            border.color: "black"
            radius: 10
        }
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.horizontalCenterOffset: -60
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: -40
        onClicked: canal.text -= "1"
    }
    Rectangle {
        id: display
        width: 200
        height: 200
        color: "black"
        border.color: "red"
        radius: 10
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: 150
    }
    Text{
        //id: canal
        objectName: "canal"
        text: "Canal:"
        color: "white"
        font.pointSize: 15
        horizontalAlignment: Text.AlignLeft
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.horizontalCenterOffset: -60
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: 70
    }
    Text{
        id: volume
        objectName: "volume"
        text: "Volume:"
        color: "white"
        font.pointSize: 15
        horizontalAlignment: Text.AlignLeft
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.horizontalCenterOffset: -45
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: 100
    }
    Text{
        id: canal
        objectName: "canal"
        color: "white"
        font.pointSize: 15
        horizontalAlignment: Text.AlignLeft
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.horizontalCenterOffset: 0
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: 70
    }
}
