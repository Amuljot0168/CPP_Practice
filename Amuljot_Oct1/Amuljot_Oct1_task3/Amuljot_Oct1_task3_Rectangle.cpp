#include "Amuljot_Oct1_task3_Rectangle.h"

Rectangle::Rectangle(const float s[4], const float a[4]) : Parallelogram(s, a) {}
bool Rectangle::isValid() const
{
    for (int i = 0; i < 4; ++i)
        if (angles[i] != 90)
            return false;
    return sides[0] == sides[2] && sides[1] == sides[3];
}
float Rectangle::area() const { return sides[0] * sides[1]; }
std::string Rectangle::ShapeType() const { return "Rectangle"; }
