#ifndef QUADILATERAL_H
#define QUADILATERAL_H

#include <iostream>
#include <string>

// Base class representing a generic quadrilateral shape
class Quadrilateral
{
protected:
    float *sides;  // Array of 4 side lengths
    float *angles; // Array of 4 internal angles (in degrees)

public:
    // Constructor: initializes sides and angles from input arrays
    Quadrilateral(const float s[4], const float a[4]);

    // Copy constructor: performs deep copy of sides and angles
    Quadrilateral(const Quadrilateral &other);

    // Virtual destructor: cleans up dynamically allocated memory
    virtual ~Quadrilateral();

    // Copy assignment operator: ensures deep copy and self-assignment safety
    Quadrilateral &operator=(const Quadrilateral &other);

    // Checks if the quadrilateral is geometrically valid
    // Can be overridden by derived shapes (e.g., square, trapezoid)
    virtual bool isValid() const;

    // Calculates the area of the quadrilateral
    virtual float area() const;

    // Returns the shape type as a string
    virtual std::string ShapeType() const;

    // Function-call operator: returns perimeter of the quadrilateral
    float operator()() const;

    // Type-cast operator: allows implicit conversion to float (returns area)
    operator float() const;

    // Equality operator: compares sides and angles for geometric equivalence
    bool operator==(const Quadrilateral &other) const;

    // Stream insertion operator: prints shape details to output stream
    friend std::ostream &operator<<(std::ostream &out, const Quadrilateral &q);
};

#endif