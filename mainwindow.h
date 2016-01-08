#include <QGraphicsView>
#include <QMouseEvent>
class MainWindow : public QGraphicsView {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    void mouseMoveEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent* pe);
};
