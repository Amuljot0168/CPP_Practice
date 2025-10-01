#ifndef TRAPEZOID_H
#define TRAPEZOID_H

#include "Amuljot_Oct1_task3_Quadilateral.h"

class Trapezoid : public Quadrilateral
{
public:
    Trapezoid(const float s[4], const float a[4]);
    bool isValid() const override;
    float area() const override;
    std::string ShapeType() const override;
};

#endif