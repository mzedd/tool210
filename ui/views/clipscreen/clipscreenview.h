#ifndef CLIPSCREEN_H
#define CLIPSCREEN_H

#include <QWidget>
#include "aspectratiowidget.h"
#include "openglscreen.h"

class OpenGLModel;
class RenderContext;

class ClipScreenView : public QWidget
{
    Q_OBJECT

public:
    explicit ClipScreenView(OpenGLModel *model, QWidget *parent = nullptr);

    QSize sizeHint() const;

    void setRenderContext(RenderContext *renderContext);

private:
    AspectRatioWidget *aspectRatioWidget;
    OpenGLScreen *openGLScreen;
};

#endif // CLIPSCREEN_H
