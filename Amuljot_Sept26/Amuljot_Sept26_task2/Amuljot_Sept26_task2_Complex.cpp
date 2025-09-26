#include <iostream>
#include "Amuljot_Sept26_task2_Complex.h"

// Parameterised Constructor
Complex::Complex(double realPart, double imaginaryPart) : real(realPart), imaginary(imaginaryPart) {}

// Overloading operator + (Addition) for complex number
Complex Complex::operator+(const Complex &operand2) const
{
    return Complex(real + operand2.real, imaginary + operand2.imaginary);
}

// Overloading operator - (Subtraction) for complex number
Complex Complex::operator-(const Complex &operand2) const
{
    return Complex(real - operand2.real, imaginary - operand2.imaginary);
}

// Overloading operator * (Multiplication) for complex number
Complex Complex::operator*(const Complex &operand2) const
{
    double real_value = (real * operand2.real) - (imaginary * operand2.imaginary);
    double imaginary_value = (real * operand2.imaginary) + (imaginary * operand2.real);

    return Complex(real_value, imaginary_value);
}

// Overloading operator == for comparing complex number
bool Complex::operator==(const Complex &other) const
{
    if (real == other.real && imaginary == other.imaginary)
    {
        return true;
    }
    return false;
}

// Overloading operator != for comparing complex number
bool Complex::operator!=(const Complex &other) const
{
    if (*this == other)
    {
        return false;
    }
    return true;
}

// Overloading operator << for output of complex number
std::ostream &operator<<(std::ostream &out, const Complex &c)
{
    out << "(" << c.real << ", " << c.imaginary << ")";
    return out;
}

// Overloading operator >> for inputing complex number
std::istream &operator>>(std::istream &in, Complex &c)
{
    std::cout << "Enter the real part: ";
    in >> c.real;
    std::cout << "Enter the imaginary part: ";
    in >> c.imaginary;
    return in;
}
