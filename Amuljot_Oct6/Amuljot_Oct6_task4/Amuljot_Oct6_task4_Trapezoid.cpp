#include "Amuljot_Oct6_task4_Trapezoid.h"

// Constructor for Trapezoid
Trapezoid::Trapezoid(const float s[4], const float a[4]) : Quadrilateral(s, a) {}

// Check valid or not
bool Trapezoid::isValid() const
{
    return Quadrilateral::isValid();
}

// Calculate the area of Trapezoid
float Trapezoid::area() const
{
    return 0.5f * (sides[0] + sides[2]) * 5;
}

// return shape type
std::string Trapezoid::ShapeType() const
{
    return "Trapezoid";
}
