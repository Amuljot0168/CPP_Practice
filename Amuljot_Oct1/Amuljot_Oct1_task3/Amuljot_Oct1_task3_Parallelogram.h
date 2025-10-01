#ifndef PARALLELOGRAM_H
#define PARALLELOGRAM_H

#include "Amuljot_Oct1_task3_Trapezoid.h"

class Parallelogram : public Trapezoid
{
public:
    Parallelogram(const float s[4], const float a[4]);
    bool isValid() const override;
    float area() const override;
    std::string ShapeType() const override;
};

#endif