#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include <QObject>

#include "demo.h"
#include "models/cliplistmodel.h"
#include "models/scenelistmodel.h"
#include "controllers/renderer.h"
#include "interactors/addsceneinteractor.h"
#include "demofileaccessinterface.h"
#include "rendercontext.h"

class Q_DECL_EXPORT MainController : public QObject
{
    Q_OBJECT
public:
    explicit MainController(QObject *parent = nullptr);
    void setupConnections();

    void setClipListModel(ClipListModel *clipListModel);
    void setSceneListModel(SceneListModel *sceneListModel);
    void setRenderer(Renderer *renderer);

    void setAddSceneInteractor(AddSceneInteractor *addSceneInteractor);
    void setRenderContext(RenderContext *renderContext);

    void setDemoFileAccessor(DemoFileAccessInterface *demoFileAccessor);

private:
    void distributeDemo();
    void distributeDemoToModels();
    void distributeDemoToInteractors();

    Tool210::Entities::Demo* demo;

    ClipListModel *clipListModel;
    SceneListModel *sceneListModel;
    Renderer *renderer;

    AddSceneInteractor *addSceneInteractor;
    RenderContext *renderContext;

    DemoFileAccessInterface *demoFileAccessor;

public Q_SLOTS:
    void newDemo();
    void loadDemo(QString filename);
    void storeDemo(QString filename);

    void modelDataChanged();

};

#endif // MAINCONTROLLER_H
