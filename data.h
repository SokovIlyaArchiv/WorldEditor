#pragma once

#include <vector>
#include <map>
#include <QGraphicsItem>
#include <memory>
#include <QDebug>
struct Texture {
    Texture(QPixmap pixmap, QString name) :
        name(name)  {
        item.setPixmap(pixmap);
    }
    QGraphicsPixmapItem item;
    QString name;
};

class Object {
public:
    void addParameter(QString parameter,QString value) {
        parameters.insert(std::pair<QString,QString>(parameter,value));
    }
    std::map<QString,QString> getParameters() {
        for(auto value:parameters) {
            qDebug() << value.first << value.second;
        }
    }

private:
    std::map<QString,QString> parameters;
};

class Data {
public:
    Data();
    void load(QString fileName);
    void save(QString fileName);
    QGraphicsItem* getItem(int number);
private:
    QString mapName;
    std::vector< std::unique_ptr<Object> > objects;
    std::vector< std::unique_ptr<Texture> > textures;
};
