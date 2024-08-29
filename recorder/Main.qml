import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts
import QtMultimedia
import Qt.labs.folderlistmodel
import DataManager 1.0

ApplicationWindow {
    id:win
    visible: true
    width: 770
    height: 550
    title: "recorder"
    color: "#494949"

    DataManager{
        id:datamangerId
    }

    property string fileName1: "";

    Image {
        id: centerIcon
        source: "file:///C:/Users/HPGGS03/Downloads/dsfds-removebg-preview.png"
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
        width: 300
        height: 60
        z:1
        fillMode: Image.PreserveAspectFit
    }

    Rectangle {
        id: rect1
        width: win.width * 0.90
        height: win.height * 0.80
        anchors.centerIn: parent
        radius: 20
        color: "transparent"
        border.color: "#3A3A3A"
        border.width: 5



        Rectangle {
            id:innerRect
            width: rect1.width - 40
            height: rect1.height - 40
            anchors.centerIn: parent
            radius: 15
            Rectangle{
                id:buttonRect
                border.color:"white"
                border.width: 3
                height: parent.height * 0.35
                width: parent.width
                color: "transparent"
                radius:8
                Item {
                    id: buttonGroup
                    width: startButton.width * 3
                    height: restartButtonct1.height * 2
                    anchors.top: parent.top
                    anchors.left: parent.left
                    anchors.topMargin: rect1.height * 0.1
                    anchors.leftMargin: rect1.width * 0.1
                    Button {
                        id: startButton
                        text: "Start"
                        hoverEnabled: false
                        width: 80
                        height: 80

                        background: Rectangle {
                            radius: width / 2  // This makes the rectangle circular
                            color: startButton.pressed ? "#003366" : "#004488"  // Darker blue when pressed
                            border.color: "#00AAFF"
                            border.width: 2

                            // Optional: Add a gradient for a more polished look
                            gradient: Gradient {
                                GradientStop { position: 0.0; color: startButton.pressed ? "#002244" : "#003366" }
                                GradientStop { position: 1.0; color: startButton.pressed ? "#003366" : "#0055AA" }
                            }
                        }

                        onClicked:{
                            audioText1.text = "Recording started"
                            stackView.clear()
                            if(videoRadio.checked){
                                camera.active = true
                                stackView.push(cameraRect)
                                mediaRecorder.recorderState === MediaRecorder.StoppedState ? mediaRecorder.record() : console.log("Already recording")
                            }
                            if(audioRadio.checked){

                                stackView.push(audioRect)
                                audiomediaRecorder.recorderState === MediaRecorder.StoppedState ? audiomediaRecorder.record() : console.log("Already recording")
                            }
                        }
                        contentItem: Text {
                            text: startButton.text
                            font.pixelSize: 16
                            color: "white"
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                        }
                    }

                    Button {
                        id: stopButton
                        text: "Stop"
                        hoverEnabled: false
                        width: 80
                        height: 80
                        x:startButton.width + 20
                        y:startButton.y

                        background: Rectangle {
                            radius: width / 2  // This makes the rectangle circular
                            color: stopButton.pressed ?  "#003366" : "#004488"  // Darker when pressed
                            border.color: "#00AAFF"
                            border.width: 2

                            // Optional: Add a gradient for a more polished look
                            gradient: Gradient {
                                GradientStop { position: 0.0; color: startButton.pressed ? "#002244" : "#003366" }
                                GradientStop { position: 1.0; color: startButton.pressed ? "#003366" : "#0055AA" }
                            }
                        }
                        onClicked:{
                            audioText1.text = "Recording Stop"
                            if(videoRadio.checked){
                            camera.active = false
                            mediaRecorder.stop()
                            }
                            else{
                                audiomediaRecorder.stop()
                            }
                        }

                        contentItem: Text {
                            text: stopButton.text
                            font.pixelSize: 16
                            color: "white"
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                        }
                    }
                }
                GridLayout {
                    id: grid
                    columns: 2
                    rows: 1
                    columnSpacing: 20
                    rowSpacing: 20
                    x: buttonGroup.width + 130
                    y: buttonGroup.y

                    ColumnLayout {
                        id: colRadio
                        spacing: 20

                        RadioButton {
                            id: audioRadio
                            text: "Audio"
                            font.pixelSize: 18
                            checked: true

                            indicator: Rectangle {  // Customizing the indicator (the radio button itself)
                                width: 18
                                height: 18
                                radius: width / 2
                                color: audioRadio.checked ? "#0077FF" : "lightgray"
                                border.color: "white"
                                border.width: 2
                            }

                            contentItem: Text {
                                text: audioRadio.text
                                font.pixelSize: audioRadio.font.pixelSize
                                color: "white"
                                verticalAlignment: Text.AlignVCenter  // Align text vertically in the center
                                leftPadding: 25  // Add some space between the indicator and the text
                                topPadding: -10
                            }
                        }

                        RadioButton {
                            id: videoRadio
                            text: "Video"
                            font.pixelSize: 18  // Ensure the font size is set here

                            indicator: Rectangle {
                                width: 18
                                height: 18
                                radius: width / 2
                                color: videoRadio.checked ? "#0077FF" : "lightgray"
                                border.color: "white"
                                border.width: 2
                            }

                            contentItem: Text {
                                text: videoRadio.text
                                font.pixelSize: videoRadio.font.pixelSize  // Ensure the font size is applied to the text
                                color: "white"
                                verticalAlignment: Text.AlignVCenter  // Align text vertically in the center
                                leftPadding: 25  // Add some space between the indicator and the text
                                topPadding: -10
                            }
                        }
                    }
                }
            }
            Rectangle{
                id:displayRect
                anchors.top: buttonRect.bottom
                anchors.left: buttonRect.left
                border.color: "white"
                border.width: 2
                radius:8
                color: "transparent"
                height: innerRect.height - buttonRect.height
                width: buttonRect.width * 0.6
                z:1

                StackView {
                   id: stackView
                   anchors.fill: parent
                   initialItem:videoPlayerItem
                   anchors.centerIn: parent
                   anchors.margins: 2
                }
                Rectangle{
                    id:audioPlayerItem
                    radius:8
                    color: "lightgray"
                    Text {
                        id: audioPlayerText
                        anchors.centerIn: parent
                    }
                    MediaPlayer{
                        id:audiomediaPlayer
                        audioOutput: audioOutput
                        onPlaybackStateChanged: {
                            if(playbackState === audiomediaPlayer.StoppedState){
                                console.log("audio stopped,resetting player>")
                            }
                        }
                    }
                    AudioOutput{
                        id:audioOutput
                    }
                }

                Rectangle {
                    id: videoPlayerItem
                    radius: 8
                    Text {
                        id: videoPlayerText
                        anchors.centerIn: parent
                    }
                    MediaPlayer {
                        id: mediaPlayer
                        videoOutput: videoOutput  // Bind the MediaPlayer to the VideoOutput
                        onPlaybackStateChanged: {
                            if (playbackState === MediaPlayer.StoppedState) {
                                console.log("Media stopped, resetting player.")
                            }
                        }
                    }
                    VideoOutput {
                        id: videoOutput
                        anchors.fill: parent
                        fillMode: VideoOutput.Stretch
                    }
                    AudioOutput{
                        id:audioOutput1
                    }
                }
                Rectangle{
                    id:abc
                    color: "blue"
                    border.color: "white"
                    border.width: 2
                    radius:8
                }
                Rectangle{
                    id:audioRect
                    Text{
                        id:audioText1
                        anchors.centerIn: parent
                    }
                    CaptureSession {
                        id: audioCaptureSession
                        audioInput: AudioInput {
                            id: audioInput
                        }
                        recorder: MediaRecorder {
                            id: audiomediaRecorder
                            outputLocation: "file:///C:/QML Projects/recorder/recordedFiles"
                        }
                    }
                    AudioOutput{
                        id:recordedAudioOutput
                    }
                }
                Rectangle{
                    id:cameraRect
                    CaptureSession{
                        id: captureSession
                        camera:Camera {
                            id: camera
                            onActiveChanged: {
                                if (active) {
                                   console.log("Camera is now active.")
                                } else {
                                   console.log("Camera has been deactivated.")
                                }
                            }
                        }
                        videoOutput: camVideoOutput

                        recorder:MediaRecorder {
                            id: mediaRecorder
                            outputLocation: "file:///C:/QML Projects/recorder/recordedFiles"
                            // onRecorderStateChanged: {
                            //     console.log("Recorder state changed to", recorderState)
                            // }
                        }
                        audioInput: AudioInput {
                        }
                    }
                    VideoOutput {
                        id: camVideoOutput
                        anchors.fill: parent
                        fillMode: VideoOutput.Stretch
                    }
                }
            }
            Rectangle {
                id: listRect
                anchors.top: buttonRect.bottom
                anchors.left: buttonRect.left
                anchors.leftMargin: buttonRect.width * 0.6
                height: innerRect.height - buttonRect.height
                width: buttonRect.width * 0.4
                color:"transparent"
                border.color: "white"
                border.width: 2
                radius:8

                ScrollView {
                    id:scrollID
                    anchors.fill: parent
                    // width: fileListView.width
                    // height: parent.height

                    ListView {
                        id: fileListView
                        width: parent.width
                        // height: parent.height
                        clip: true  // Ensure that content is clipped to the ListView's bounds

                        model:FolderListModel{
                            id:modelView
                            folder:"file:///C:/QML Projects/recorder/recordedFiles/"
                            nameFilters: ["*.mp3","*.mp4","*.m4a","*.avi","*.wav"]
                        }
                        delegate: Item {
                        width: fileListView.width
                        height: 40

                        RowLayout {
                            // columns: 3
                            anchors.fill: parent
                            anchors.margins: 8
                            // columnSpacing: 15

                            Text {
                                id:fileText
                                text: model.fileName
                                font.pixelSize: 18
                                color: "white"
                                Layout.alignment: Qt.AlignLeft
                            }

                            Button {
                                text: "Play"
                                onClicked: {
                                    console.log("Playing: " + model.fileName)
                                    fileName1 = model.fileName

                                    // Stop both media players first
                                    if (mediaPlayer.playbackState !== MediaPlayer.StoppedState) {
                                        mediaPlayer.stop()
                                    }
                                    if (audiomediaPlayer.playbackState !== MediaPlayer.StoppedState) {
                                        audiomediaPlayer.stop()
                                    }

                                    // Determine whether the file is video or audio based on the extension
                                    if (model.fileName.endsWith(".mp4") || model.fileName.endsWith(".avi") || model.fileName.endsWith(".mkv")) {
                                        // Play video

                                        mediaPlayer.source = modelView.folder + model.fileName
                                        stackView.clear()
                                        stackView.push(videoPlayerItem)
                                        videoPlayerText.text = fileName1 + " Playing"
                                        Qt.callLater(() => mediaPlayer.play())
                                    } else if (model.fileName.endsWith(".wav") || model.fileName.endsWith(".mp3") || model.fileName.endsWith(".m4a")) {
                                        // Play audio
                                        audioPlayerText.text = fileName1 + " Playing"
                                        audiomediaPlayer.source = "file:///C:/QML Projects/recorder/recordedFiles/" + model.fileName
                                        stackView.clear()
                                        stackView.push(audioPlayerItem)

                                        Qt.callLater(() => audiomediaPlayer.play())
                                    } else {
                                        console.log("Unsupported file type: " + model.fileName)
                                    }
                                }
                                width: 80
                                height: 30
                                Layout.alignment: Qt.AlignRight
                            }

                            Button {
                                id: deleteButton
                                text: "Delete"
                                hoverEnabled: false
                                background: Rectangle{
                                    color: "#CC0000"
                                    radius:8
                                }

                                onClicked: {
                                    datamangerId.deleteFile(model.filePath)
                                    console.log("Deleted: " + model.fileName)
                                }
                                width: 80
                                height: 30
                                Layout.alignment: Qt.AlignRight
                                }
                            }
                        }
                        // ScrollBar.vertical: ScrollBar {
                        //     policy: ScrollBar.AlwaysOn

                        // }
                    }
                }
            }

            gradient: Gradient {
                GradientStop { position: 0.0; color: "#080E1C" }
                GradientStop { position: 1.0; color: "#2A2D37" }
            }
        }
    }
}
