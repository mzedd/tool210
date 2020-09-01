#ifndef CLIPSCREEN_H
#define CLIPSCREEN_H

#include <QWidget>
#include "aspectratiowidget.h"
#include "openglscreen.h"
#include "controllers/clipscreencontroller.h"

class OpenGLModel;

class ClipScreenView : public QWidget
{
    Q_OBJECT

public:
    explicit ClipScreenView(OpenGLModel *model, QWidget *parent = nullptr);
    void setController(ClipScreenController *clipScreenController);

private:
    AspectRatioWidget *aspectRatioWidget;
    OpenGLScreen *openGLScreen;

    ClipScreenController *clipScreenController;
};

#endif // CLIPSCREEN_H
