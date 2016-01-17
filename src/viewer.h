#pragma once

#include <QGraphicsView>
#include <QMouseEvent>
class Viewer : public QGraphicsView {
    Q_OBJECT

public:
    Viewer(QWidget *parent = 0);
public slots:
    void removeItem(bool);
signals:
    void removeSelectableItem(QGraphicsItem* );
protected:
    virtual void mousePressEvent(QMouseEvent *event) override;
    virtual void mouseMoveEvent(QMouseEvent *event) override;
    virtual void wheelEvent(QWheelEvent* pe) override;
};
