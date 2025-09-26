#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include "Amuljot_Sept26_task5_Terms.h"

#include <iostream>
class Polynomial
{
    friend std::ostream &operator<<(std::ostream &, const Polynomial &);

public:
    // Constructors
    Polynomial(int = 10);
    Polynomial(const Polynomial &);
    ~Polynomial();

    // Assignment Operator
    Polynomial &operator=(const Polynomial &);

    // Arithmetic Operator
    Polynomial operator+(const Polynomial &) const;
    Polynomial operator-(const Polynomial &) const;
    Polynomial operator*(const Polynomial &) const;

    Polynomial &operator+=(const Polynomial &);
    Polynomial &operator-=(const Polynomial &);
    Polynomial &operator*=(const Polynomial &);

    // set Function
    void setTerm(int coeff, int exp);
    // Get Function
    int getCoefficient(int exp) const;

private:
    Term *terms;
    int size;
};
#endif