import QtQuick 2.12
import QtQuick.Controls.Basic
import Qt5Compat.GraphicalEffects


Page {
  width: 1024
  height: 600

  background: Rectangle
  {
    color: "grey"
    anchors.fill: parent
  }

  Column{
    anchors{
      horizontalCenter: parent.horizontalCenter
    }

    spacing: 20

    Button{
      id: btn1
      width: 100
      height: 60
      hoverEnabled: false
      background: Rectangle{
        color: btn1.pressed ? "red" : "green"

        layer.enabled: true
        layer.effect: Glow
        {
           color: "white"
           radius: 8
        }
      }
    }

    Switch {
      id: swt1

      indicator: Rectangle {
        implicitWidth: 48
        implicitHeight: 26
        // x: swt1.leftPadding
        // y: swt1.height / 2 - height / 2
        radius: 13
        color: swt1.checked ? "#17a81a" : "#ffffff"
        border.color: swt1.checked ? "#17a81a" : "#cccccc"

        Rectangle {
          x: swt1.checked ? parent.width - width : 0
          width: 26
          height: 26
          radius: 13
          color: swt1.down ? "#cccccc" : "#ffffff"
          border.color: swt1.checked ? (swt1.down ? "#17a81a" : "#21be2b") : "#999999"
        }
      }
    }


    TextField{
      width: 100
      height: 55
      background: Rectangle{
        anchors.fill: parent
        color: "red"
      }
    }

    Slider {
        id: control
        value: 0.5

        background: Rectangle {
            x: control.leftPadding
            y: control.topPadding + control.availableHeight / 2 - height / 2
            implicitWidth: 200
            implicitHeight: 4
            width: control.availableWidth
            height: implicitHeight
            radius: 2
            color: "#bdbebf"

            Rectangle {
                width: control.visualPosition * parent.width
                height: parent.height
                color: "#21be2b"
                radius: 2
            }
        }

        handle: Rectangle {
            x: control.leftPadding + control.visualPosition * (control.availableWidth - width)
            y: control.topPadding + control.availableHeight / 2 - height / 2
            implicitWidth: 26
            implicitHeight: 26
            radius: 13
            color: control.pressed ? "#f0f0f0" : "#f6f6f6"
            border.color: "#bdbebf"
        }
    }

    Item {
        id: circleProg
        width: 150
        height: 150

        property real value: 1.5   // 65%
        property color progressColor: "#0078d4"
        property color backgroundColor: "#dddddd"
        property int lineWidth: 10

        Canvas {
            id: canvas
            anchors.fill: parent
            onPaint: {
                var ctx = getContext("2d")
                ctx.clearRect(0,0,width,height)

                var centerX = width/2
                var centerY = height/2
                var radius = width/2 - circleProg.lineWidth

                // Background circle
                ctx.beginPath()
                ctx.lineWidth = circleProg.lineWidth
                ctx.strokeStyle = circleProg.backgroundColor
                ctx.arc(centerX, centerY, radius, 0, Math.PI*2)
                ctx.stroke()

                // Progress arc
                ctx.beginPath()
                ctx.strokeStyle = circleProg.progressColor
                ctx.lineWidth = circleProg.lineWidth
                ctx.lineCap = "round"
                ctx.arc(centerX, centerY, radius, -Math.PI/2,
                        (Math.PI * 2 * circleProg.value) - Math.PI/2)
                ctx.stroke()
            }

            Connections {
                target: circleProg
                onValueChanged: canvas.requestPaint()
            }
        }
    }

  }

  ProgressBar {
      id: progressBar1
      value: 0.5
      padding: 2

      background: Rectangle {
          implicitWidth: 200
          implicitHeight: 6
          color: "#e6e6e6"
          radius: 3
      }

      contentItem: Item {
          implicitWidth: 200
          implicitHeight: 60

          // Progress indicator for determinate state.
          Rectangle {
              width: progressBar1.visualPosition * parent.width
              height: parent.height
              radius: 2
              color: "#17a81a"
              visible: !progressBar1.indeterminate
          }
      }
  }






}
