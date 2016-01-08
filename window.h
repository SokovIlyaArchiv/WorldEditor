#pragma once
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "viewer.h"

class Window : public QWidget{
public:
    Window(QWidget* parent = nullptr);
private:
    Viewer* viewer;
    QVBoxLayout* buttonsLayout;
    QHBoxLayout* layout;
    QPushButton* addObject,* deleteObject,* loadData,* saveData;
};
