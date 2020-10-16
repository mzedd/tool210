#include "point.h"
#include <cmath>
#include <limits>

namespace Tool210 {
namespace Entities {

Point::Point() :
    x(0.0f),
    y(0.0f),
    z(0.0f)
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
