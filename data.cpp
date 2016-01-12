#include "data.h"
#include <QFile>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonParseError>
#include <QJsonDocument>
#include <QDebug>



Data::Data() {
}

void Data::load(QString fileName) {
    QFile jsonFile(fileName);
    if(jsonFile.open(QIODevice::ReadOnly)) {
        QJsonParseError error;
        QJsonDocument json = QJsonDocument::fromJson(jsonFile.readAll(),&error);
        auto object = json.object();
        if(error.error == QJsonParseError::NoError) {
            mapName = object.value("map-name").toString();

            for(auto value:object["textures"].toArray()) {
                std::unique_ptr<Texture> texture(new Texture(QPixmap(value.toObject().value("filename").toString()),value.toObject().value("name").toString()));
                textures.push_back( std::move(texture) );
            }

            for(auto value:object["objects"].toArray()) {
                std::unique_ptr<Object> object(new Object);
                for(auto key:value.toObject().keys()) {
                    object->addParameter(key,value.toObject().value(key).toString());
                }
                objects.push_back(std::move(object));
            }
            for(auto& value:objects) {
                value->getParameters();
                qDebug() << "\n\n\n";
            }
            qDebug() << objects.size();
        } else {
            qDebug() << error.errorString();
        }
    } else {
        qDebug() << "ERROR: FILE NOT OPEN!";
    }
}

