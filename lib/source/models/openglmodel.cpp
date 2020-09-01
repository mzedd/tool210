#include "openglmodel.h"
#include "models/Demo.h"
#include "models/Scene.h"

#include "models/ShaderOnlyScene.h"

OpenGLModel::OpenGLModel(QObject *parent) :
    QObject(parent),
    time_(5.0f),
    clipToRender_(nullptr),
    run(false)
{
    //scene = new ShaderOnlyScene;
    //clipToRender_ = new Clip;
    //clipToRender()->setScene(scene);
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
