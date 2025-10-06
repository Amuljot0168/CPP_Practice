#ifndef SPHERE_H
#define SPHERE_H

#include "Amuljot_Oct6_task3_ThreeDimensionalShape.h"

//  class Sphere
class Sphere : public ThreeDimensionalShape
{
private:
    float radius; // Radius of the sphere

public:
    // Constructor to initialize radius
    Sphere(float r);

    // Calculates volume
    float volume() const override;

    // Displays shape details
    void display() const override;

    // Returns "ThreeDimensional"
    std::string getType() const override;
};

#endif