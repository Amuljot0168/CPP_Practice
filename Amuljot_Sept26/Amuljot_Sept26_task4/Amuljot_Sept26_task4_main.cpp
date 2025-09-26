#include <iostream>
#include "Amuljot_Sept26_task4_RationalNumber.h"

int main()
{
    RationalNumber rationalNumber1(4, 6); // simplifies to 2/3
    RationalNumber rationalNumber2(3, 4);

    std::cout << "rationalNumber1 = " << rationalNumber1 << "\nr2 = " << rationalNumber2 << "\n\n";

    // Using all arithmetic operators
    std::cout << "rationalNumber1 + rationalNumber2 = " << (rationalNumber1 + rationalNumber2) << std::endl; // Addition
    std::cout << "rationalNumber1 - rationalNumber2 = " << (rationalNumber1 - rationalNumber2) << std::endl; // Subtraction
    std::cout << "rationalNumber1 * rationalNumber2 = " << (rationalNumber1 * rationalNumber2) << std::endl; // Multiplication
    std::cout << "rationalNumber1 / rationalNumber2 = " << (rationalNumber1 / rationalNumber2) << std::endl; // Division

    // Comparisons
    std::cout << "\nRelational comparisons:\n";
    std::cout << "rationalNumber1 == rationalNumber2: " << ((rationalNumber1 == rationalNumber2) ? "True" : "False") << std::endl; // return true when both numbers are equal and false when not equal
    std::cout << "rationalNumber1 != rationalNumber2: " << ((rationalNumber1 != rationalNumber2) ? "True" : "False") << std::endl; // return true when both numbers are not equal and false when  equal
    std::cout << "rationalNumber1 < rationalNumber2: " << ((rationalNumber1 < rationalNumber2) ? "True" : "False") << std::endl;   // return true when rational number1 is smaller than rational number 2
    std::cout << "rationalNumber1 <= rationalNumber2: " << ((rationalNumber1 <= rationalNumber2) ? "True" : "False") << std::endl; // return true when rational number1 is smaller or equal than rational number 2
    std::cout << "rationalNumber1 > rationalNumber2: " << ((rationalNumber1 > rationalNumber2) ? "True" : "False") << std::endl;   // return true when rational number1 is greater than rational number 2
    std::cout << "rationalNumber1 >= rationalNumber2: " << ((rationalNumber1 >= rationalNumber2) ? "True" : "False") << std::endl; // return true when rational number1 is greater or equal than rational number 2

    return 0;
}