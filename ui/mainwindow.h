#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>

#include "controllers/maincontroller.h"

#include "views/timeline/timelineview.h"
#include "views/clipinspector/clipinspectorview.h"
#include "views/sceneeditor/sceneeditorview.h"

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
    //ClipScreenView *clipScreenView;
    ClipInspectorView *clipInspectorView;
    SceneEditorView *sceneEditorView;

    void createMenu();
    void createWidgets();

Q_SIGNALS:
    void loadDemo(QString filepath);

private Q_SLOTS:
    void openDemoFile();

};
#endif // MAINWINDOW_H
