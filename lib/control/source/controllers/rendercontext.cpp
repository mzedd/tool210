#include "rendercontext.h"
#include <algorithm>

constexpr float MSEC_PER_SECS = 0.001f;

RenderContext::RenderContext(QObject *parent) :
    QObject(parent),
    time_(10.0f),
    run_(false),
    timeAtRunChanged(0.0f)

{
    timer.start();
}

void RenderContext::setDemo(Demo *demo)
{
    this->demo = demo;
}

void RenderContext::setRenderer(Renderer *renderer)
{
    this->renderer = renderer;
}

float RenderContext::time() const
{
    return time_;
}

void RenderContext::setTime(float time)
{
    time_ = std::max(0.0f, time);
    timeAtRunChanged = timer.elapsed() * MSEC_PER_SECS - time_;

    int clipId = demo->clipIdAt(time);

    if(clipId > -1) {
        Clip *clipToRender = demo->clipList().at(clipId);
        renderer->setClipToRender(clipToRender);
    }

    emit timeChanged();
}

bool RenderContext::run() const
{
    return run_;
}

void RenderContext::setRun(bool run)
{
    run_ = run;
    timeAtRunChanged = timer.elapsed() * MSEC_PER_SECS - time_;
    emit runChanged();
}

float RenderContext::deltaTime()
{
    setTime(timer.elapsed() * MSEC_PER_SECS - timeAtRunChanged);
    return time_;
}
