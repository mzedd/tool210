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
