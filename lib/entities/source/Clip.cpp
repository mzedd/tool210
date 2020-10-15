#include "Clip.h"

const std::string DEFAULT_CLIP_NAME = "default";
constexpr float DEFAULT_CLIP_DURATION = 10.0f;

Clip::Clip() :
    name_(DEFAULT_CLIP_NAME),
    duration_(DEFAULT_CLIP_DURATION),
    scene_(nullptr)
{

}

std::string Clip::name() const
{
    return name_;
}

void Clip::setName(std::string name)
{
    this->name_ = name;
}

float Clip::duration() const
{
    return duration_;
}

void Clip::setDuration(float duration)
{
    this->duration_ = duration;
}

Scene *Clip::scene() const
{
    return scene_;
}

void Clip::setScene(Scene *scene)
{
    this->scene_ = scene;
}

Camera &Clip::getCamera()
{
    return camera;
}
