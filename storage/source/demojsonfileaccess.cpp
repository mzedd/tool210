#include "demojsonfileaccess.h"

#include "models/ShaderOnlyScene.h"
#include "models/Demo.h"

#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QString>

DemoJsonFileAccess::DemoJsonFileAccess(QString filename)
{
    loadFile(filename);
}

Demo *DemoJsonFileAccess::getDemo()
{
    Demo *demo = new Demo(getClipList(), getSceneList());
    demo->setName(getDemoName());

    return demo;
}

void DemoJsonFileAccess::loadFile(QString filename)
{
    QFile file(filename);

    if(!file.open(QIODevice::ReadOnly)) {
        qWarning("Couldn't open demo file.");
    }

    QByteArray fileContent = file.readAll();

    QJsonDocument document(QJsonDocument::fromJson(fileContent));

    jsonObject = document.object();
}

QString DemoJsonFileAccess::getDemoName()
{
    if(jsonObject.contains("name")) {
        QString val = jsonObject["name"].toString();
        return  val;
    }

    return QString();
}

std::vector<Clip *> DemoJsonFileAccess::getClipList()
{
    std::vector<Clip *> clipList = std::vector<Clip *>();
    Clip *clip;

    std::vector<Scene *> sceneList = getSceneList();

    if(jsonObject.contains("clip list") && jsonObject["clip list"].isArray()) {
        QJsonArray array =  jsonObject["clip list"].toArray();

        clipList.reserve(array.size());
        for (int i = 0; i < array.size(); i++) {
            QJsonObject clipJsonObject = array.at(i).toObject();

            clip = new Clip;
            clip->setName(clipJsonObject["name"].toString());
            clip->setDuration(static_cast<float>(clipJsonObject["duration"].toDouble()));
            clip->setSceneId(clipJsonObject["scene id"].toInt());

            clipList.push_back(clip);
        }
    }

    for(Scene* scene : sceneList) {
        delete scene;
    }

    return clipList;
}

std::vector<Scene *> DemoJsonFileAccess::getSceneList()
{
    std::vector<Scene *> sceneList = std::vector<Scene *>();
    ShaderOnlyScene *scene;

    if(jsonObject.contains("scene list") && jsonObject["scene list"].isArray()) {
        QJsonArray array = jsonObject["scene list"].toArray();

        sceneList.reserve(array.size());
        for(int i = 0; i < array.size(); i++) {
            QJsonObject sceneJsonObject = array.at(i).toObject();

            scene = new ShaderOnlyScene;
            scene->setName(sceneJsonObject["name"].toString());
            scene->setShader(sceneJsonObject["shader file name"].toString());

            sceneList.push_back(scene);
        }
    }

    return sceneList;
}
