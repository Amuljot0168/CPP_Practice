#include <iostream>
#include "Amuljot_Sept26_task4_RationalNumber.h"

// Constructor
RationalNumber::RationalNumber(int num, int denum)
{
    if (denum == 0)
    {
        throw std::invalid_argument("Error: Denonminator cannot be zero!\n");
    }

    numerator = num;
    denominator = denum;
    reduce();
}

// Helper Function to find gcd which helps in reduce function
int RationalNumber::gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

// Function to reduce the fraction of rational Number
void RationalNumber::reduce()
{
    int divisor = gcd(abs(numerator), abs(denominator));
    numerator /= divisor;
    denominator /= divisor;
}

// Overloading + operator to add rational Numbers
RationalNumber RationalNumber::operator+(const RationalNumber &operand2) const
{
    int num = (numerator * operand2.denominator) + (operand2.numerator * denominator);
    int denum = denominator * operand2.denominator;

    return RationalNumber(num, denum);
}

// Overloading - operator to subtract rational Numbers
RationalNumber RationalNumber::operator-(const RationalNumber &operand2) const
{
    int num = (numerator * operand2.denominator) - (operand2.numerator * denominator);
    int denum = denominator * operand2.denominator;

    return RationalNumber(num, denum);
}

// Overloading * operator to multiply rational Numbers
RationalNumber RationalNumber::operator*(const RationalNumber &operand2) const
{
    int num = numerator * operand2.numerator;
    int denum = denominator * operand2.denominator;

    return RationalNumber(num, denum);
}

// Overloading / operator to divide rational Numbers
RationalNumber RationalNumber::operator/(const RationalNumber &other) const
{
    if (other.numerator == 0)
    {
        throw std::invalid_argument("Error: Division by zero.\n");
        exit(1);
    }

    int num = numerator * other.denominator;
    int denum = denominator * other.numerator;
    return RationalNumber(num, denum);
}

// Overloading == operator to compare rational Numbers
bool RationalNumber::operator==(const RationalNumber &other) const
{
    if (numerator == other.numerator && denominator == other.denominator)
    {
        return true; // both numerator and denominator are equal
    }
    else
    {
        return false; // either numerator or denominator is different
    }
}

// Overloading != operator to compare rational Numbers
bool RationalNumber::operator!=(const RationalNumber &other) const
{
    if (*this == other)
    {
        return false; // they are equal, so not unequal
    }
    else
    {
        return true; // they are different
    }
}

// Overloading < operator to compare rational Numbers
bool RationalNumber::operator<(const RationalNumber &other) const
{
    if (numerator * other.denominator < other.numerator * denominator)
    {
        return true; // this is less than other
    }
    else
    {
        return false; // this is not less than other
    }
}

// Overloading <= operator to compare rational Numbers
bool RationalNumber::operator<=(const RationalNumber &other) const
{
    if (*this < other || *this == other)
    {
        return true; // this is less than or equal to other
    }
    else
    {
        return false; // this is greater than other
    }
}

// Overloading > operator to compare rational Numbers
bool RationalNumber::operator>(const RationalNumber &other) const
{
    if (!(*this <= other))
    {
        return true; // this is greater than other
    }
    else
    {
        return false; // this is not greater than other
    }
}

// Overloading >= operator to compare rational Numbers
bool RationalNumber::operator>=(const RationalNumber &other) const
{
    if (*this > other || *this == other)
    {
        return true; // this is greater than or equal to other
    }
    else
    {
        return false; // this is less than other
    }
}

// Overloading << operator for showing output as Rational Number
std::ostream &operator<<(std::ostream &out, const RationalNumber &r)
{
    if (r.denominator == 1)
        out << r.numerator;
    else
        out << r.numerator << "/" << r.denominator;
    return out;
}
