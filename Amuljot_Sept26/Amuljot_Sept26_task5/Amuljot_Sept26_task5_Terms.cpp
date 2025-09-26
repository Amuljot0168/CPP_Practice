#include "Amuljot_Sept26_task5_Terms.h"

// Constructor
Term::Term(int c, int e) : coefficient(c), exponent(e) {}

// Set Functions
void Term::setCoefficient(int c)
{
    coefficient = c;
}

void Term::setExponent(int e)
{
    exponent = e;
}

// Get Functions

int Term::getCoefficient() const
{
    return coefficient;
}

int Term::getExponent() const
{
    return exponent;
}