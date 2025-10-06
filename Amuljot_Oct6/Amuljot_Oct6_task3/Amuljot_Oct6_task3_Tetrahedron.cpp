#include "Amuljot_Oct6_task3_Tetrahedron.h"

#include <iostream>
#include <cmath>

// Constructor: initializes edge and sets name to "Tetrahedron"
Tetrahedron::Tetrahedron(float e) : ThreeDimensionalShape("Tetrahedron"), edge(e) {}

// Calculates volume
float Tetrahedron::volume() const
{
    return (edge * edge * edge) / (6 * std::sqrt(2));
}

// Displays shape details
void Tetrahedron::display() const
{
    std::cout << "Shape: " << name << ", Edge: " << edge
              << ", Volume: " << volume() << std::endl;
}

// Returns shape type
std::string Tetrahedron::getType() const
{
    return "ThreeDimensional";
}
