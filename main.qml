import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12
import qtavplayer 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    AVOutput{
        anchors.fill: parent
        source: avplayer
    }

    AVPlayer{
        id : avplayer
        //source : "D:/BIXIN_testSource/CustomGift.mp4"     //test mp4 单图像
        //source : "D:/BIXIN_testSource/n.mp3"              //test mp3 单声音
        source : "D:/BIXIN_testSource/cat.mp4"              //test mp4 图像 + 声音
        autoPlay: true
    }
}
