import QtQuick 2.12
import QtQuick.Controls

Page {
    width: 1024
    height: 600

    background: Rectangle
    {
        color: "red"
        anchors.fill: parent
    }

    Column {
        anchors.centerIn: parent
        spacing: 10

        ListView {
            width: parent.width
            height: 200
            model: Person_Q

            delegate: Rectangle {
                height: 40
                width: parent.width
                color: "lightgray"
                border.width: 1

                Text {
                    anchors.centerIn: parent
                    text: name
                }
            }
        }

        Row {
            spacing: 5

            Button {
                text: "Add"
                onClicked: Person_Q.addPerson("New Person")
            }
            Button {
                text: "Remove"
                onClicked: Person_Q.removePerson(0)
            }
            Button {
                text: "Update"
                onClicked: Person_Q.updatePerson(0, "Updated Name")
            }
        }
    }
}
