#include "camera.h"

namespace Tool210 {
namespace Entities {

Camera::Camera() :
    position(Point()),
    lookAt(Point(1.0f, 0.0f, 0.0f)),
    roll(0.0f),
    zoom(1.0f)
{
    updateTransform();
}

void Camera::setPosition(Point &point)
{
    this->position = point;
    updateTransform();
}

void Camera::setLookAtPoint(Point &point)
{
    this->lookAt = point;
    updateTransform();
}

void Camera::setRoll(float angle)
{
    this->roll = angle;
    updateTransform();
}

void Camera::setZoom(float zoom)
{
    this->zoom = zoom;
    updateTransform();
}

Point Camera::getPosition() const
{
    return position;
}

Point Camera::getLookAt() const
{
    return lookAt;
}

float Camera::getRoll() const
{
    return roll;
}

float Camera::getZoom() const
{
    return zoom;
}

Point Camera::getForwardVector()
{
    return forward;
}

Point Camera::getUpVector()
{
    return up;
}

Point Camera::getRightVector()
{
    return right;
}

void Camera::updateTransform()
{
    forward = lookAt - position;
    forward.normalize();

    right = Point::cross(forward, Point(0.0f, 1.0f, 0.0f));

    up = Point::cross(right, forward);
}

} // namespace Entities
} // namespace Tool210
