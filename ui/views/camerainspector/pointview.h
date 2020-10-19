#ifndef POINTVIEW_H
#define POINTVIEW_H

#include <QWidget>
#include <QVector3D>
#include "pointviewmodel.h"

namespace Ui {
class PointView;
}

class PointView : public QWidget
{
    Q_OBJECT

public:
    explicit PointView(QWidget *parent = nullptr);
    ~PointView();

    void updateView(PointViewModel model);
    QVector3D getPoint();

private:
    Ui::PointView *ui;
};

#endif // POINTVIEW_H
