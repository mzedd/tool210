#ifndef CLIPSCREEN_H
#define CLIPSCREEN_H

#include <QWidget>
#include <QBoxLayout>
#include <QResizeEvent>
#include "OpenGLScreen.h"

class ClipScreen : public QWidget
{
    Q_OBJECT

public:
    explicit ClipScreen(QWidget *parent = nullptr);
    ~ClipScreen();
    OpenGLScreen* getOpenGLScreen() const;

protected:
    void resizeEvent(QResizeEvent *event) override;

private:
    QBoxLayout *layout;
    OpenGLScreen *openGLScreen;
};

#endif // CLIPSCREEN_H
