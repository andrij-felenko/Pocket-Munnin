import QtQuick 2.11
import QtQuick.Controls 2.12

Item {
    id: mainWindow
    anchors.fill: parent
    property double bSize: Math.max(height, width) / 12

    Item {
        id: topItem
        objectName: "topItem"
        height: bSize
        anchors {
            top: parent.top
            left: parent.left
            right: parent.right
        }
    }

    Item {
        id: contentItem
        objectName: "contentItem"
        height: bSize
        anchors {
            top: topItem.bottom
            left: parent.left
            right: parent.right
            bottom: parent.bottom
        }
    }
}
