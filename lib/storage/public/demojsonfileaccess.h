#ifndef DEMOJSONFILEACCESS_H
#define DEMOJSONFILEACCESS_H

#include "demofileaccessinterface.h"
#include <QJsonObject>

class DemoJsonFileAccess : public DemoFileAccessInterface
{
public:
    Demo *getDemo(QString filepath);
    void storeDemo(QString filepath, Demo* demo);

private:
    void loadFile(QString filename);
    QString getDemoName();
    void populateSceneList(Demo *demo);
    void populateClipList(Demo *demo);

    int getSceneIdFrom(Scene *scene, std::vector<Scene *> &sceneList) const;

    QJsonObject jsonObject;
};

#endif // DEMOJSONFILEACCESS_H
