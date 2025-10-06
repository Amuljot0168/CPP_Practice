#include "Amuljot_Oct6_task3_Triangle.h"
#include <iostream>

// Constructor: initializes base and height, sets name to "Triangle"
Triangle::Triangle(float b, float h) : TwoDimensionalShape("Triangle"), base(b), height(h) {}

// Calculates area as 1/2 × base × height
float Triangle::area() const
{
    return 0.5f * base * height;
}

// Displays shape details
void Triangle::display() const
{
    std::cout << "Shape: " << name << ", Base: " << base
              << ", Height: " << height << ", Area: " << area() << std::endl;
}

// Returns shape type
std::string Triangle::getType() const
{
    return "TwoDimensional";
}
