#ifndef CAMERA_H
#define CAMERA_H

#include "point.h"

class Camera
{
public:
    Camera();

    void setLookAtPoint(Point &point);
    void setUpVector(Point &point);

    Point getPosition();
    Point getForwardVector();
    Point getUpVector();
    Point getRight();

    float getZoom() const;

public:
    Point position;
    Point lookAt;
    Point up;
    Point right;

    float zoom;
};

#endif // CAMERA_H
