#ifndef OPENGLMODEL_H
#define OPENGLMODEL_H

#include <QObject>
#include "models/Clip.h"
#include "models/ShaderOnlyScene.h"

class Q_DECL_EXPORT OpenGLModel : public QObject
{
    Q_OBJECT
public:
    explicit OpenGLModel(QObject *parent = nullptr);

    void setClipToRender(Clip *clip);

    Clip *clipToRender() const;
    float time() const;

private:
    float time_;
    Clip *clipToRender_;
    bool run;
    ShaderOnlyScene *scene;

Q_SIGNALS:
    void clipToRenderChanged();
    void frameFinished();

public Q_SLOTS:
    void setTime(float time);
    void playPauseDemo();
};

#endif // OPENGLMODEL_H
