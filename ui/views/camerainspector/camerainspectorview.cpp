#include "camerainspectorview.h"
#include "ui_camerainspectorview.h"

CameraInspectorView::CameraInspectorView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CameraInspectorView)
{
    ui->setupUi(this);
}

CameraInspectorView::~CameraInspectorView()
{
    delete ui;
}
