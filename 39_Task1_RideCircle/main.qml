/*При нажатии на левый квадрат круг перемещается на небольшое расстояние в сторону правого квадрата (без анимации).
При достижении правого квадрата (его центра или любого края) круг возвращается в исходное положение (внутри левого квадрата)
    с любой анимацией на ваше усмотрение.
При нажатии на правый квадрат круг возвращается в исходное положение (также с анимацией).*/
import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

Window {
    id: main
    width: 640
    height: 480
    visible: true
    title: "Make transition"
    Rectangle{
        id: scene
        anchors.fill: parent
        state: "DefState"
        Rectangle{
            id: leftRect
            x: 100
            y: 200
            color: "lightgrey"
            width: 100
            height: 100
            border.color: "black"
            border.width: 3
            radius: 5
            MouseArea{
                anchors.fill: parent
                onClicked:{
                    ball.x += 30
                    scene.state = "InterState"
                    if(ball.x >= rightRect.x)
                        scene.state = "DefState"
                        //ball.x = leftRect.x + 5
                }
            }
            Text{
                id: move_circle
                anchors.centerIn: parent
                text: "move"
            }
        }
        Rectangle{
            id: rightRect
            x: 300
            y: 200
            color: "lightgrey"
            width: 100
            height: 100
            border.color: "black"
            border.width: 3
            radius: 5
            MouseArea{
                anchors.fill: parent
                onClicked:  scene.state = "DefState"
                            //ball.x = leftRect.x + 5
            }
            Text{
                id: return_circle
                anchors.centerIn: parent
                text: "return"
            }
        }
        Rectangle{
            id: ball
            color: "darkgreen"
            x: leftRect.x + 5
            y:leftRect.y + 5
            width: leftRect.width - 10
            height: leftRect.height - 10
            radius: width/2
            opacity: 0.8
        }
        states: [
            State{
                name: "DefState"
                PropertyChanges{
                    target: ball
                    x: leftRect.x + 5
                }
            },
            State{
                name: "InterState"
                PropertyChanges {
                    target: ball
                    x: ball.x
                }
            }
        ]
        transitions: [
            Transition {
                from: "InterState"
                to: "DefState"
                NumberAnimation{
                    properties: "x, y"
                    duration: 1000
                    easing.type: Easing.InOutExpo
                }
            }
        ]
    }
}
