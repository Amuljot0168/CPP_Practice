#ifndef TRAPEZOID_H
#define TRAPEZOID_H

#include "Amuljot_Oct6_task4_Quadilateral.h"

// Represents a Trapezoid shape
// Inherits from Quadrilateral
class Trapezoid : public Quadrilateral
{
public:
    // Constructor:
    Trapezoid(const float s[4], const float a[4]);

    // Checks if the shape is trapezoid
    bool isValid() const override;

    // Calculates the area of the trapezoid:
    float area() const override;

    // Returns the string "Trapezoid" to identify the shape type
    std::string ShapeType() const override;
};

#endif