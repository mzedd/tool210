#ifndef CAMERA_H
#define CAMERA_H

#include "point.h"

namespace Tool210 {
namespace Entities {

class Camera
{
public:
    Camera();

    void setPosition(Point &point);
    void setLookAtPoint(Point &point);
    void setRoll(float angle);
    void setZoom(float zoom);

    Point getPosition() const;
    Point getLookAt() const;
    float getRoll() const;
    float getZoom() const;

    Point getForwardVector();
    Point getUpVector();
    Point getRightVector();

private:
    void updateTransform();

    Point position;
    Point lookAt;
    float roll;
    float zoom;

    Point forward;
    Point up;
    Point right;
};

} // namespace Entities
} // namespace Tool210

#endif // CAMERA_H
