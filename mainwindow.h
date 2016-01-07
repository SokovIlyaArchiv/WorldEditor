#include <QGraphicsView>
#include <QMouseEvent>
class MainWindow : public QGraphicsView {
    Q_OBJECT

public:
    MainWindow(QGraphicsScene* scene, QWidget *parent = 0);
    void mouseMoveEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent* pe);
};
