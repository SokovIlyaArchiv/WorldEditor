#include <QGraphicsView>
#include <QMouseEvent>
class Viewer : public QGraphicsView {
    Q_OBJECT

public:
    Viewer(QWidget *parent = 0);
    void mouseMoveEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent* pe);
};
