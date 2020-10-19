#include "camera.h"

namespace Tool210 {
namespace Entities {

Camera::Camera() :
    zoom(0.0f)
{

}

void Camera::setLookAtPoint(Point &point)
{
    this->lookAt = point;
}

void Camera::setUpVector(Point &point)
{
    this->up = point;
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

} // namespace Entities
} // namespace Tool210
