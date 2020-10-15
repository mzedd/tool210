#include "camera.h"

Camera::Camera() :
    zoom(0.0f)
{

}

Point Camera::getPosition()
{
    return position;
}

Point Camera::getForwardVector()
{
    Point point(lookAt - position);
    point.normalize();

    return point;
}

Point Camera::getUpVector()
{
    return up;
}

Point Camera::getRight()
{
    Point point;
    point.x = 1.0f;

    return point;
}

float Camera::getZoom() const
{
    return zoom;
}
