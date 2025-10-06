#include "Amuljot_Oct6_task3_Square.h"

// Constructor: initializes side and sets name to "Square"
Square::Square(float s) : TwoDimensionalShape("Square"), side(s) {}

// Calculates area as side²
float Square::area() const
{
    return side * side;
}

// Displays shape details
void Square::display() const
{
    std::cout << "Shape: " << name << ", Side: " << side
              << ", Area: " << area() << std::endl;
}

// Returns shape type
std::string Square::getType() const
{
    return "TwoDimensional";
}