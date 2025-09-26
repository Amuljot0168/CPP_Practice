#ifndef RATIONALNUMBER_H
#define RATIONALNUMBER_H

#include <iostream>
class RationalNumber
{
    friend std::ostream &operator<<(std::ostream &, const RationalNumber &);

private:
    int numerator;
    int denominator;

    void reduce();         // Reduce the fraction
    int gcd(int a, int b); // Find the Greater Common divisor

public:
    RationalNumber(int = 0, int = 1); // Default and Parameterised Constructor

    // Arithmetic operators
    RationalNumber operator+(const RationalNumber &) const;
    RationalNumber operator-(const RationalNumber &) const;
    RationalNumber operator*(const RationalNumber &) const;
    RationalNumber operator/(const RationalNumber &) const;

    // Releational Operators

    bool operator==(const RationalNumber &) const;
    bool operator!=(const RationalNumber &) const;
    bool operator<(const RationalNumber &) const;
    bool operator<=(const RationalNumber &) const;
    bool operator>(const RationalNumber &) const;
    bool operator>=(const RationalNumber &) const;
};
#endif