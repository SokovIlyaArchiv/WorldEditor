#pragma once

#include <QGraphicsPixmapItem>
#include <map>

class Object : public QGraphicsPixmapItem {
public:
    Object();
    void addParameter(QString parameter, QString value);
    void setValue(QString parameter, QString value);
    QString getValue(QString parameter);
    QString getKey(size_t number);
    size_t getAmountKeys();
private:
    std::map<QString,QString> parameters;
};
