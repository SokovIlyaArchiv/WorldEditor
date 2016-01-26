#include "window.h"
#include <QDebug>
#include <QHeaderView>
Window::Window(QWidget *parent) : QWidget(parent) {
    createUI();
    createConnects();
    data->load("../data/data.txt");
    for(int c = 0; c < data->getAmountObjects(); c++) {
        scene->addItem(data->getObject(c));
    }
    viewer->setScene(scene);
    scene->setSceneRect(0,0,1000,1000);
}

Window::~Window() {
    while(paramsItems.size()!=0) {
        delete paramsItems.at(0);
        delete valuesItems.at(0);
    }
    delete parameter;
    delete value;
}

void Window::setParameters(QGraphicsItem *item) {
    if(item != nullptr) {
        auto object = data->getObject(item);
        while(paramsList->rowCount() != 0) {
            paramsList->removeRow(0);
        }
        paramsList->setRowCount(object->getAmountKeys());
        while(paramsItems.size() < object->getAmountKeys()) {
            paramsItems.push_back(new QTableWidgetItem);
            valuesItems.push_back(new QTableWidgetItem);
        }
        for(size_t c = 0; c < paramsList->rowCount(); c++) {
            if(!paramsList->item(c,0)) {
                paramsList->setItem(c,0,paramsItems.at(c));
            }
            if(!paramsList->item(c,1)) {
                paramsList->setItem(c,1,valuesItems.at(c));
            }
            paramsList->item(c,0)->setText(object->getKey(c));
            paramsList->item(c,1)->setText(object->getValue(object->getKey(c)));
        }
    } else {
        paramsList->setRowCount(0);
    }
}

void Window::createUI() {
    data = new Data(this);
    viewer = new Viewer(this);
    layout = new QHBoxLayout(this);
    buttonsLayout = new QVBoxLayout(this);
    scene = new QGraphicsScene(this);
    paramsList = new QTableWidget(this);
    addObject = new QPushButton("Добавить объект",this);
    deleteObject = new QPushButton("Удалить объект",this);
    loadData = new QPushButton("Загрузить уровень",this);
    saveData = new QPushButton("Сохранить уровень",this);
    layout->addLayout(buttonsLayout);
    buttonsLayout->addWidget(addObject);
    buttonsLayout->addWidget(deleteObject);
    buttonsLayout->addWidget(loadData);
    buttonsLayout->addWidget(saveData);
    layout->addWidget(viewer);
    layout->addWidget(paramsList);
    setLayout(layout);
    paramsList->setColumnCount(2);
    value = new QTableWidgetItem("Value");
    parameter = new QTableWidgetItem("Parameter");
    paramsList->setHorizontalHeaderItem(0,parameter);
    paramsList->setHorizontalHeaderItem(1,value);
    paramsList->horizontalHeader()->setSectionResizeMode (0,QHeaderView::Stretch);
    paramsList->horizontalHeader()->setSectionResizeMode (1,QHeaderView::Stretch);
    connect(paramsList,&QTableWidget::itemChanged,[](QTableWidgetItem* item) {
                                                    //qDebug() << item->text();
                                                  });
}

void Window::createConnects() {
    connect(deleteObject,&QPushButton::clicked,viewer,&Viewer::removeItem);
    connect(viewer,&Viewer::getRemoveItem,data,&Data::remove);
    connect(viewer,&Viewer::clicked,this,&Window::setParameters);
}

