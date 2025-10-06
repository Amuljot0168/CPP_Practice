#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <string>

// Base Class Shape
class Shape
{
protected:
    std::string name; // Name of the shape

public:
    // Constructor to initialize shape name
    Shape(const std::string &name);

    // Virtual destructor
    virtual ~Shape();

    // Pure virtual function to display shape details
    virtual void display() const = 0;

    // Pure virtual function to return shape type
    virtual std::string getType() const = 0;
};

#endif