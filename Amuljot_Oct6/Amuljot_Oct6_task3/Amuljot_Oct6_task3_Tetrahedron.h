#ifndef TETRAHEDRON_H
#define TETRAHEDRON_H

#include "Amuljot_Oct6_task3_ThreeDimensionalShape.h"

// class representing a Tetrahedron
class Tetrahedron : public ThreeDimensionalShape
{
private:
    float edge; // Length of one edge

public:
    // Constructor to initialize edge
    Tetrahedron(float e);

    // Calculates volume
    float volume() const override;

    // Displays shape details
    void display() const override;

    // Returns "ThreeDimensional"
    std::string getType() const override;
};

#endif