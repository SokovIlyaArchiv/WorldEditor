#pragma once

#include <QGraphicsItem>
#include <memory>
#include <vector>
#include <map>
#include "object.h"
class Data {
public:
    Data();
    Object* getObject(int number);
    void load(QString fileName);
    void save(QString fileName);
    int getAmountObjects();
private:
    QString* mapName;
    std::vector< std::unique_ptr<Object> > objects;
    std::map< QString, QPixmap > textures;
};
