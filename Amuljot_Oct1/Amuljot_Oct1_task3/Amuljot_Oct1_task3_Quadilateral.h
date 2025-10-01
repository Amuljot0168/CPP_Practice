#ifndef QUADILATERAL_H
#define QUADILATERAL_H
#include <iostream>
#include <string>
class Quadrilateral
{
protected:
    float *sides;
    float *angles;

public:
    Quadrilateral(const float s[4], const float a[4]);
    Quadrilateral(const Quadrilateral &other);
    virtual ~Quadrilateral();
    Quadrilateral &operator=(const Quadrilateral &other);

    virtual bool isValid() const;
    virtual float area() const;
    virtual std::string ShapeType() const;

    float operator()() const; // perimeter
    operator float() const;   // area
    bool operator==(const Quadrilateral &other) const;
    friend std::ostream &operator<<(std::ostream &out, const Quadrilateral &q);
};

#endif