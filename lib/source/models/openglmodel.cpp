#include "openglmodel.h"
#include "models/Demo.h"
#include "models/Scene.h"

OpenGLModel::OpenGLModel(QObject *parent) :
    QObject(parent),
    time_(5.0f),
    clipToRender_(nullptr),
    run(false)
{

}

void OpenGLModel::setTime(float time)
{
    this->time_ = time;
}

void OpenGLModel::setClipToRender(Clip *clip)
{
    clipToRender_ = clip;
    emit clipToRenderChanged();
}

Clip *OpenGLModel::clipToRender() const
{
    return clipToRender_;
}

float OpenGLModel::time() const
{
    return time_;
}

void OpenGLModel::playPauseDemo()
{
    run = !run;
}
