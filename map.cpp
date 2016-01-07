#include "map.h"
#include <fstream>
#include <string>

Map::Map() {
    scene = new QGraphicsScene;
}

Map::~Map() {
    for(int c = 0; c < items.size(); c++) {
        delete items[c];
    }
}

void Map::load() {
    std::ifstream in("Resources/main");
    std::string fileName;
    int amount = 0, x, y;
    in >> amount;
    for(int c = 0; c < amount; c++) {
        in >> fileName >> x >> y;
        QPixmap pixmap(QString::fromStdString(fileName));
        items.push_back(new QGraphicsPixmapItem(pixmap));
        items[items.size()-1]->setPos(QPoint(x,y));
        items[items.size()-1]->setFlag(QGraphicsItem::ItemIsMovable,true);
        items[items.size()-1]->setFlag(QGraphicsItem::ItemIsSelectable);
    }
    for(int c = 0; c < items.size(); c++) {
        scene->addItem(items[c]);
    }
}

QGraphicsScene* Map::getScene() {
    return scene;
}
