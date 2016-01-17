#include "object.h"

Object::Object() : QGraphicsPixmapItem(nullptr){
}

void Object::addParameter(QString parameter, QString value) {
    std::pair<QString,QString> pair(parameter,value);
    parameters.insert(pair);
}

QString Object::getValue(QString parameter) {
    return parameters.at(parameter);
}

QString Object::getKey(size_t number) {
    size_t counter {0};
    for(auto value:parameters) {
        if(counter == number) {
            return value.first;
        }
        counter++;
    }
    return "";
}

size_t Object::getAmountKeys() {
    return parameters.size();
}
