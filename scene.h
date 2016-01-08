#pragma once

#include <memory>
#include <vector>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>

class Scene : public QGraphicsScene {
public:
    Scene();
private:
    std::vector< std::unique_ptr<QGraphicsPixmapItem> > items;
};
