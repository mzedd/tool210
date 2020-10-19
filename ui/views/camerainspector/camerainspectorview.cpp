#include "camerainspectorview.h"
#include "ui_camerainspectorview.h"

CameraInspectorView::CameraInspectorView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CameraInspectorView),
    viewModel(nullptr),
    inputBoundary(nullptr)
{
    ui->setupUi(this);
}

CameraInspectorView::~CameraInspectorView()
{
    delete ui;
}

void CameraInspectorView::setViewModel(CameraInspectorViewModel *viewModel)
{
    this->viewModel = viewModel;
    update();
}

void CameraInspectorView::setInputBoundary(CameraInspectorInputBoundary *inputBoundary)
{
    this->inputBoundary = inputBoundary;
}

Tool210::Entities::Point CameraInspectorView::fromQVector3D(QVector3D vector)
{
    return Tool210::Entities::Point(vector.x(), vector.y(), vector.z());
}

void CameraInspectorView::editingFinished()
{
    CameraData cameraData;

    cameraData.position = fromQVector3D(ui->positionWidget->getPoint());
    cameraData.lookAt = fromQVector3D(ui->lookAtWidget->getPoint());
    cameraData.up = fromQVector3D(ui->upWidget->getPoint());
    cameraData.zoom = ui->zoomLineEdit->text().toFloat();

    inputBoundary->setData(cameraData);
}

void CameraInspectorView::update()
{
    ui->positionWidget->updateView(viewModel->position);
    ui->lookAtWidget->updateView(viewModel->lookAt);
    ui->upWidget->updateView(viewModel->up);

    ui->zoomLineEdit->setText(QString::fromStdString(viewModel->zoom));

    QWidget::update();
}
