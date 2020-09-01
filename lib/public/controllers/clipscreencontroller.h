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
    void setClipToRender(Clip *clip);

private:
    OpenGLModel *model;

};

#endif // CLIPSCREENCONTROLLER_H
