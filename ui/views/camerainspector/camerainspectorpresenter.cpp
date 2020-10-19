#include "camerainspectorpresenter.h"

#include <string>

CameraInspectorPresenter::CameraInspectorPresenter() :
    view(nullptr)
{

}

void CameraInspectorPresenter::setView(CameraInspectorView *view)
{
    this->view = view;
}

CameraInspectorViewModel &CameraInspectorPresenter::getViewModel()
{
    return viewModel;
}

void CameraInspectorPresenter::present(CameraData cameraData)
{
    viewModel.position = toPointViewModel(cameraData.position);
    viewModel.lookAt = toPointViewModel(cameraData.lookAt);
    viewModel.up = toPointViewModel(cameraData.up);
    viewModel.zoom = std::to_string(cameraData.zoom);

    view->update();
}

PointViewModel CameraInspectorPresenter::toPointViewModel(Tool210::Entities::Point point)
{
    PointViewModel pointViewModel;

    pointViewModel.xValue = std::to_string(point.x);
    pointViewModel.yValue = std::to_string(point.y);
    pointViewModel.zValue = std::to_string(point.z);

    return pointViewModel;
}
