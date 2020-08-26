#ifndef CLIPSCREEN_H
#define CLIPSCREEN_H

#include <QWidget>
#include <QBoxLayout>
#include <QResizeEvent>

class ClipScreen : public QWidget
{
    Q_OBJECT

public:
    explicit ClipScreen(QWidget *parent = nullptr);
    ~ClipScreen();

protected:
    void resizeEvent(QResizeEvent *event) override;

private:
    QBoxLayout *layout;
};

#endif // CLIPSCREEN_H
