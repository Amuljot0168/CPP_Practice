#include "Amuljot_Oct6_task3_Sphere.h"
#include <iostream>
#include <cmath>

// Constructor: initializes radius and sets name to "Sphere"
Sphere::Sphere(float r) : ThreeDimensionalShape("Sphere"), radius(r) {}

// Calculates volume using 4/3(pi)r^3
float Sphere::volume() const
{
    return (4.0f / 3.0f) * M_PI * radius * radius * radius;
}

// Displays shape details
void Sphere::display() const
{
    std::cout << "Shape: " << name << ", Radius: " << radius
              << ", Volume: " << volume() << std::endl;
}

// Returns shape type
std::string Sphere::getType() const
{
    return "ThreeDimensional";
}
