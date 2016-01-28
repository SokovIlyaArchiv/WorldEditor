#include "window.h"
#include "data.h"
#include "viewer.h"
#include <QGraphicsScene>
#include <QBoxLayout>
#include <QPushButton>
#include <QHeaderView>
#include <QDebug>


Window::Window(QWidget* parent):
    QWidget {parent} {

    createUI();
    data->load("../data/data.txt");
    for(int c = 0; c < data->getAmountObjects(); c++) {
        scene->addItem(data->getObject(c));
    }
    viewer->setScene(scene);
    scene->setSceneRect(0,0,1000,1000);
    createButtons();
    createConnects();
    createParametersTable();
}



Window::~Window() {
    while(paramsList->rowCount() != 0) {
        delete paramsList->item(0,0);
        delete paramsList->item(0,1);
    }
    delete parameter;
    delete value;
}



void Window::setParameters(QGraphicsItem *item) {
    auto object = data->getObject(item);
    if(object != nullptr) {
        while(paramsList->rowCount() != 0) {
            delete paramsList->item(0,0);
            delete paramsList->item(0,1);
            paramsList->removeRow(0);
        }
        paramsList->setRowCount(object->getAmountKeys());
        for(int c = 0; c < object->getAmountKeys(); c++) {
            paramsList->setItem(c,0,new QTableWidgetItem);
            paramsList->setItem(c,1,new QTableWidgetItem);
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
    scene = new QGraphicsScene(this);
    paramsList = new QTableWidget(this);
    layout->addWidget(viewer);
    layout->addWidget(paramsList);
    setLayout(layout);
}



void Window::createButtons() {
    std::map<ButtonID, std::string> buttonsTexts {
        {ButtonID::AddObject, "Добавить объект"},
        {ButtonID::DeleteObject, "Удалить объект"},
        {ButtonID::LoadData, "Загрузить уровень"},
        {ButtonID::SaveData, "Сохранить уровень"}
    };
    buttonsLayout = new QVBoxLayout(this);
    buttons.resize(buttonsTexts.size());
    for(size_t c = 0; c < buttons.size(); c++) {
        buttons[c] = new QPushButton(buttonsTexts[static_cast<ButtonID>(c)].c_str(),
                                     this);
        buttonsLayout->addWidget(buttons[c]);
    }
    layout->addLayout(buttonsLayout);
}



void Window::createParametersTable() {
    paramsList->setColumnCount(2);
    value = new QTableWidgetItem("Value");
    parameter = new QTableWidgetItem("Parameter");
    paramsList->setHorizontalHeaderItem(0,parameter);
    paramsList->setHorizontalHeaderItem(1,value);
    paramsList->horizontalHeader()->setSectionResizeMode (0,QHeaderView::Stretch);
    paramsList->horizontalHeader()->setSectionResizeMode (1,QHeaderView::Stretch);
}



void Window::createConnects() {
    connect(buttons.at(static_cast<int>(ButtonID::DeleteObject)), &QPushButton::clicked,
            viewer, &Viewer::removeItem);
    connect(buttons.at(static_cast<int>(ButtonID::DeleteObject)), &QPushButton::clicked,
            [&](){paramsList->setRowCount(0);});
    connect(viewer, &Viewer::getRemoveItem,
            data, &Data::remove);
    connect(viewer, &Viewer::clicked,
            this, &Window::setParameters);
}

