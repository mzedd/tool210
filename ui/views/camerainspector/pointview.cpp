#include "pointview.h"
#include "ui_pointview.h"

PointView::PointView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PointView)
{
    ui->setupUi(this);
}

PointView::~PointView()
{
    delete ui;
}

void PointView::updateView(PointViewModel model)
{
    ui->xLabel->setText(QString::fromStdString(model.xValue));
    ui->yLabel->setText(QString::fromStdString(model.yValue));
    ui->zLabel->setText(QString::fromStdString(model.zValue));
}

QVector3D PointView::getPoint()
{
    float x = ui->xLabel->text().toFloat();
    float y = ui->yLabel->text().toFloat();
    float z = ui->zLabel->text().toFloat();

    return QVector3D(x, y, z);
}
