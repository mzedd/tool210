#ifndef RENDERCONTEXT_H
#define RENDERCONTEXT_H

#include <QObject>
#include <QElapsedTimer>
#include "Demo.h"
#include "renderer.h"

class RenderContext : public QObject
{
    Q_OBJECT

public:
    RenderContext(QObject *parent = nullptr);

    void setDemo(Demo *demo);
    void setRenderer(Renderer *renderer);

    float time() const;
    void setTime(float time);

    bool run() const;
    void setRun(bool run);

    float deltaTime();

private:
    Demo *demo;
    Renderer *renderer;

    float time_;
    bool run_;

    QElapsedTimer timer;
    float timeAtRunChanged;

Q_SIGNALS:
    void runChanged();
    void timeChanged();
};

#endif // RENDERCONTEXT_H
