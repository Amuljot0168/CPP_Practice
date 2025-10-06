#include <iostream>
#include "Amuljot_Oct6_task3_Circle.h"
#include "Amuljot_Oct6_task3_Cube.h"
#include "Amuljot_Oct6_task3_Triangle.h"
#include "Amuljot_Oct6_task3_Sphere.h"
#include "Amuljot_Oct6_task3_Square.h"
#include "Amuljot_Oct6_task3_Tetrahedron.h"

int main()
{
    // Create an array of Shape pointers
    Shape *shapes[] = {
        new Circle(5.0f),         // Radius = 5
        new Square(4.0f),         // Side = 4
        new Triangle(6.0f, 3.0f), // Base = 6, Height = 3
        new Sphere(3.0f),         // Radius = 3
        new Cube(2.0f),           // Side = 2
        new Tetrahedron(4.0f)     // Edge = 4
    };

    std::cout << "Shape Details: \n\n";
    for (Shape *shape : shapes)
    {
        shape->display();
        std::cout << "Type: " << shape->getType() << "\n\n";
    }

    //  Clean up dynamically allocated memory
    for (Shape *shape : shapes)
    {
        delete shape;
    }

    return 0;
}