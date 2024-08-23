import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Controls.Material

Window {
    id:updateWin
    width: 640
    height: 480
    visible: true
    title: qsTr("Update")
    color: "#e8d5b5"

    Text {
        id: title
        text: qsTr("Update the Books")
        // opacity:5.0
        // scale: 1.0
        anchors.centerIn: parent
        anchors.verticalCenterOffset: -(updateWin.height) * 0.43
        font.pixelSize: 24
        font.bold: true           // Make the text bold
        font.italic: true         // Make the text italic
        font.underline: true      // Underline the text
        color: "blue"
    }

    Rectangle{
        id: rect6
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
            rows: 6
            columnSpacing: 30
            rowSpacing: 30
            anchors.top: parent.top
            anchors.left: parent.left
            anchors.topMargin: 70
            anchors.leftMargin: 35

            Label{
                    id: label1
                    text: "Books Name"
                    font.pixelSize: 18
                }

            TextField{
                id:inputName
                 placeholderText: "Enter Book Name"
                 Layout.preferredHeight: 30
                 Layout.preferredWidth: 150
                 background: Rectangle{
                    radius: 8
                 }
            }

            Label{
                id: label2
                text: qsTr("Quantity")
                font.pixelSize: 18

            }
            TextField{
                id:inputQuantity
                placeholderText:"Enter Quantity"
                Layout.preferredHeight: 30
                Layout.preferredWidth: 150
                background: Rectangle{
                    radius: 8
                }
            }
            RadioButton{
                id:techRadio
                text: "Technical"
                font.pixelSize: 15
            }
            RadioButton{
                id:nonTechRadio
                text: "non-Technical"
                font.pixelSize: 15
            }

        // ColumnLayout{
        //     id:col1
        //     spacing: 20
        //     anchors.top: parent.top
        //     anchors.left: parent.left
        //     anchors.topMargin: 170
        //     anchors.leftMargin: 25

            Button{
                id:insertButton
                text: "Insert"
                font.pixelSize: 18
                Material.foreground: "white"
                background: Rectangle{
                    color:"#342C2A"
                    radius: 8
                    // width: 135
                }
                Layout.preferredWidth: 130  // Set uniform width
                Layout.preferredHeight: 50
                onClicked: {
                            var bookName = pareseString(inputName.text);
                            var quantity = parseInt(inputQuantity.text);
                            // if (bookComboBox.currentIndex !== -1) {
                            mainWindow.updateBooks(inputQuantity.currentText, quantity);
                             // }
                    }
            }
            Button{
                id:deleteButton
                text: "Delete"
                font.pixelSize: 18
                Material.foreground: "white"
                background: Rectangle{
                    color:"#342C2A"
                    radius: 8
                    // width: 135
                }
                Layout.preferredWidth: 130  // Set uniform width
                Layout.preferredHeight: 50

            }
            // }
        }
    }
}





