#include "Amuljot_Oct6_task4_Rectangle.h"

// Constructor of Rectangle class
Rectangle::Rectangle(const float s[4], const float a[4]) : Parallelogram(s, a) {}

// Check rectangle is valid based upon angles and sides
bool Rectangle::isValid() const
{
    for (int i = 0; i < 4; ++i)
        if (angles[i] != 90)
            return false;
    return sides[0] == sides[2] && sides[1] == sides[3];
}

// return area of rectangle
float Rectangle::area() const { return sides[0] * sides[1]; }

// return shape type "Rectangle"
std::string Rectangle::ShapeType() const { return "Rectangle"; }
