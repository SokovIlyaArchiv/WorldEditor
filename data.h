#pragma once

#include <QGraphicsItem>
//#include <QList>

class Data {
public:
    Data();
    void load(QString fileName);
    void save(QString fileName);
    QGraphicsItem* getItem(int number);
private:
    QList<QGraphicsItem*> items;
};
