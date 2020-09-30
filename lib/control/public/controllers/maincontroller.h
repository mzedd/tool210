#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include <QObject>

#include "Demo.h"
#include "models/cliplistmodel.h"
#include "models/scenelistmodel.h"
#include "interactors/addsceneinteractor.h"
#include "demofileaccessinterface.h"

class Q_DECL_EXPORT MainController : public QObject
{
    Q_OBJECT
public:
    explicit MainController(QObject *parent = nullptr);

    void setClipListModel(ClipListModel *clipListModel);
    void setSceneListModel(SceneListModel *sceneListModel);

    void setAddSceneInteractor(AddSceneInteractor *addSceneInteractor);

    void setDemoFileAccessor(DemoFileAccessInterface *demoFileAccessor);

private:
    void distributeDemo();
    void distributeDemoToModels();
    void distributeDemoToInteractors();

    Demo* demo;

    ClipListModel *clipListModel;
    SceneListModel *sceneListModel;

    AddSceneInteractor *addSceneInteractor;

    DemoFileAccessInterface *demoFileAccessor;

public Q_SLOTS:
    void newDemo();
    void loadDemo(QString filename);
    void storeDemo(QString filename);

};

#endif // MAINCONTROLLER_H
