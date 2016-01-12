#include <QGraphicsView>
#include <QMouseEvent>
class Viewer : public QGraphicsView {
    Q_OBJECT

public:
    Viewer(QWidget *parent = 0);
protected:
    virtual void mouseMoveEvent(QMouseEvent *event) override;
    virtual void wheelEvent(QWheelEvent* pe) override;
};
