#ifndef OPENGLMODEL_H
#define OPENGLMODEL_H

#include <QObject>
#include <QElapsedTimer>
#include <QOpenGLFunctions>
#include "models/Clip.h"

class Q_DECL_EXPORT OpenGLModel : public QObject, protected QOpenGLFunctions
{
    Q_OBJECT

    Q_PROPERTY(float time READ time WRITE setTime NOTIFY timeChanged)
    Q_PROPERTY(bool run READ run WRITE setRun NOTIFY runChanged)

public:
    explicit OpenGLModel(QObject *parent = nullptr);

    float time() const;
    void setTime(float time);

    Clip *clipToRender() const;
    void setClipToRender(Clip *clip);

    bool run() const;
    void setRun(bool run);

    void initializeGL();
    void resiszeGL(int w, int h);
    void paintGL();

    float deltaTime();
    
private:
    float time_;
    Clip *clipToRender_;
    bool run_;

    QElapsedTimer timer;
    float timeAtRunChanged;

Q_SIGNALS:
    void timeChanged();
    void clipToRenderChanged();
    void runChanged();
};

#endif // OPENGLMODEL_H
