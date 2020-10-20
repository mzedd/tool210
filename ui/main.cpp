#include <QApplication>

#include "mainwindow.h"

#include "controllers/maincontroller.h"
#include "editorcontext.h"
#include "interactors/addsceneinteractor.h"
#include "interactors/setcameradatainteractor.h"

#include "models/cliplistmodel.h"
#include "models/scenelistmodel.h"
#include "models/openglrenderer.h"
#include "rendercontext.h"
#include "controllers/editorcontext.h"

#include "views/clipscreen/openglscreen.h"
#include "views/camerainspector/camerainspectorpresenter.h"

#include "demojsonfileaccess.h"

int main(int argc, char *argv[])
{
    QApplication::setApplicationName("tool210");
    QApplication::setOrganizationName("Team 210");
    QApplication app(argc, argv);

    MainWindow mainWindow;

    RenderContext *renderContext = new RenderContext;
    EditorContext *editorContext = new EditorContext;

    ClipListModel *clipListModel = new ClipListModel;
    SceneListModel *sceneListModel = new SceneListModel;
    OpenGLScreen *openGLScreen = new OpenGLScreen;

    AddSceneInteractor *addSceneInteractor = new AddSceneInteractor(openGLScreen);
    CameraInspectorPresenter *cameraInspectorPresenter = new CameraInspectorPresenter;
    SetCameraDataInteractor *setCameraDataInteractor = new SetCameraDataInteractor(cameraInspectorPresenter, editorContext, openGLScreen);

    DemoJsonFileAccess *demoFileAccessor = new DemoJsonFileAccess;
    MainController mainController;

    editorContext->setCameraDataInteractor(setCameraDataInteractor);

    renderContext->setRenderer(openGLScreen);
    sceneListModel->setAddScenenInteractor(addSceneInteractor);

    mainController.setClipListModel(clipListModel);
    mainController.setSceneListModel(sceneListModel);
    mainController.setRenderer(openGLScreen);
    mainController.setDemoFileAccessor(demoFileAccessor);
    mainController.setAddSceneInteractor(addSceneInteractor);
    mainController.setRenderContext(renderContext);
    mainController.setEditorContext(editorContext);

    mainWindow.setMainController(&mainController);
    mainWindow.setClipListModel(clipListModel);
    mainWindow.setSceneListModel(sceneListModel);
    mainWindow.setOpenGLModel(openGLScreen);
    mainWindow.setRenderContext(renderContext);
    mainWindow.setCameraInspectorPresenter(cameraInspectorPresenter);
    mainWindow.setCameraInspectorInputBoundary(setCameraDataInteractor);

    mainWindow.initialize();
    mainWindow.show();


    mainController.newDemo(); // initialize the editor with a fresh empty demo
    mainController.setupConnections();

    return app.exec();
}
