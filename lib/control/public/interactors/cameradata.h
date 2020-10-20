#ifndef CAMERADATA_H
#define CAMERADATA_H

#include "point.h"

class CameraData
{
public:
    CameraData();

    Tool210::Entities::Point position;
    Tool210::Entities::Point lookAt;
    float roll;
    float zoom;
};

#endif // CAMERADATA_H
