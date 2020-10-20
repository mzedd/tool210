#ifndef CAMERAINSPECTORPRESENTER_H
#define CAMERAINSPECTORPRESENTER_H

#include "camerainspectorview.h"
#include "interactors/camerainspectoroutputboundary.h"
#include "views/view.h"

class CameraInspectorPresenter : public CameraInspectorOutputBoundary
{
public:
    CameraInspectorPresenter();

    void setView(CameraInspectorView *view);
    CameraInspectorViewModel &getViewModel();

    void present(CameraData cameraData);

private:
    PointViewModel toPointViewModel(Tool210::Entities::Point point);
    std::string formatNumericValue(float value);

    View *view;
    CameraInspectorViewModel viewModel;

};

#endif // CAMERAINSPECTORPRESENTER_H
