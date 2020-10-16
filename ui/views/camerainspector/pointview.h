#ifndef POINTVIEW_H
#define POINTVIEW_H

#include <QWidget>

namespace Ui {
class PointView;
}

class PointView : public QWidget
{
    Q_OBJECT

public:
    explicit PointView(QWidget *parent = nullptr);
    ~PointView();

private:
    Ui::PointView *ui;
};

#endif // POINTVIEW_H
