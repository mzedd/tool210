#include "demojsonfileaccess.h"

#include "demo.h"
#include "clip.h"
#include "scene.h"

#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QString>

Tool210::Entities::Demo *DemoJsonFileAccess::getDemo(QString filepath)
{
    loadFile(filepath);

    Tool210::Entities::Demo *demo = new Tool210::Entities::Demo;
    demo->setName(getDemoName().toStdString());

    populateSceneList(demo);
    populateClipList(demo);

    return demo;
}

void DemoJsonFileAccess::storeDemo(QString filepath, Tool210::Entities::Demo* demo)
{
    QFile file(filepath);

    if(!file.open(QIODevice::WriteOnly)) {
        qWarning("Couldn't open demo file.");
        return;
    }

    // construct demo json object
    QJsonObject demoJsonObject;
    demoJsonObject.insert(QString("name"), QString::fromStdString(demo->name()));

    QJsonArray clipArray;
    for(Tool210::Entities::Clip *clip : demo->clipList()) {
        QJsonObject clipJsonObject;
        clipJsonObject.insert("name", QString::fromStdString(clip->name()));
        clipJsonObject.insert("duration", clip->duration());
        clipJsonObject.insert("scene id", getSceneIdFrom(clip->scene(), demo->sceneList()));
        clipArray.append(clipJsonObject);
    }
    demoJsonObject.insert("clip list", clipArray);

    QJsonArray sceneArray;
    for(Tool210::Entities::Scene *scene : demo->sceneList()) {
        QJsonObject sceneJsonObject;
        sceneJsonObject.insert("name", QString::fromStdString(scene->name()));
        sceneJsonObject.insert("shader file name", QString::fromStdString(scene->shaderFileName()));
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

void DemoJsonFileAccess::populateSceneList(Tool210::Entities::Demo *demo)
{
    if(jsonObject.contains("scene list") && jsonObject["scene list"].isArray()) {
        QJsonArray array = jsonObject["scene list"].toArray();

        demo->sceneList().reserve(array.size());
        for(int i = 0; i < array.size(); i++) {
            QJsonObject sceneJsonObject = array.at(i).toObject();

            demo->addScene();
            Tool210::Entities::Scene *scene = demo->sceneList().back();

            scene->setName(sceneJsonObject["name"].toString().toStdString());
            scene->setShaderFileName(sceneJsonObject["shader file name"].toString().toStdString());
        }
    }
}


void DemoJsonFileAccess::populateClipList(Tool210::Entities::Demo *demo)
{
    if(jsonObject.contains("clip list") && jsonObject["clip list"].isArray()) {
        QJsonArray array =  jsonObject["clip list"].toArray();

        demo->clipList().reserve(array.size());
        for (int i = 0; i < array.size(); i++) {
            QJsonObject clipJsonObject = array.at(i).toObject();

            demo->addClip();
            Tool210::Entities::Clip *clip = demo->clipList().back();

            clip->setName(clipJsonObject["name"].toString().toStdString());
            clip->setDuration(static_cast<float>(clipJsonObject["duration"].toDouble()));
            clip->setScene(demo->sceneList().at(clipJsonObject["scene id"].toInt()));

            if (clipJsonObject.contains("camera")) {
                QJsonObject camera = clipJsonObject["camera"].toObject();

                Tool210::Entities::Point point;

                QJsonObject jsonPoint = camera["position"].toObject();
                point.x = jsonPoint["x"].toDouble();
                point.y = jsonPoint["y"].toDouble();
                point.z = jsonPoint["z"].toDouble();
                clip->getCamera().setPosition(point);

                jsonPoint = camera["lookAt"].toObject();
                point.x = jsonPoint["x"].toDouble();
                point.y = jsonPoint["y"].toDouble();
                point.z = jsonPoint["z"].toDouble();
                clip->getCamera().setLookAtPoint(point);

                clip->getCamera().setRoll(camera["roll"].toDouble());
                clip->getCamera().setZoom(camera["zoom"].toDouble());
            }
        }
    }
}

int DemoJsonFileAccess::getSceneIdFrom(Tool210::Entities::Scene *scene, std::vector<Tool210::Entities::Scene *> &sceneList) const
{
    for(size_t i = 0; i < sceneList.size(); i++) {
        if(sceneList.at(i) == scene)
            return static_cast<int>(i);
    }
    return -1;
}

