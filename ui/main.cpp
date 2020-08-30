#include "mainwindow.h"
#include "demo/Demo.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    // TESTING
    Demo::instance().addClip();
    Demo::instance().clipAt(0).setDuration(50.f);

    w.show();
    return a.exec();
}
