#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Amuljot_Oct6_task4_Parallelogram.h"

// Represents a Rectangle shape
// Inherits from Parallelogram to reuse side and angle structure
class Rectangle : public Parallelogram
{
public:
    // Constructor:
    // Initializes a Rectangle using arrays of 4 sides and 4 angles

    Rectangle(const float s[4], const float a[4]);

    // Checks if the shape satisfies the geometric properties of a rectangle:
    bool isValid() const override;

    // Calculates the area of the rectangle:
    // Typically side[0] * side[1] if adjacent sides are known
    float area() const override;

    // Returns the string "Rectangle" to identify the shape type
    std::string ShapeType() const override;
};

#endif