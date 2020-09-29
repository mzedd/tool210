#include "rendercontext.h"
#include <algorithm>

constexpr float MSEC_PER_SECS = 0.001f;

RenderContext::RenderContext(QObject *parent) :
    QObject(parent),
    time_(10.0f),
    timeAtRunChanged(0.0f)
{
    timer.start();
}

float RenderContext::time() const
{
    return time_;
}

void RenderContext::setTime(float time)
{
    time_ = std::max(0.0f, time);
    timeAtRunChanged = timer.elapsed() * MSEC_PER_SECS - time_;
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
    time_ = timer.elapsed() * MSEC_PER_SECS - timeAtRunChanged;
    return time_;
}
