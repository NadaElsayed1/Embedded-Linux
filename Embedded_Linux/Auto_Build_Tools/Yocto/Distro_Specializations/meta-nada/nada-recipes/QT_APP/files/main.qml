import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls

ApplicationWindow {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Image {
        id: imageId
        //source: "file://home/nada/Downloads/images.jpeg"
        source: "file://images.jpeg"
        height: 100
        width: 80
        fillMode: Image.PreserveAspectFit
        // anchors.centerIn: parent
    }

    Column {
        spacing: 50
        anchors.centerIn: parent
        Text { font.pointSize: 20; text: "Hello From iti"; style: Text.Raised; styleColor: "black"; font.bold: true }

        // Text
        // {
        //     text: 'Hello From iti'
        //     font { pixelSize: 30; italic: false; capitalization: Font.DemiBold }

        // }
        TextField {
            id: nameField
            placeholderText: "Please enter your name"
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Button {
            text: "Login"
            onClicked: {
                if (nameField.text === "Nada") {
                    resultText.text = "Hello Nada"
                    resultText.color = "green"
                } else {
                    resultText.text = "Error: Incorrect name"
                    resultText.color = "red"
                }
            }
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Text {
            id: resultText
            text: ""
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }
}
