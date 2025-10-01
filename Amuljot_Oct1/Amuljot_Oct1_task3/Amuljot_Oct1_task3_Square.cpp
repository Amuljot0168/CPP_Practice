#include "Amuljot_Oct1_task3_Square.h"

Square::Square(const float s[4], const float a[4]) : Rectangle(s, a) {}
bool Square::isValid() const
{
    for (int i = 0; i < 4; ++i)
        if (angles[i] != 90 || sides[i] != sides[0])
            return false;
    return true;
}
float Square::area() const { return sides[0] * sides[0]; }
std::string Square::ShapeType() const { return "Square"; }
