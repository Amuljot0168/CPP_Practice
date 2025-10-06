#include "Amuljot_Oct6_task4_Quadilateral.h"
#include <cmath>

// Base class constructor
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

// Copy Constructor
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

// Destructor
Quadrilateral::~Quadrilateral()
{
    delete[] sides;
    delete[] angles;
}

// Overloading operator
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

// Function to check quadilateral is valid or not
bool Quadrilateral::isValid() const
{
    float sum = 0;
    for (int i = 0; i < 4; ++i)
        sum += angles[i];
    return sum == 360;
}

// Function to find area as deafault value return 0
float Quadrilateral::area() const
{
    return 0;
}

// return shape type
std::string Quadrilateral::ShapeType() const
{
    return "Quadrilateral";
}

// Overloading () operator returns sum of all sides
float Quadrilateral::operator()() const
{
    return sides[0] + sides[1] + sides[2] + sides[3];
}

// Overloading float() to return area
Quadrilateral::operator float() const
{
    return area();
}

// check if both objects are equal based upon areas
bool Quadrilateral::operator==(const Quadrilateral &other) const
{
    return std::fabs(area() - other.area()) < 0.01;
}

// Overloading << operator for output
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
