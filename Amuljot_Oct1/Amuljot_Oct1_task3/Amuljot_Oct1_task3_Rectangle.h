#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Amuljot_Oct1_task3_Parallelogram.h"

class Rectangle : public Parallelogram
{
public:
    Rectangle(const float s[4], const float a[4]);
    bool isValid() const override;
    float area() const override;
    std::string ShapeType() const override;
};

#endif