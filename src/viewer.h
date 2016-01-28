#pragma once
#include <QGraphicsView>
#include <QMouseEvent>



class Viewer: public QGraphicsView {

    Q_OBJECT

public:
    Viewer(QWidget* parent = nullptr);
    QGraphicsItem* getSelectedItem();

public slots:
    void removeItem(bool);

signals:
    void clicked(QGraphicsItem*);
    void getRemoveItem(QGraphicsItem*);

protected:
    virtual void mousePressEvent(QMouseEvent* event) override;
    virtual void mouseMoveEvent(QMouseEvent* event) override;
    virtual void wheelEvent(QWheelEvent* event) override;
};
