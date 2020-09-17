#ifndef DEMOJSONFILEACCESS_H
#define DEMOJSONFILEACCESS_H

#include "demofileaccessinterface.h"
#include <QJsonObject>

class DemoJsonFileAccess : public DemoFileAccessInterface
{
public:
    DemoJsonFileAccess(QString filename);
    Demo *getDemo();
    void storeDemo(QString filepath, Demo* demo);

private:
    void loadFile(QString filename);
    QString getDemoName();
    std::vector<Scene *> *getSceneList();
    std::vector<Clip *> *getClipList(std::vector<Scene *> *sceneList);

    int getSceneIdFrom(Scene *scene, std::vector<Scene *> &sceneList) const;

    QJsonObject jsonObject;
};

#endif // DEMOJSONFILEACCESS_H
