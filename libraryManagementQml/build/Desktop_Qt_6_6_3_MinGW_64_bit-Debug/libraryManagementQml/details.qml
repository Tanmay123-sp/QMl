import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 2.15
import QtQuick.Controls.Material
import Qt.labs.qmlModels 1.0


Window {
    id:detailsWin
    width: 740
    height: 580
    visible: true
    title: qsTr("Details")
    color: "#e8d5b5"

    Text {
        id: title
        text: qsTr("User and Books Details")
        anchors.centerIn: parent
        anchors.verticalCenterOffset: -(detailsWin.height) * 0.43
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

//         TableView {
//                id: tableView
//                anchors.fill: parent
//                columnSpacing: 1
//                rowSpacing: 1
//                clip: true

//                TableViewColumn {
//                    title: "Sr No"
//                    width: 50
//                    delegate: Text {
//                        text: (index + 1)
//                        anchors.centerIn: parent
//                    }
//                }

//                TableViewColumn {
//                    title: "Name"
//                    width: 100
//                    delegate: Text {
//                        text: model.name
//                        anchors.centerIn: parent
//                    }
//                }

//                TableViewColumn {
//                    title: "Age"
//                    width: 50
//                    delegate: Text {
//                        text: model.age
//                        anchors.centerIn: parent
//                    }
//                }

//                TableViewColumn {
//                    title: "Address"
//                    width: 150
//                    delegate: Text {
//                        text: model.address
//                        anchors.centerIn: parent
//                    }
//                }

//                TableViewColumn {
//                    title: "Phone"
//                    width: 100
//                    delegate: Text {
//                        text: model.phone
//                        anchors.centerIn: parent
//                    }
//                }

//                TableViewColumn {
//                    title: "Email"
//                    width: 150
//                    delegate: Text {
//                        text: model.email
//                        anchors.centerIn: parent
//                    }
//                }

//                model: TableModel {
//                    TableModelColumn { display: "name" }
//                    TableModelColumn { display: "age" }
//                    TableModelColumn { display: "address" }
//                    TableModelColumn { display: "phone" }
//                    TableModelColumn { display: "email" }

//                    rows: [
//                        { "name": "Name1", "age": "25", "address": "Address1", "phone": "1234567890", "email": "email1@example.com" },
//                        { "name": "Name2", "age": "30", "address": "Address2", "phone": "0987654321", "email": "email2@example.com" },
//                        { "name": "Name3", "age": "22", "address": "Address3", "phone": "1122334455", "email": "email3@example.com" }
//                    ]
//                }
//            }

    }
}
