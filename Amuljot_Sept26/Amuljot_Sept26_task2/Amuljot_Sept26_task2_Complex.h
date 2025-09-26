#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
class Complex
{
    // Output and input operators
    friend std::ostream &operator<<(std::ostream &, const Complex &);
    friend std::istream &operator>>(std::istream &, Complex &);

public:
    Complex(double = 0.0, double = 0.0); // constructor

    Complex operator+(const Complex &) const; // addition

    Complex operator-(const Complex &) const; // subtraction

    Complex operator*(const Complex &) const; // multilpication

    bool operator==(const Complex &) const; // Comparison
    bool operator!=(const Complex &) const;

private:
    double real; // real part

    double imaginary; // imaginary part
}; // end class Compl

#endif