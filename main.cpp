#include <QApplication>
#include "window.h"
#include "data.h"
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Window window;
    window.show();
//    Data data;
//    data.load("data.txt");
    return a.exec();
}
