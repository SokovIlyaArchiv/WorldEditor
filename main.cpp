#include "mainwindow.h"
#include "scene.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Scene scene;
    MainWindow w;

    w.setScene(&scene);
    w.show();
    return a.exec();
}
