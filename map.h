#include <vector>
#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
class Map {
public:
    Map();
    ~Map();
    void load();
    QGraphicsScene* getScene();
private:
    std::vector< QGraphicsPixmapItem* > items;
    QGraphicsScene* scene;
};
