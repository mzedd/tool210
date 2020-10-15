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
    return right;
}

float Camera::getZoom() const
{
    return zoom;
}
