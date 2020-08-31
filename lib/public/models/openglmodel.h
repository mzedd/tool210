#ifndef OPENGLMODEL_H
#define OPENGLMODEL_H

#include <QObject>
#include <QOpenGLFunctions>
#include "demo/Clip.h"

class Q_DECL_EXPORT OpenGLModel : public QObject, protected QOpenGLFunctions
{
    Q_OBJECT
public:
    explicit OpenGLModel(QObject *parent = nullptr);

    void initializeGL();
    void resiszeGL(int w, int h);
    void paintGL();

private:
    float time;
    Clip *clipToRender;
    bool run;

Q_SIGNALS:
    void frameFinished();

public Q_SLOTS:
    void setTime(float time);
    void setClipToRender(int id);
    void playPauseDemo();
};

#endif // OPENGLMODEL_H
