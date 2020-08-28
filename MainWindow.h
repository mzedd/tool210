#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include "modules/ClipScreen/ClipScreen.h"
#include "modules/Timeline/Timeline.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private:
    void createMenu();
    void createInitialWidgets();
    void setupConnections();

    ClipScreen *clipScreen;
    Timeline *timeline;
};
#endif // MAINWINDOW_H
