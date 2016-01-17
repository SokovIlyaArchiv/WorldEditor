#pragma once

#include <QGraphicsItem>
#include <QObject>
#include <memory>
#include <vector>
#include <map>
#include "object.h"
class Data : public QObject {
    Q_OBJECT
public:
    Data(QObject* parent = nullptr);
    Object* getObject(int number);
    void load(QString fileName);
    void save(QString fileName);
    int getAmountObjects();
public slots:
    void remove(QGraphicsItem* item);
private:
    QString* mapName;
    std::vector< std::unique_ptr<Object> > objects;
    std::map< QString, QPixmap > textures;
};
