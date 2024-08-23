import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Controls.Material
// import "mainWindow.h"
// import CppIntegration

Window {
    id: win
    width: 640
    height: 480
    visible: true
    title: qsTr("Library Management System")
    color: "#e8d5b5"


    Text {
        id: title
        text: qsTr("Library Management System")
        // opacity:5.0
        // scale: 1.0
        anchors.centerIn: parent
        anchors.verticalCenterOffset: -(win.height) * 0.43
        font.pixelSize: 24
        font.bold: true           // Make the text bold
        font.italic: true         // Make the text italic
        font.underline: true      // Underline the text
        color: "blue"
    }

    Rectangle{
        id: rect1
        height: parent.height*0.8
        width: parent.width
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        //anchors.centerIn: parent
        anchors.topMargin: 70
        anchors.leftMargin: 20
        anchors.rightMargin: 20
        anchors.bottomMargin: 20
        radius: parent.width*0.05
        border.width:8
        border.color: "#EFAF48"
        color:"#F3CA87"

        GridLayout{
            columns: 2
            rows: 2
            columnSpacing: 30
            rowSpacing: 30
            anchors.top: parent.top
            anchors.left: parent.left
            anchors.topMargin: 70
            anchors.leftMargin: 35


                Label{
                    id: text1
                    text: qsTr("Books List")
                    font.pixelSize: 18
                }
                ComboBox{
                    id:combo1
                    Layout.preferredHeight: 30
                    Layout.preferredWidth: 100
                    model: mainWindow.getBooksList()
                }
                Component.onCompleted: {
                       console.log("ComboBox model:", combo1.model);
                   }
        //     Label{
        //         id: text2
        //         // anchors.top: parent.top
        //         // anchors.left: parent.left
        //         // anchors.topMargin: 150
        //         // anchors.leftMargin: 35
        //         text: qsTr("Books Quantity")
        //         font.pixelSize: 18
        //     }
        //     Label{
        //         id:textinput2
        //         Layout.preferredHeight: 30
        //         Layout.preferredWidth: 100
        //         font.pixelSize: 18
        //         text: mainWindow.getBookCount(mainWindow.getBooksList().first)
        //         // model: mainWindow.getBookCount()
        //     }
        //     Component.onCompleted: {
        //            console.log("book count:",textinput2.text );
        //        }
        }

        Rectangle{
            id: rect2
            anchors.right: parent.right
            width: parent.width/2
            height: parent.height
            // border.color: "black"
            color:"transparent"

            ColumnLayout{
                spacing: 20
                anchors.left: parent.left
                anchors.leftMargin: 70
                // anchors.centerIn: parent
                Rectangle {
                               Layout.preferredHeight: 30  // Adjust this value to control the space before the buttons
                               color: "transparent"  // Make it invisible, only used for spacing
                           }


                Button{

                    // Loader{
                    //     id:loader1
                    //     anchors.fill: parent
                    // }
                    id:button1
                    text: "Update"
                    font.pixelSize: 15
                    Material.foreground: "white"

                    background: Rectangle{
                    color:"#342C2A"
                    radius: 8
                    }
                    Layout.preferredWidth: 180  // Set uniform width
                    Layout.preferredHeight: 50

                    onClicked: {
                        loader1.source = ""
                        loader1.source = "update.qml"
                        loader1.visible=true
                    }
                }
                Button{
                    Loader{

                        id:loader2
                        anchors.fill: parent

                    }
                    id:button2
                    text: "Assign"
                    font.pixelSize: 15
                    Material.foreground: "white"
                    background: Rectangle{
                    color:"#342C2A"
                    radius: 8
                    }
                    Layout.preferredWidth: 180  // Set uniform width
                    Layout.preferredHeight: 50
                    onClicked: {
                        loader2.source = ""
                        loader2.source = "assign.qml"
                    }
                }
                Button{
                    Loader{
                        id:loader3
                        anchors.fill: parent
                    }
                    id:button3
                    text: "Details"
                    font.pixelSize: 15
                    Material.foreground: "white"
                    background: Rectangle{
                    color:"#342C2A"
                    radius: 8
                        }
                    Layout.preferredWidth: 180  // Set uniform width
                    Layout.preferredHeight: 50
                    onClicked: {
                        loader3.source = ""
                        loader3.source = "details.qml"
                    }
                }
                Button{
                    Loader{
                        id:loader4
                        anchors.fill: parent
                    }
                    id:button4
                    text: "View Book list"
                    font.pixelSize: 15
                    Material.foreground: "white"
                    background: Rectangle{
                    color:"#342C2A"
                    radius: 8
                    }
                    Layout.preferredWidth: 180  // Set uniform width
                    Layout.preferredHeight: 50
                    onClicked: {
                        loader4.source = ""
                        loader4.source = "bookList.qml"
                    }
                }


            }
            Loader{
                id:loader1
                anchors.fill: parent
            }
        }
    }
}
