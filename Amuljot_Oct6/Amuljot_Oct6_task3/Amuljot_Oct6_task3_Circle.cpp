#include "Amuljot_Oct6_task3_Circle.h"
#include <iostream>
#include <cmath>

// Constructor: initializes radius and sets name to "Circle"
Circle::Circle(float r) : TwoDimensionalShape("Circle"), radius(r) {}

// Calculates area using πr²
float Circle::area() const
{
    return M_PI * radius * radius;
}

// Displays shape details
void Circle::display() const
{
    std::cout << "Shape: " << name << ", Radius: " << radius
              << ", Area: " << area() << std::endl;
}

// Returns shape type
std::string Circle::getType() const
{
    return "TwoDimensional";
}
