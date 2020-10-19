#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include <QApplication>

#include "controllers/maincontroller.h"
#include "views/timeline/timelineview.h"
#include "views/clipscreen/clipscreenview.h"
#include "views/clipinspector/clipinspectorview.h"
#include "views/sceneeditor/sceneeditorview.h"

#include "views/camerainspector/camerainspectorview.h"
#include "views/camerainspector/camerainspectorpresenter.h"

class RenderContext;
class AddSceneInteractor;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void setMainController(MainController *mainController);
    void setClipListModel(ClipListModel* clipListModel);
    void setSceneListModel(SceneListModel *sceneListModel);
    void setOpenGLModel(OpenGLScreen *openGLScreen);
    void setRenderContext(RenderContext *renderContext);
    void setCameraInspectorPresenter(CameraInspectorPresenter *cameraInspectorPresenter);
    void setCameraInspectorInputBoundary(CameraInspectorInputBoundary *inputBoundary);
    void initialize();

private:
    MainController *mainController;

    TimelineView *timelineView;
    ClipScreenView *clipScreenView;
    ClipInspectorView *clipInspectorView;
    SceneEditorView *sceneEditorView;
    CameraInspectorView *cameraInspectorView;

    CameraInspectorPresenter *cameraInspectorPresenter;

    void createMenu();
    void createWidgets();
    void createConnections();

private Q_SLOTS:
    void handleNewDemo();
    void handleLoadDemo();
    void handelSaveDemo();

};
#endif // MAINWINDOW_H
