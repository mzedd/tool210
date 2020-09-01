#include "clipscreencontroller.h"

ClipScreenController::ClipScreenController(QObject *parent) : QObject(parent)
{

}

void ClipScreenController::setModel(OpenGLModel *openGLModel)
{
    openGLModel->setParent(this);
}
