#include "window.h"

Window::Window(QWidget *parent) : QWidget(parent) {
    createUI();
}

void Window::createUI() {
    viewer = new Viewer(this);
    layout = new QHBoxLayout(this);
    buttonsLayout = new QVBoxLayout(this);
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

