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
    std::vector<Scene *> *sceneList;
    std::vector<Clip *> *clipList;

    sceneList = getSceneList();
    clipList = getClipList(sceneList);

    Demo *demo = new Demo(clipList, sceneList);
    demo->setName(getDemoName());

    return demo;
}

void DemoJsonFileAccess::storeDemo(QString filepath, Demo* demo)
{
    QFile file(filepath);

    if(!file.open(QIODevice::WriteOnly)) {
        qWarning("Couldn't open demo file.");
        return;
    }

    // construct demo json object
    QJsonObject demoJsonObject;
    demoJsonObject.insert(QString("name"), demo->name());

    QJsonArray clipArray;
    for(Clip *clip : demo->clipList()) {
        QJsonObject clipJsonObject;
        clipJsonObject.insert("name", clip->name());
        clipJsonObject.insert("duration", clip->duration());
        clipJsonObject.insert("scene id", getSceneIdFrom(clip->scene(), demo->sceneList()));
        clipArray.append(clipJsonObject);
    }
    demoJsonObject.insert("clip list", clipArray);

    QJsonArray sceneArray;
    for(Scene *scene : demo->sceneList()) {
        QJsonObject sceneJsonObject;
        sceneJsonObject.insert("name", scene->name());
        sceneJsonObject.insert("shader file name", QString::fromStdString(static_cast<ShaderOnlyScene *>(scene)->shaderFileName()));
        sceneArray.append(sceneJsonObject);
    }
    demoJsonObject.insert("scene list", sceneArray);

    QJsonDocument document(demoJsonObject);
    file.write(document.toJson());
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

std::vector<Scene *> *DemoJsonFileAccess::getSceneList()
{
    std::vector<Scene *> *sceneList = new std::vector<Scene *>();
    ShaderOnlyScene *scene;

    if(jsonObject.contains("scene list") && jsonObject["scene list"].isArray()) {
        QJsonArray array = jsonObject["scene list"].toArray();

        sceneList->reserve(array.size());
        for(int i = 0; i < array.size(); i++) {
            QJsonObject sceneJsonObject = array.at(i).toObject();

            scene = new ShaderOnlyScene;
            scene->setName(sceneJsonObject["name"].toString());
            scene->setShaderFileName(sceneJsonObject["shader file name"].toString().toStdString());

            sceneList->push_back(scene);
        }
    }

    return sceneList;
}


std::vector<Clip *> *DemoJsonFileAccess::getClipList(std::vector<Scene *> *sceneList)
{
    std::vector<Clip *> *clipList = new std::vector<Clip *>();
    Clip *clip;

    if(jsonObject.contains("clip list") && jsonObject["clip list"].isArray()) {
        QJsonArray array =  jsonObject["clip list"].toArray();

        clipList->reserve(array.size());
        for (int i = 0; i < array.size(); i++) {
            QJsonObject clipJsonObject = array.at(i).toObject();

            clip = new Clip;
            clip->setName(clipJsonObject["name"].toString());
            clip->setDuration(static_cast<float>(clipJsonObject["duration"].toDouble()));
            clip->setScene(sceneList->at(clipJsonObject["scene id"].toInt()));

            clipList->push_back(clip);
        }
    }

    return clipList;
}

int DemoJsonFileAccess::getSceneIdFrom(Scene *scene, std::vector<Scene *> &sceneList) const
{
    for(size_t i = 0; i < sceneList.size(); i++) {
        if(sceneList.at(i) == scene)
            return static_cast<int>(i);
    }
    return -1;
}

