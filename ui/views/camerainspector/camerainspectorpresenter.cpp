#include "camerainspectorpresenter.h"

#include <string>
#include <sstream>

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
    viewModel.roll = formatNumericValue(cameraData.roll);
    viewModel.zoom = formatNumericValue(cameraData.zoom);

    view->update();
}

PointViewModel CameraInspectorPresenter::toPointViewModel(Tool210::Entities::Point point)
{
    PointViewModel pointViewModel;

    pointViewModel.xValue = formatNumericValue(point.x);
    pointViewModel.yValue = formatNumericValue(point.y);
    pointViewModel.zValue = formatNumericValue(point.z);

    return pointViewModel;
}

std::string CameraInspectorPresenter::formatNumericValue(float value)
{
    std::stringstream stream;
    stream << value;
    return  stream.str();
}
