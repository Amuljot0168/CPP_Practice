#ifndef THREEDIMENSIONALSHAPE_H
#define THREEDIMENSIONALSHAPE_H

#include "Amuljot_Oct6_task3_Shape.h"

// Abstract class for all 3D shapes
class ThreeDimensionalShape : public Shape
{
public:
    // Constructor passes name to base Shape
    ThreeDimensionalShape(const std::string &n);

    // function to calculate volume
    virtual float volume() const = 0;
};

#endif