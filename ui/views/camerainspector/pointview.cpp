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
    ui->xLineEdit->setText(QString::fromStdString(model.xValue));
    ui->yLineEdit->setText(QString::fromStdString(model.yValue));
    ui->zLineEdit->setText(QString::fromStdString(model.zValue));
}

QVector3D PointView::getPoint()
{
    float x = ui->xLineEdit->text().toFloat();
    float y = ui->yLineEdit->text().toFloat();
    float z = ui->zLineEdit->text().toFloat();

    return QVector3D(x, y, z);
}

void PointView::editingFinished()
{
    emit editFinished();
}
