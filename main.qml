import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls

Window {
    width: 1024
    height: 600
    visible: true
    title: qsTr("Hello World")


    SwipeView
    {
        anchors.fill: parent

        PageOne{}
        PageTwo{}
    }

}
