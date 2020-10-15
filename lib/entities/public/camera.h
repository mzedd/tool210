#ifndef CAMERA_H
#define CAMERA_H

#include "point.h"

class Camera
{
public:
    Camera();

private:
    Point lookAt;
    Point up;
    Point right;
};

#endif // CAMERA_H
