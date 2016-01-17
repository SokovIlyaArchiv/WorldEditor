#pragma once

#include <QGraphicsView>
#include <QMouseEvent>
class Viewer : public QGraphicsView {
    Q_OBJECT

public:
    Viewer(QWidget *parent = 0);
signals:
    void itemSelected(QGraphicsItem* item);
protected:
    virtual void mousePressEvent(QMouseEvent *event) override;
    virtual void mouseMoveEvent(QMouseEvent *event) override;
    virtual void wheelEvent(QWheelEvent* pe) override;
};
