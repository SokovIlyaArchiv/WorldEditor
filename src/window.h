#pragma once

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGraphicsScene>
#include "viewer.h"
#include "data.h"

class Window : public QWidget{
    Q_OBJECT

public:
    Window(QWidget* parent = nullptr);
private:
    void createUI();
    void createConnects();
    Data* data;
    Viewer* viewer;
    QHBoxLayout* layout;
    QGraphicsScene* scene;
    QVBoxLayout* buttonsLayout;
    QPushButton* addObject,* deleteObject,* loadData,* saveData;
};
