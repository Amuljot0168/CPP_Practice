#include <iostream>
#include "Amuljot_Oct1_task3_Quadilateral.h"
#include "Amuljot_Oct1_task3_Trapezoid.h"
#include "Amuljot_Oct1_task3_Parallelogram.h"
#include "Amuljot_Oct1_task3_Rectangle.h"
#include "Amuljot_Oct1_task3_Square.h"

int main()
{
    // Task 1: Create one object of each class
    float s1[4] = {5, 5, 5, 5};
    float a1[4] = {90, 90, 90, 90};
    Square sq(s1, a1);

    float s2[4] = {6, 4, 6, 4};
    float a2[4] = {90, 90, 90, 90};
    Rectangle rect(s2, a2);

    float s3[4] = {6, 4, 6, 4};
    float a3[4] = {110, 70, 110, 70};
    Parallelogram para(s3, a3);

    float s4[4] = {6, 5, 4, 3};
    float a4[4] = {100, 80, 100, 80};
    Trapezoid trap(s4, a4);

    float s5[4] = {3, 4, 5, 6};
    float a5[4] = {90, 90, 90, 90};
    Quadrilateral quad(s5, a5);

    // Task 2: Store in Quadrilateral* array and demonstrate polymorphism
    Quadrilateral *shapes[5] = {&sq, &rect, &para, &trap, &quad};

    std::cout << "Geometry Toolkit Diagnostics\n\n";

    // Task 3: Call isValid() and area() for each
    for (int i = 0; i < 5; ++i)
    {
        std::cout << *shapes[i]; // Task 4: Use << to print details
        std::cout << "Valid: " << (shapes[i]->isValid() ? "Yes" : "No") << "\n";
        std::cout << "Area: " << float(*shapes[i]) << "\n";     // Task 6: float() to area
        std::cout << "Perimeter: " << (*shapes[i])() << "\n\n"; // Task 7: () to perimeter
    }

    // Task 5: Compare area of Rectangle and Square
    std::cout << "Rectangle vs Square Area Comparison:\n";
    std::cout << "Rectangle Area: " << float(rect) << "\n";
    std::cout << "Square Area: " << float(sq) << "\n";
    std::cout << "Are areas equal? " << ((rect == sq) ? "Yes" : "No") << "\n";

    return 0;
}