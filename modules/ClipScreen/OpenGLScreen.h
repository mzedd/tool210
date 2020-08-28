#ifndef OPENGLSCREEN_H
#define OPENGLSCREEN_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include "demo/Clip.h"

class OpenGLScreen : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT
public:
    OpenGLScreen(QWidget* parent);
    ~OpenGLScreen();

protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;

private:
    float time;
    Clip *clipToRender;

signals:
    void timeChangend(float time);

public slots:
    void setTime(float time);
    void setClipToRender(int id);
};

#endif // OPENGLSCREEN_H
