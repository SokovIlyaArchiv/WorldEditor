#pragma once
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGraphicsScene>
#include "viewer.h"
#include "data.h"

class Window : public QWidget{
public:
    Window(QWidget* parent = nullptr);

private:
    Data data;
    void createUI();
    Viewer* viewer;
    QHBoxLayout* layout;
    QVBoxLayout* buttonsLayout;
    QGraphicsScene* scene;
    QPushButton* addObject,* deleteObject,* loadData,* saveData;
};
