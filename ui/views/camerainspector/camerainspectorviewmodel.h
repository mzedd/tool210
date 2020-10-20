#ifndef CAMERAINSPECTORVIEWMODEL_H
#define CAMERAINSPECTORVIEWMODEL_H

#include <string>
#include "pointviewmodel.h"

class CameraInspectorViewModel
{
public:
    CameraInspectorViewModel();

    PointViewModel position;
    PointViewModel lookAt;
    std::string roll;
    std::string zoom;
};

#endif // CAMERAINSPECTORVIEWMODEL_H
