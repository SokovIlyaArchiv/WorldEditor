#include "window.h"
Window::Window(QWidget *parent) : QWidget(parent) {
    createUI();
    createConnects();
    data->load("../data/data.txt");
    for(int c = 0; c < data->getAmountObjects(); c++) {
        scene->addItem(data->getObject(c));
    }
    viewer->setScene(scene);
}

void Window::createUI() {
    data = new Data;
    viewer = new Viewer(this);
    layout = new QHBoxLayout(this);
    buttonsLayout = new QVBoxLayout(this);
    scene = new QGraphicsScene(this);
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
    setLayout(layout);
}

void Window::createConnects() {
    QObject::connect(deleteObject,&QPushButton::clicked,viewer,&Viewer::removeItem);
    QObject::connect(viewer,&Viewer::removeSelectableItem,data,&Data::remove);
}

