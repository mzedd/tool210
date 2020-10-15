#ifndef POINT_H
#define POINT_H

class Point
{
public:
    Point();
    float getLength();
    void normalize();
    bool isNormalized();

    Point operator+(Point point);
    Point operator-(Point point);

    float x;
    float y;
    float z;

};

#endif // POINT_H
