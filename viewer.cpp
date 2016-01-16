#include "viewer.h"
#include <QDebug>
#include <QGraphicsItem>

Viewer::Viewer(QWidget *parent) : QGraphicsView(parent){

    setFixedSize(800,600);
}

void Viewer::mouseMoveEvent(QMouseEvent *event) {
    QGraphicsView::mouseMoveEvent(event);
    if(event->buttons() == Qt::RightButton) {
        centerOn(mapToScene(event->pos()));
    }
}

void Viewer::wheelEvent(QWheelEvent *event) {
        centerOn(mapToScene(event->pos()));
        if(event->delta() > 0) {
            scale(1.5,1.5);
        } else {
            scale(0.66,0.66);
        }
}
