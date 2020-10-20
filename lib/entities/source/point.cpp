#include "point.h"
#include <cmath>
#include <limits>

namespace Tool210 {
namespace Entities {

Point::Point() :
    Point(0.0f, 0.0f, 0.0f)
{

}

Point::Point(float x, float y, float z) :
    x(x),
    y(y),
    z(z)
{

}

float Point::getLength()
{
    return sqrt(x*x + y*y + z*z);
}

void Point::normalize()
{
    float reziprocLength = 1.0f/getLength();

    x = reziprocLength * x;
    y = reziprocLength * y;
    z = reziprocLength * z;
}

bool Point::isNormalized()
{
    return std::fabs(getLength() - 1.0f) < std::numeric_limits<float>::epsilon();
}

Point Point::cross(const Point a, const Point b)
{
    return Point(a.y*b.z - a.z*b.y,
                 a.z*b.x - a.x*b.z,
                 a.x*b.y - a.y*b.x);
}

Point Point::operator+(Point point)
{
    Point resultingPoint;

    resultingPoint.x = x + point.x;
    resultingPoint.y = y + point.y;
    resultingPoint.z = z + point.z;

    return resultingPoint;
}

Point Point::operator-(Point point)
{
    Point resultingPoint;

    resultingPoint.x = x - point.x;
    resultingPoint.y = y - point.y;
    resultingPoint.z = z - point.z;

    return resultingPoint;
}

} // namespace Entities
} // namespace Tool210
