#include "Amuljot_Oct6_task3_Cube.h"
#include <iostream>

// Constructor: initializes side and sets name to "Cube"
Cube::Cube(float s) : ThreeDimensionalShape("Cube"), side(s) {}

// Calculates volume as side^3
float Cube::volume() const
{
    return side * side * side;
}

// Displays shape details
void Cube::display() const
{
    std::cout << "Shape: " << name << ", Side: " << side
              << ", Volume: " << volume() << std::endl;
}

// Returns shape type
std::string Cube::getType() const
{
    return "ThreeDimensional";
}
