#include "demofileaccess.h"

#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QString>

DemoFileAccess::DemoFileAccess()
{
    QFile file("resources/demo.json");

    if(!file.open(QIODevice::ReadOnly)) {
        qWarning("Couldn't open demo file.");
    }

    QByteArray fileContent = file.readAll();

    QJsonDocument document(QJsonDocument::fromJson(fileContent));

    jsonObject = document.object();
}

QString DemoFileAccess::getDemoName()
{
    if(jsonObject.contains("name")) {
        QString val = jsonObject["name"].toString();
        return  val;
    }

    return QString();
}

std::vector<Clip *> DemoFileAccess::getClipList()
{
    return std::vector<Clip *>();
}

std::vector<Scene *> DemoFileAccess::getSceneList()
{
    return  std::vector<Scene *>();
}
