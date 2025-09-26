#ifndef TERM_H
#define TERM_H

class Term
{
private:
    int coefficient;
    int exponent;

public:
    Term(int c = 0, int e = 0); // Default or Parameterised Constructor

    void setCoefficient(int c); // Set Coefficient
    void setExponent(int e);    // set Exponent

    int getCoefficient() const; // get value of Coefficient
    int getExponent() const;    // get value of exponent
};

#endif