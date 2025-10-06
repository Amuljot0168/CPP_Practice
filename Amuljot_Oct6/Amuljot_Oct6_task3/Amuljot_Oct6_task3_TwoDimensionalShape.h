#ifndef TWODIMENSIONALSHAPE_H
#define TWODIMENSIONALSHAPE_H

#include "Amuljot_Oct6_task3_Shape.h"

//  base class for all 2D shapes inheriting Shape class
class TwoDimensionalShape : public Shape
{
public:
    // Constructor passes name to base Shape
    TwoDimensionalShape(const std::string &n);

    // function to calculate area
    virtual float area() const = 0;
};

#endif