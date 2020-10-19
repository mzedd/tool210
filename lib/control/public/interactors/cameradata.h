#ifndef CAMERADATA_H
#define CAMERADATA_H

#include "point.h"

class CameraData
{
public:
    CameraData();

    Tool210::Entities::Point position;
    Tool210::Entities::Point lookAt;
    Tool210::Entities::Point up;
    float zoom;
};

#endif // CAMERADATA_H
