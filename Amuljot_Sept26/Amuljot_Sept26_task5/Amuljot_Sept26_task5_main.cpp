#include <iostream>
#include "Amuljot_Sept26_task5_Polynomial.h"

int main()
{

    // Create polynomial of size 3 (5x^4 + 2x^3+1)
    Polynomial p1(3);
    p1.setTerm(5, 4);
    p1.setTerm(2, 3);
    p1.setTerm(1, 0);

    // Create second polynomial: x^4 + 3x^2 + 5
    Polynomial p2(3);
    p2.setTerm(1, 4); // x^4
    p2.setTerm(3, 2); // 3x^2
    p2.setTerm(5, 0); // 5

    std::cout << "Polynomial p1 = " << p1 << std::endl;
    std::cout << "Polynomial p2 = " << p2 << std::endl;

    // Addition
    Polynomial sum = p1 + p2;
    std::cout << "\np1 + p2 = " << sum << std::endl;

    // Subtraction
    Polynomial diff = p1 - p2;
    std::cout << "p1 - p2 = " << diff << std::endl;

    // Multiplication
    Polynomial prod = p1 * p2;
    std::cout << "p1 * p2 = " << prod << std::endl;

    // Assignment operators
    p1 += p2;
    std::cout << "\nAfter p1 += p2, p1 = " << p1 << std::endl;

    p1 -= p2;
    std::cout << "After p1 -= p2, p1 = " << p1 << std::endl;

    p1 *= p2;
    std::cout << "After p1 *= p2, p1 = " << p1 << std::endl;

    return 0;
}