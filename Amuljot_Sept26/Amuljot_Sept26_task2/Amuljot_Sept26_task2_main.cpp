#include <iostream>
#include "Amuljot_Sept26_task2_Complex.h"
using namespace std;

int main()
{
    Complex complex1;             // Default constructor (0, 0)
    Complex complex2(40.0, 50.0); // real = 40.0, imaginary = 10.0
    Complex complex3(20.0, 30.0); // real = 20.0, imaginary = 30.0

    // Printing the complex number with the help of '<<' operator
    std::cout << "Initial values:\n";
    std::cout << "complex1: " << complex1 << endl;
    std::cout << "complex2: " << complex2 << endl;
    std::cout << "complex3: " << complex3 << endl;

    // Input new value for complex1
    std::cout << "\nEnter a new complex number for complex1:\n";
    std::cin >> complex1;
    std::cout << "You entered: " << complex1 << endl;

    // Addition
    Complex sum = complex2 + complex3; // Using '+' operator for adding complex number
    std::cout << "\ncomplex2 + complex3 = " << sum << endl;

    // Subtraction
    Complex diff = complex2 - complex3; // Using '-' operator for subtracting complex number
    std::cout << "complex2 - complex3 = " << diff << endl;

    // Multiplication
    Complex product = complex2 * complex3; // Using '*' operator for multiplying complex number
    std::cout << "complex2 * complex3 = " << product << endl;

    // Comparison
    if (complex2 == complex3)
        std::cout << "\ncomplex2 and complex3 are equal.\n";
    else
        std::cout << "\ncomplex2 and complex3 are not equal.\n";

    if (complex1 != complex2)
        std::cout << "complex1 and complex2 are different.\n";

    return 0;
}