import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Controls.Material

Window {
    id:assignWin
    width: 640
    height: 480
    visible: true
    title: qsTr("Assign")
    color: "#e8d5b5"

    Text {
        id: title
        text: qsTr("Assign the Books")
        // opacity:5.0
        // scale: 1.0
        anchors.centerIn: parent
        anchors.verticalCenterOffset: -(assignWin.height) * 0.43
        font.pixelSize: 24
        font.bold: true           // Make the text bold
        font.italic: true         // Make the text italic
        font.underline: true      // Underline the text
        color: "blue"
    }

    Rectangle{
        id: rect7
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

            ColumnLayout{
                id:columnLayout1
                spacing:20
                anchors.top: parent.top
                anchors.left: parent.left
                anchors.topMargin: 60
                anchors.leftMargin: 35


            RowLayout{
                id:rowLayout1
                spacing: 20

                Label{
                    id:bookCategoryLabel
                    text:"Book Category"
                    font.pixelSize: 18
                }

                RadioButton{
                    id:techRadioAssign
                    text: "Technical"
                    font.pixelSize: 15
                }
                RadioButton{
                    id:nonTechRadioAssign
                    text: "non-Technical"
                    font.pixelSize: 15
                }
                RadioButton{
                    id:allRadioAssign
                    text: "All Books"
                    font.pixelSize: 15
                }
            }
            GridLayout{
                columns: 2
                rows: 6
                columnSpacing: 30
                rowSpacing: 30
                // anchors.top: parent.top
                // anchors.left: parent.left
                // anchors.topMargin: 70
                // anchors.leftMargin: 35
            Label{
                    id: label1
                    text: "Book"
                    font.pixelSize: 18
                }

            ComboBox{
                 id:bookCombo
                 Layout.preferredHeight: 30
                 Layout.preferredWidth: 150

            }

            Label{
                id: label2
                text: qsTr("User")
                font.pixelSize: 18

            }
            ComboBox{
                 id:userCombo
                 Layout.preferredHeight: 30
                 Layout.preferredWidth: 150

            }
            Label{
                id: quantityLabel
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
            Rectangle{
                id:rect8
                color: "transparent"
            }

            Button{
                id:assignButton
                text: "Assign"
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
            }
        }
    }
}
