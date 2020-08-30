#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include "views/cliplistview.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private:
    ClipListView *clipListView;

    void createMenu();
    void createWidgets();
};
#endif // MAINWINDOW_H
