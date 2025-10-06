#include "Amuljot_Oct6_task4_Square.h"

// Constructor of Square class
Square::Square(const float s[4], const float a[4]) : Rectangle(s, a) {}

// Check is Square is valid
bool Square::isValid() const
{
    for (int i = 0; i < 4; ++i)
        if (angles[i] != 90 || sides[i] != sides[0])
            return false;
    return true;
}

// return the area of square
float Square::area() const { return sides[0] * sides[0]; }

// return shape type as "Square"
std::string Square::ShapeType() const { return "Square"; }
