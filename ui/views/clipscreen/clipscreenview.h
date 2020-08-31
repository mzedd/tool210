#ifndef CLIPSCREEN_H
#define CLIPSCREEN_H

#include <QWidget>
#include "aspectratiowidget.h"
#include "openglscreen.h"

class ClipScreenView : public QWidget
{
    Q_OBJECT

public:
    explicit ClipScreenView(QWidget *parent = nullptr);

private:
    AspectRatioWidget *aspectRatioWidget;
    OpenGLScreen *openGLScreen;

    // model
};

#endif // CLIPSCREEN_H
