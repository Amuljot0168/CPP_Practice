#ifndef CUBE_H
#define CUBE_H

#include "Amuljot_Oct6_task3_ThreeDimensionalShape.h"

// class  Cube
class Cube : public ThreeDimensionalShape
{
private:
    float side; // Length of one edge

public:
    // Constructor to initialize side
    Cube(float s);

    // Calculates volume
    float volume() const override;

    // Displays shape details
    void display() const override;

    // Returns "ThreeDimensional"
    std::string getType() const override;
};

#endif