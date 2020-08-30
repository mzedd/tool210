#include "Clip.h"

const QString DEFAULT_CLIP_NAME = "default";
constexpr float DEFAULT_CLIP_DURATION = 10.0f;

Clip::Clip() :
    name(DEFAULT_CLIP_NAME),
    duration(DEFAULT_CLIP_DURATION),
    scene(nullptr)
{

}

void Clip::renderAt(float time)
{
    scene->renderAt(time);
}

QString Clip::getName()
{
    return name;
}

void Clip::setName(QString name)
{
    this->name = name;
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
