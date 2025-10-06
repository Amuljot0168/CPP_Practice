#ifndef SQUARE_H
#define SQUARE_H

#include "Amuljot_Oct6_task3_TwoDimensionalShape.h"

// Class Square
class Square : public TwoDimensionalShape
{
private:
    float side; // Length of one side

public:
    // Constructor to initialize side
    Square(float s);

    // Calculates area
    float area() const override;

    // Displays shape details
    void display() const override;

    // Returns "TwoDimensional"
    std::string getType() const override;
};

#endif