#include "data.h"
#include <QFile>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonDocument>
#include <QDebug>

Data::Data(QObject* parent) : QObject(parent) {
        mapName = new QString;
}

void Data::remove(QGraphicsItem *item) {

    for(auto it = objects.begin(); it != objects.end(); ++it) {
        if(it->get() == item) {
            objects.erase(it);
            break;
        }
    }
}


void Data::load(QString fileName) {
    QFile jsonFile(fileName);
    if(jsonFile.open(QIODevice::ReadOnly)) {
        QJsonParseError error;
        QJsonDocument json = QJsonDocument::fromJson(jsonFile.readAll(),&error);
        auto jsonObject = json.object();
        if(error.error == QJsonParseError::NoError) {
            *mapName = jsonObject.value("map-name").toString();
            for(auto object:jsonObject.value("textures").toArray()) {
                std::pair<QString,QPixmap> pair;
                pair.first = object.toObject().value("name").toString();
                pair.second.load(object.toObject().value("filename").toString());
                textures.insert(pair);
            }
            for(auto object:jsonObject.value("objects").toArray()) {
                std::unique_ptr<Object> newObject(new Object);
                newObject->setPos(object.toObject().value("posX").toInt(),object.toObject().value("posY").toInt());
                newObject->setPixmap(textures[object.toObject().value("texture").toString()]);
                newObject->setFlag(QGraphicsItem::ItemIsSelectable);
                newObject->setFlag(QGraphicsItem::ItemIsMovable);
                for(auto parameter:object.toObject().keys()) {
                    if(object.toObject().value(parameter).isDouble()) {
                        newObject->addParameter(parameter,QString::number(object.toObject().value(parameter).toDouble()));
                    }
                    newObject->addParameter(parameter,object.toObject().value(parameter).toString());
                }
                objects.push_back(std::move(newObject));
            }
        } else {
            qDebug() << error.errorString();
        }
    } else {
        qDebug() << "ERROR: FILE NOT OPEN!";
    }
}

Object *Data::getObject(int number) {
    return objects.at(number).get();
}

Object *Data::getObject(QGraphicsItem *item) {
    for(auto it = objects.begin(); it != objects.end(); ++it) {
        if(it->get() == item) {
            return it->get();
        }
    }
    return nullptr;
}


int Data::getAmountObjects() {
    return objects.size();
}

