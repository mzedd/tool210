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

signals:

};

#endif // CLIPSCREENCONTROLLER_H
