#include "Amuljot_Oct1_task3_Trapezoid.h"

Trapezoid::Trapezoid(const float s[4], const float a[4]) : Quadrilateral(s, a) {}

bool Trapezoid::isValid() const
{
    return Quadrilateral::isValid();
}
float Trapezoid::area() const
{
    return 0.5f * (sides[0] + sides[2]) * 5;
}
std::string Trapezoid::ShapeType() const
{
    return "Trapezoid";
}
