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
