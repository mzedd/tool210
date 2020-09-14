#ifndef DEMOJSONFILEACCESS_H
#define DEMOJSONFILEACCESS_H

#include "demofileaccessinterface.h"
#include <QJsonObject>

class DemoJsonFileAccess : public DemoFileAccessInterface
{
public:
    DemoJsonFileAccess(QString filename);
    QString getDemoName();
    std::vector<Clip *> getClipList();
    std::vector<Scene *> getSceneList();

private:
    void loadFile(QString filename);

    QJsonObject jsonObject;
};

#endif // DEMOJSONFILEACCESS_H
