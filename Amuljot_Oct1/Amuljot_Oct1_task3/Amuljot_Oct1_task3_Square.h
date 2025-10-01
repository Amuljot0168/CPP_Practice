#ifndef SQUARE_H
#define SQUARE_H

#include "Amuljot_Oct1_task3_Rectangle.h"

class Square : public Rectangle
{
public:
    Square(const float s[4], const float a[4]);
    bool isValid() const override;
    float area() const override;
    std::string ShapeType() const override;
};

#endif