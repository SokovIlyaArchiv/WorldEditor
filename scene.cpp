#include "scene.h"
#include <fstream>
#include <string>
#include <QDebug>

Scene::Scene() {
    int amount,x,y;
    std::string fileName;
    std::ifstream in("main");
    if(in.is_open()) {
        in >> amount;
        for(int c = 0;c < amount; c++) {
            in >> fileName >> x >> y;
            items.push_back(std::shared_ptr<QGraphicsPixmapItem>(new QGraphicsPixmapItem( QPixmap( QString::fromStdString( fileName ) ) ) ));
            items[items.size()-1]->setPos(QPoint(x,y));
            addItem(items[items.size()-1].get());
        }
    }
}
