#ifndef OPENGLSCREEN_H
#define OPENGLSCREEN_H

#include <QOpenGLWidget>
#include <models/openglmodel.h>

class RenderContext;

class OpenGLScreen : public QOpenGLWidget
{
    Q_OBJECT
public:
    OpenGLScreen(OpenGLModel *model, QWidget* parent = nullptr);
    ~OpenGLScreen();

    void setRenderContext(RenderContext *renderContext);

protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;

private:
    OpenGLModel *model;
    RenderContext *renderContext;

Q_SIGNALS:
    void frameFinishedAt(float time);

};

#endif // OPENGLSCREEN_H
