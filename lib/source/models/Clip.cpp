#include "Clip.h"

const QString DEFAULT_CLIP_NAME = "default";
constexpr float DEFAULT_CLIP_DURATION = 10.0f;

Clip::Clip(QObject *parent) :
    QObject(parent),
    name_(DEFAULT_CLIP_NAME),
    duration_(DEFAULT_CLIP_DURATION),
    scene_(nullptr)
{

}

void Clip::renderAt(float time)
{
    scene_->renderAt(time);
}

int Clip::id() const
{
    return id_;
}

void Clip::setId(int id)
{
    id_ = id;
    emit idChanged();
}

QString Clip::name() const
{
    return name_;
}

void Clip::setName(QString name)
{
    this->name_ = name;
    emit nameChanged();
}

float Clip::duration() const
{
    return duration_;
}

void Clip::setDuration(float duration)
{
    this->duration_ = duration;
    emit durationChanged();
}

Scene *Clip::scene() const
{
    return scene_;
}

void Clip::setScene(Scene *scene)
{
    this->scene_ = scene;
    emit sceneChanged();
}

int Clip::sceneId() const
{
    return sceneId_;
}

void Clip::setSceneId(int id)
{
    this->sceneId_ = id;
}
