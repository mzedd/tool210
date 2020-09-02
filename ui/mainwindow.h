#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>

#include "controllers/maincontroller.h"

#include "views/timeline/timelineview.h"
#include "views/clipscreen/clipscreenview.h"
#include "views/clipinspector/clipinspectorview.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void setMainController(MainController *mainController);
    void setClipListModel(ClipListModel* clipListModel);
    void setOpenGLModel(OpenGLModel *openGLmodel);
    void setClipInspectorModel(ClipInspectorModel* model);
    void initialize();

private:
    MainController *mainController;
    TimelineView *timelineView;
    ClipScreenView *clipScreenView;
    ClipInspectorView *clipInspectorView;

    void createMenu();
    void createWidgets();
};
#endif // MAINWINDOW_H
