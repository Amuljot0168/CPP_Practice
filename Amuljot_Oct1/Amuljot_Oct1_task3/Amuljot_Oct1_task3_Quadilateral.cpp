#include "Amuljot_Oct1_task3_Quadilateral.h"
#include <cmath>
// Base class
Quadrilateral::Quadrilateral(const float s[4], const float a[4])
{
    sides = new float[4];
    angles = new float[4];
    for (int i = 0; i < 4; ++i)
    {
        sides[i] = s[i];
        angles[i] = a[i];
    }
}

Quadrilateral::Quadrilateral(const Quadrilateral &other)
{
    sides = new float[4];
    angles = new float[4];
    for (int i = 0; i < 4; ++i)
    {
        sides[i] = other.sides[i];
        angles[i] = other.angles[i];
    }
}

Quadrilateral::~Quadrilateral()
{
    delete[] sides;
    delete[] angles;
}

Quadrilateral &Quadrilateral::operator=(const Quadrilateral &other)
{
    if (this != &other)
    {
        delete[] sides;
        delete[] angles;
        sides = new float[4];
        angles = new float[4];
        for (int i = 0; i < 4; ++i)
        {
            sides[i] = other.sides[i];
            angles[i] = other.angles[i];
        }
    }
    return *this;
}

bool Quadrilateral::isValid() const
{
    float sum = 0;
    for (int i = 0; i < 4; ++i)
        sum += angles[i];
    return sum == 360;
}

float Quadrilateral::area() const
{
    return 0;
}

std::string Quadrilateral::ShapeType() const
{
    return "Quadrilateral";
}

float Quadrilateral::operator()() const
{
    return sides[0] + sides[1] + sides[2] + sides[3];
}

Quadrilateral::operator float() const
{
    return area();
}

bool Quadrilateral::operator==(const Quadrilateral &other) const
{
    return std::fabs(area() - other.area()) < 0.01;
}

std::ostream &operator<<(std::ostream &out, const Quadrilateral &q)
{
    out << q.ShapeType() << ":\nSides: ";
    for (int i = 0; i < 4; ++i)
        out << q.sides[i] << " ";
    out << "\nAngles: ";
    for (int i = 0; i < 4; ++i)
        out << q.angles[i] << " ";
    out << "\nArea: " << float(q) << "\nPerimeter: " << q() << "\n";
    return out;
}
