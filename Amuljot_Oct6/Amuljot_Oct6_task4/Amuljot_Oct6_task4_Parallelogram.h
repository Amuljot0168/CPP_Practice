#ifndef PARALLELOGRAM_H
#define PARALLELOGRAM_H

#include "Amuljot_Oct6_task4_Trapezoid.h"

// Derived class representing a Parallelogram shape
// Inherits from Trapezoid to reuse side and angle structure
class Parallelogram : public Trapezoid
{
public:
    // Constructor:
    // Initializes a Parallelogram using arrays of 4 sides and 4 angles
    Parallelogram(const float s[4], const float a[4]);

    // Checks if the shape satisfies the geometric properties of a parallelogram
    bool isValid() const override;

    // Calculates the area of the parallelogram
    float area() const override;

    // Returns the string "Parallelogram" to identify the shape type
    std::string ShapeType() const override;
};

#endif