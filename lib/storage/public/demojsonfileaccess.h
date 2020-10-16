#ifndef DEMOJSONFILEACCESS_H
#define DEMOJSONFILEACCESS_H

#include "demofileaccessinterface.h"
#include <QJsonObject>

class DemoJsonFileAccess : public DemoFileAccessInterface
{
public:
    Tool210::Entities::Demo *getDemo(QString filepath);
    void storeDemo(QString filepath, Tool210::Entities::Demo* demo);

private:
    void loadFile(QString filename);
    QString getDemoName();
    void populateSceneList(Tool210::Entities::Demo *demo);
    void populateClipList(Tool210::Entities::Demo *demo);

    int getSceneIdFrom(Tool210::Entities::Scene *scene, std::vector<Tool210::Entities::Scene *> &sceneList) const;

    QJsonObject jsonObject;
};

#endif // DEMOJSONFILEACCESS_H
