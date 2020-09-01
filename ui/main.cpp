#include <QApplication>

#include "mainwindow.h"
#include "demo/Demo.h"

#include "maincontroller.h"

int main(int argc, char *argv[])
{
    QApplication::setApplicationName("tool210");
    QApplication::setOrganizationName("Team 210");
    QApplication app(argc, argv);

    MainWindow mainWindow;
    MainController mainController;

    mainWindow.setMainController(&mainController);

    // TESTING
    Demo::instance().addClip();
    Demo::instance().clipAt(0).setDuration(50.f);

    mainWindow.initialize();

    mainWindow.show();
    return app.exec();
}
