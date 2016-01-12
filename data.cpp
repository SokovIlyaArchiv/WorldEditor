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
            qDebug() << object.value("level-name").toString();
            qDebug() << object.value("amount-objects").toInt();
            for(auto value:object["objects"].toArray()) {
                qDebug() << value.toObject()["filename"].toString();
            }
        } else {
            qDebug() << error.errorString();
        }
    } else {
        qDebug() << "ERROR: FILE NOT OPEN!";
    }
}

