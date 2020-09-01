#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>

#include "controllers/maincontroller.h"

#include "views/timeline/timelineview.h"
#include "views/clipscreen/clipscreenview.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void setMainController(MainController *mainController);
    void initialize();

private:
    MainController *mainController;
    TimelineView *timelineView;
    ClipScreenView *clipScreenView;

    void createMenu();
    void createWidgets();
};
#endif // MAINWINDOW_H
