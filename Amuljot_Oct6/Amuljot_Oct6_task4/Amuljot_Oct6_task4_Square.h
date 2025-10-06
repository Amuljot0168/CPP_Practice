#ifndef SQUARE_H
#define SQUARE_H

#include "Amuljot_Oct6_task4_Rectangle.h"

// Represents a Square shape
// Inherits from Rectangle
class Square : public Rectangle
{
public:
    // Constructor:
    Square(const float s[4], const float a[4]);

    // Checks if the shape is square:
    bool isValid() const override;

    // Calculates the area of the square:

    float area() const override;

    // Returns the string "Square" to identify the shape type
    std::string ShapeType() const override;
};

#endif