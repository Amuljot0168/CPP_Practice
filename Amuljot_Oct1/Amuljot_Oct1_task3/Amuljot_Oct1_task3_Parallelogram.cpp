#include "Amuljot_Oct1_task3_Parallelogram.h"
#include <cmath>

Parallelogram::Parallelogram(const float s[4], const float a[4]) : Trapezoid(s, a) {}
bool Parallelogram::isValid() const { return sides[0] == sides[2] && sides[1] == sides[3]; }
float Parallelogram::area() const { return sides[0] * sides[1] * std::sin(angles[0] * M_PI / 180); }
std::string Parallelogram::ShapeType() const { return "Parallelogram"; }
