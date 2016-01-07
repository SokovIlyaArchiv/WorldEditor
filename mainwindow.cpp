#include "mainwindow.h"
#include <QDebug>
#include <QGraphicsItem>
MainWindow::MainWindow(QGraphicsScene *scene, QWidget *parent) :
    QGraphicsView(scene,parent) {
    resize(800,600);
}

void MainWindow::mouseMoveEvent(QMouseEvent *event) {
    QGraphicsView::mouseMoveEvent(event);
    if(event->buttons() == Qt::RightButton) {
        centerOn(mapToScene(event->pos()));
    }
}

void MainWindow::wheelEvent(QWheelEvent *event) {
        centerOn(mapToScene(event->pos()));
        if(event->delta() > 0) {
            scale(1.5,1.5);
        } else {
            scale(0.66,0.66);
        }
}
