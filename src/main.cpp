#include "controller/viewController.h"

#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    ViewController w;
    w.setWindowTitle("storageDevice");
    w.show();
    return a.exec();
}
