#pragma once
#include <memory>
#include <QTableWidgetItem>
class QGraphicsScene;
class QGraphicsItem;
class QHBoxLayout;
class QVBoxLayout;
class QTableWidget;
class QPushButton;
class Data;
class Viewer;



class Window: public QWidget {

    Q_OBJECT

public:
    explicit Window(QWidget* parent = nullptr);
    ~Window();

public slots:
    void setParameters(QGraphicsItem*);

private:
    void createConnects();
    void createUI();
    void createButtons();
    void createParametersTable();

    QGraphicsScene* scene;

    Data* data;
    Viewer* viewer;

    QHBoxLayout* layout;
    QVBoxLayout* buttonsLayout;
    QTableWidget* paramsList;
    QTableWidgetItem* value,
                    * parameter;
    enum class ButtonID {AddObject, DeleteObject, LoadData, SaveData};
    std::vector<QPushButton*> buttons;
};
