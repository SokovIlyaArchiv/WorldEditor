#include "viewer.h"
#include <QGraphicsItem>
Viewer::Viewer(QWidget *parent) : QGraphicsView(parent){
    setFixedSize(800,600);
}

QGraphicsItem *Viewer::getSelectedItem() {
    if(scene()->selectedItems().size() != 0) {
        return scene()->selectedItems().at(0);
    } else {
        return nullptr;
    }
}



void Viewer::removeItem(bool) {
    if(scene()->selectedItems().size() != 0) {
        emit getRemoveItem(getSelectedItem());
    }
}

void Viewer::mouseReleaseEvent(QMouseEvent *event) {
    QGraphicsView::mouseReleaseEvent(event);
    emit released(getSelectedItem());
}



void Viewer::mousePressEvent(QMouseEvent *event) {
    QGraphicsView::mousePressEvent(event);
    emit clicked(getSelectedItem());
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
