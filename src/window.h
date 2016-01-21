#pragma once

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGraphicsScene>
#include <QTableWidgetItem>
#include <QTableWidget>
#include "viewer.h"
#include "data.h"

class Window : public QWidget{
    Q_OBJECT

public:
    Window(QWidget* parent = nullptr);
    ~Window();
public  slots:
    void setParameters(QGraphicsItem* );
private:
    void createUI();
    void createConnects();
    Data* data;
    Viewer* viewer;
    QHBoxLayout* layout;
    QGraphicsScene* scene;
    QVBoxLayout* buttonsLayout;
    QTableWidget* paramsList;
    QTableWidgetItem* value,* parameter;
    QPushButton* addObject,* deleteObject,* loadData,* saveData;
    std::vector<QTableWidgetItem* > paramsItems;
    std::vector<QTableWidgetItem* > valuesItems;
};
