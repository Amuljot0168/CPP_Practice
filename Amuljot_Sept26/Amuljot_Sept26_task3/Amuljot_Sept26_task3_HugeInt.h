#ifndef HUGEINT_H
#define HUGEINT_H

#include <iostream>
#include <string>
class HugeInt
{
    friend std::ostream &operator<<(std::ostream &, const HugeInt &);

public:
    static const int digits = 30;

    HugeInt(long = 0);            // conversion/default constructor
    HugeInt(const std::string &); // conversion constructor

    HugeInt operator+(const HugeInt &) const; // addition operator; HugeInt + HugeInt

    HugeInt operator+(int) const; // addition operator; HugeInt + int

    // addition operator;
    // HugeInt + string that represents large integer value
    HugeInt operator+(const std::string &) const;

    // Subtract operator
    HugeInt operator-(const HugeInt &) const;

    // Multiply operator
    HugeInt operator*(const HugeInt &) const;

    // Division operator
    HugeInt operator/(const HugeInt &) const;

    // Comparison operators
    bool operator==(const HugeInt &) const;
    bool operator!=(const HugeInt &) const;
    bool operator<(const HugeInt &) const;
    bool operator<=(const HugeInt &) const;
    bool operator>(const HugeInt &) const;
    bool operator>=(const HugeInt &) const;

private:
    short integer[digits];
};
#endif