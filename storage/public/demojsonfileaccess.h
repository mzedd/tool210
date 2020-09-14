#ifndef DEMOJSONFILEACCESS_H
#define DEMOJSONFILEACCESS_H

#include "demofileaccessinterface.h"
#include <QJsonObject>

class DemoJsonFileAccess : public DemoFileAccessInterface
{
public:
    DemoJsonFileAccess(QString filename);
    Demo *getDemo();

private:
    void loadFile(QString filename);
    QString getDemoName();
    std::vector<Clip *> getClipList();
    std::vector<Scene *> getSceneList();

    QJsonObject jsonObject;
};

#endif // DEMOJSONFILEACCESS_H
