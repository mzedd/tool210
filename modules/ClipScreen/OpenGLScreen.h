#ifndef OPENGLSCREEN_H
#define OPENGLSCREEN_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>

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
};

#endif // OPENGLSCREEN_H
