#ifndef DEMOFILEACCESS_H
#define DEMOFILEACCESS_H

#include "demofileaccessinterface.h"
#include <QJsonObject>

class DemoFileAccess : public DemoFileAccessInterface
{
public:
    DemoFileAccess();
    QString getDemoName();
    std::vector<Clip *> getClipList();
    std::vector<Scene *> getSceneList();

private:
    QJsonObject jsonObject;
};

#endif // DEMOFILEACCESS_H
