#include "Clip.h"

const QString DEFAULT_CLIP_NAME = "default";
constexpr float DEFAULT_CLIP_DURATION = 10.0f;

Clip::Clip() :
    name_(DEFAULT_CLIP_NAME),
    duration(DEFAULT_CLIP_DURATION),
    scene(nullptr)
{

}

void Clip::renderAt(float time)
{
    scene->renderAt(time);
}

QString Clip::name() const
{
    return name_;
}

void Clip::setName(QString name)
{
    this->name_ = name;
}

float Clip::getDuration()
{
    return duration;
}

void Clip::setDuration(float duration)
{
    this->duration = duration;
}

Scene *Clip::getScene()
{
    return scene;
}

void Clip::setScene(Scene *scene)
{
    this->scene = scene;
}
