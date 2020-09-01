#ifndef OPENGLSCREEN_H
#define OPENGLSCREEN_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <models/openglmodel.h>
#include "models/ShaderOnlyScene.h"

class OpenGLScreen : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT
public:
    OpenGLScreen(OpenGLModel *model, QWidget* parent = nullptr);
    ~OpenGLScreen();

protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;

private:
    OpenGLModel *model;

};

#endif // OPENGLSCREEN_H
