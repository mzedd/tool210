#include "MainWindow.h"
#include "demo/Demo.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    // TESTING
    Demo::instance().addClip();
    Demo::instance().clipAt(0).setName("Erster Clip");
    Demo::instance().clipAt(0).setDuration(100.0f);
    Demo::instance().addClip();
    Demo::instance().clipAt(1).setName("Zweiter Clip");
    Demo::instance().clipAt(1).setDuration(42.0f);
    Demo::instance().addClip();
    Demo::instance().clipAt(2).setName("Dritter Clip");
    Demo::instance().clipAt(2).setDuration(210.0f);

    w.show();
    return a.exec();
}
