#include "demojsonfileaccess.h"

#include "Demo.h"
#include "Clip.h"
#include "Scene.h"

#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QString>

Demo *DemoJsonFileAccess::getDemo(QString filepath)
{
    loadFile(filepath);

    Demo *demo = new Demo;
    demo->setName(getDemoName().toStdString());

    populateSceneList(demo);
    populateClipList(demo);

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
    demoJsonObject.insert(QString("name"), QString::fromStdString(demo->name()));

    QJsonArray clipArray;
    for(Clip *clip : demo->clipList()) {
        QJsonObject clipJsonObject;
        clipJsonObject.insert("name", QString::fromStdString(clip->name()));
        clipJsonObject.insert("duration", clip->duration());
        clipJsonObject.insert("scene id", getSceneIdFrom(clip->scene(), demo->sceneList()));
        clipArray.append(clipJsonObject);
    }
    demoJsonObject.insert("clip list", clipArray);

    QJsonArray sceneArray;
    for(Scene *scene : demo->sceneList()) {
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

void DemoJsonFileAccess::populateSceneList(Demo *demo)
{
    if(jsonObject.contains("scene list") && jsonObject["scene list"].isArray()) {
        QJsonArray array = jsonObject["scene list"].toArray();

        demo->sceneList().reserve(array.size());
        for(int i = 0; i < array.size(); i++) {
            QJsonObject sceneJsonObject = array.at(i).toObject();

            demo->addScene();
            Scene *scene = demo->sceneList().back();

            scene->setName(sceneJsonObject["name"].toString().toStdString());
            scene->setShaderFileName(sceneJsonObject["shader file name"].toString().toStdString());
        }
    }
}


void DemoJsonFileAccess::populateClipList(Demo *demo)
{
    if(jsonObject.contains("clip list") && jsonObject["clip list"].isArray()) {
        QJsonArray array =  jsonObject["clip list"].toArray();

        demo->clipList().reserve(array.size());
        for (int i = 0; i < array.size(); i++) {
            QJsonObject clipJsonObject = array.at(i).toObject();

            demo->addClip();
            Clip *clip = demo->clipList().back();

            clip->setName(clipJsonObject["name"].toString().toStdString());
            clip->setDuration(static_cast<float>(clipJsonObject["duration"].toDouble()));
            clip->setScene(demo->sceneList().at(clipJsonObject["scene id"].toInt()));

            if (clipJsonObject.contains("camera")) {
                QJsonObject camera = clipJsonObject["camera"].toObject();

                Point point;

                QJsonObject jsonPoint = camera["position"].toObject();
                point.x = jsonPoint["x"].toDouble();
                point.y = jsonPoint["y"].toDouble();
                point.z = jsonPoint["z"].toDouble();
                clip->getCamera().position = point;

                jsonPoint = camera["lookAt"].toObject();
                point.x = jsonPoint["x"].toDouble();
                point.y = jsonPoint["y"].toDouble();
                point.z = jsonPoint["z"].toDouble();
                clip->getCamera().lookAt = point;

                jsonPoint = camera["up"].toObject();
                point.x = jsonPoint["x"].toDouble();
                point.y = jsonPoint["y"].toDouble();
                point.z = jsonPoint["z"].toDouble();
                clip->getCamera().up = point;

                clip->getCamera().zoom = camera["zoom"].toDouble();
            }

        }
    }
}

int DemoJsonFileAccess::getSceneIdFrom(Scene *scene, std::vector<Scene *> &sceneList) const
{
    for(size_t i = 0; i < sceneList.size(); i++) {
        if(sceneList.at(i) == scene)
            return static_cast<int>(i);
    }
    return -1;
}

