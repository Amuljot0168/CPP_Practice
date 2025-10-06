#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Amuljot_Oct6_task3_TwoDimensionalShape.h"

//  class Triangle
class Triangle : public TwoDimensionalShape
{
private:
    float base, height; // Base and height of the triangle

public:
    // Constructor to initialize base and height
    Triangle(float b, float h);

    // Calculates area
    float area() const override;

    // Displays shape details
    void display() const override;

    // Returns "TwoDimensional"
    std::string getType() const override;
};

#endif