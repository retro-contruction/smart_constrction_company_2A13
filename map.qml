import QtQuick 2.0
import QtLocation 5.9
import QtPositioning 5.6
Rectangle {
Plugin {
    id : mapPlugin
    name: "osm"
}
Map {
    id : mapView
    anchors.fill: parent
    plugin: Plugin {name: "osm"}
    center: QtPositioning.coordinate(25.6585, 125.3658);
    zoomLevel: 15
}
}
