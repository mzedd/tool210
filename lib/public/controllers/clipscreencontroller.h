#ifndef CLIPSCREENCONTROLLER_H
#define CLIPSCREENCONTROLLER_H

#include <QObject>
#include "models/openglmodel.h"

class Q_DECL_EXPORT ClipScreenController : public QObject
{
    Q_OBJECT
public:
    explicit ClipScreenController(QObject *parent = nullptr);
    void setModel(OpenGLModel *openGLModel);
    void setTime(float time);
    void setClipToRender(Clip *clip);
    void toggleRun();


private:
    OpenGLModel *model;

Q_SIGNALS:
    void frameFinishedAt(float time);

};

#endif // CLIPSCREENCONTROLLER_H
