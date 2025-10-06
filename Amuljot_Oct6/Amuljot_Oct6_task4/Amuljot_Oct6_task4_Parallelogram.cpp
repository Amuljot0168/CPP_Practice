#include "Amuljot_Oct6_task4_Parallelogram.h"
#include <cmath>

// Constructor of parallelogram
Parallelogram::Parallelogram(const float s[4], const float a[4]) : Trapezoid(s, a) {}

// Check if prarllelogram is valid
bool Parallelogram::isValid() const { return sides[0] == sides[2] && sides[1] == sides[3]; }

// calculate and return the area of parallelogram
float Parallelogram::area() const { return sides[0] * sides[1] * std::sin(angles[0] * M_PI / 180); }

// return type of shape
std::string Parallelogram::ShapeType() const { return "Parallelogram"; }
