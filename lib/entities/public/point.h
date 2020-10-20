#ifndef POINT_H
#define POINT_H

namespace Tool210 {
namespace Entities {

class Point
{
public:
    Point();
    Point(float x, float y, float z);

    float getLength();
    void normalize();
    bool isNormalized();

    static Point cross(const Point a, const Point b);

    Point operator+(Point point);
    Point operator-(Point point);

    float x;
    float y;
    float z;

};

} // namespace Entities
} // namespace Tool210

#endif // POINT_H
