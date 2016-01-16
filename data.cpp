#include "data.h"
#include <QFile>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonDocument>
#include <QDebug>

Data::Data() {
    mapName = new QString();
}

void Data::load(QString fileName) {
    QFile jsonFile(fileName);
    if(jsonFile.open(QIODevice::ReadOnly)) {
        QJsonParseError error;
        QJsonDocument json = QJsonDocument::fromJson(jsonFile.readAll(),&error);
        auto jsonObject = json.object();
        if(error.error == QJsonParseError::NoError) {
            qDebug() << "START READER DATA!";
            *mapName = jsonObject.value("map-name").toString();
            qDebug() << "LOADED TEXTURES";
            for(auto object:jsonObject.value("textures").toArray()) {
                std::pair<QString,QPixmap> pair;
                pair.first = object.toObject().value("name").toString();
                pair.second.load(object.toObject().value("filename").toString());
                textures.insert(pair);
            }
            qDebug() << "LOAD OBJECTS";
            for(auto object:jsonObject.value("objects").toArray()) {
                std::unique_ptr<Object> newObject(new Object);
                newObject->setPixmap(textures[object.toObject().value("texture").toString()]);
                for(auto parameter:object.toObject().keys()) {
                    newObject->addParameter(parameter,object.toObject().value(parameter).toString());
                }
                objects.push_back(std::move(newObject));
            }
            qDebug() << "DATA READED";
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

int Data::getAmountObjects() {
    return objects.size();
}

