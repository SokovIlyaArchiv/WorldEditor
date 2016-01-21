#pragma once

#include <QGraphicsView>
#include <QMouseEvent>
class Viewer : public QGraphicsView {
    Q_OBJECT

public:
    Viewer(QWidget *parent = 0);
    QGraphicsItem* getSelectedItem();
public slots:
    void removeItem(bool);
signals:
    void itemSelected(QGraphicsItem* );
    void getRemoveItem(QGraphicsItem* );
protected:
    virtual void mousePressEvent(QMouseEvent *event) override;
    virtual void mouseMoveEvent(QMouseEvent *event) override;
    virtual void wheelEvent(QWheelEvent* pe) override;
};
