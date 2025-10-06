#ifndef CIRCLE_H
#define CIRCLE_H

#include "Amuljot_Oct6_task3_TwoDimensionalShape.h"

// class  Circle
class Circle : public TwoDimensionalShape
{
private:
    float radius; // Radius of the circle

public:
    // Constructor to initialize radius
    Circle(float r);

    // Calculates area
    float area() const override;

    // Displays shape details
    void display() const override;

    // Returns "TwoDimensional"
    std::string getType() const override;
};

#endif