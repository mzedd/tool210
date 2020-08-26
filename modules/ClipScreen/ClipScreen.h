#ifndef CLIPSCREEN_H
#define CLIPSCREEN_H

#include <QDockWidget>

namespace Ui {
class ClipScreen;
}

class ClipScreen : public QDockWidget
{
    Q_OBJECT

public:
    explicit ClipScreen(QWidget *parent = nullptr);
    ~ClipScreen();

private:
    Ui::ClipScreen *ui;
};

#endif // CLIPSCREEN_H
