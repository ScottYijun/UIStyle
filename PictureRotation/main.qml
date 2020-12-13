import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5

Window {
    visible: true
    width: 600
    height: 480
    color: "green"
    title: qsTr("Hello World")

    Image {
        id: loginImage
        width: 80; height: 80;
        source: "qrc:/res/bb.png";
        visible: true
    }

    Image {
        id: loginSucessImage
        width: 80; height: 80;
        source: "qrc:/res/aa.png";
        visible: false
        Text{
            id: timeText
            text: "00:12:34"
            color: "red"
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 10
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }

    NumberAnimation{
        id: numberAnimation
        target: loginImage
        duration: 1000;
        loops: Animation.Infinite
        from: 0
        to: 360
        property: "rotation"
    }

    Rectangle {
        id: startRect
        width: 50; height: 50;
        color: "red"
        anchors.top: parent.top;
        anchors.topMargin: 1;
        anchors.left: parent.left;
        anchors.leftMargin: 100
        MouseArea{
            anchors.fill: parent;
            onClicked: {
                loginImage.visible = true;
                loginSucessImage.visible = false;
                numberAnimation.start();
            }
        }
    }

    Rectangle {
        id: stopRect
        width: 50; height: 50;
        color: "blue"
        anchors.top: parent.top;
        anchors.topMargin: 1;
        anchors.left: parent.left;
        anchors.leftMargin: 150
        MouseArea{
            anchors.fill: parent;
            onClicked: {
                numberAnimation.stop();
                loginImage.visible = false;
                loginSucessImage.visible = true;
            }
        }
    }
    //显示弹框
    Rectangle {
        id: showPopupRect
        width: 50; height: 50;
        color: "blue"
        anchors.top: parent.top;
        anchors.topMargin: 100;
        anchors.left: parent.left;
        anchors.leftMargin: 150
        MouseArea{
            anchors.fill: parent;
            onClicked: {
                userInfo.show()
                //myPopup.open()
            }
        }
    }

    //自定义的弹框，带三角尖
    UserInfoPopup {
        id: userInfo
        backgroundWidth: 200
        backgroundHeight: 180
        anchors.left: parent.left;
        anchors.leftMargin: 200
        anchors.top: parent.top;
        anchors.topMargin: 50;
        barColor: "red"
    }

//    Popup {
//        id: myPopup
//        x: 150
//        y: 100
//        width: 200;
//        height: 200
//        modal: true
//        focus: true
//        //closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutsideParent
//    }
    //https://www.cnblogs.com/surfsky/p/3998391.html
    //https://jaredtao.github.io/2019/05/12/Qml%E7%BB%84%E4%BB%B6%E5%8C%96%E7%BC%96%E7%A8%8B3-%E5%8A%A8%E6%80%81%E5%88%87%E6%8D%A2%E7%9A%AE%E8%82%A4/
}
