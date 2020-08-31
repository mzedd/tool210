#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include "views/timeline/timelineview.h"
#include "views/clipscreen/clipscreenview.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private:
    TimelineView *timelineView;
    ClipScreenView *clipScreenView;

    void createMenu();
    void createWidgets();
};
#endif // MAINWINDOW_H
