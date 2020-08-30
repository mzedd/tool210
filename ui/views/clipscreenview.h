#ifndef CLIPSCREEN_H
#define CLIPSCREEN_H

#include <QWidget>
#include <QBoxLayout>
#include <QResizeEvent>
#include "openglscreen.h"

class ClipScreenView : public QWidget
{
    Q_OBJECT

public:
    explicit ClipScreenView(QWidget *parent = nullptr);

protected:
    void resizeEvent(QResizeEvent *event) override;

private:
    QBoxLayout *layout;
    OpenGLScreen *openGLScreen;
};

#endif // CLIPSCREEN_H
