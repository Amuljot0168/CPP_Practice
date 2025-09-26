#include <iostream>

#include "Amuljot_Sept26_task5_Polynomial.h"

// Constructors
Polynomial::Polynomial(int s) : size(s)
{
    terms = new Term[size];
}

// Copy Constructor
Polynomial::Polynomial(const Polynomial &other) : size(other.size)
{
    terms = new Term[size];
    for (int i = 0; i < size; i++)
    {
        terms[i] = other.terms[i];
    }
}

// Destructor to delete dynamically allocated memory
Polynomial::~Polynomial()
{
    delete[] terms;
}

// Overloading assignment operator to copy value from other polynomial
Polynomial &Polynomial::operator=(const Polynomial &other)
{
    if (this != &other)
    {
        delete[] terms;
        size = other.size;
        terms = new Term[size];
        for (int i = 0; i < size; i++)
        {
            terms[i] = other.terms[i];
        }
    }
    return *this;
}

// Function to set Terms value according to coefficient and exponent
void Polynomial::setTerm(int coeff, int exp)
{
    for (int i = 0; i < size; i++)
    {
        if (terms[i].getExponent() == exp)
        {
            terms[i].setCoefficient(coeff); // Update the value if exponent exist in polynomial
            return;
        }
    }
    for (int i = 0; i < size; ++i)
    {
        if (terms[i].getCoefficient() == 0) // If there is not any existing value  then add the values
        {
            terms[i].setCoefficient(coeff);
            terms[i].setExponent(exp);
            return;
        }
    }
}

// Function to get Coefficient of current object according the exponent
int Polynomial::getCoefficient(int exp) const
{
    for (int i = 0; i < size; ++i)
        if (terms[i].getExponent() == exp)
            return terms[i].getCoefficient();
    return 0;
}

// Overloading + operator to multiply the polynomials
Polynomial Polynomial::operator+(const Polynomial &operand2) const
{
    Polynomial result(size + operand2.size);

    // Copy the current object polynomial to result one
    for (int i = 0; i < size; i++)
    {
        result.setTerm(terms[i].getCoefficient(), terms[i].getExponent());
    }

    // Add the polynomials
    for (int i = 0; i < operand2.size; i++)
    {
        int coeff = result.getCoefficient(operand2.terms[i].getExponent()) + operand2.terms[i].getCoefficient(); // Add the coefficients with particluar exponents same of both
        result.setTerm(coeff, operand2.terms[i].getExponent());                                                  // Store the add value in result
    }

    return result; // return the calculated polynomial
}

// Overloading - operator to multiply the polynomials
Polynomial Polynomial::operator-(const Polynomial &operand2) const
{
    Polynomial result(size + operand2.size);

    // Copy the current object polynomial to result polynomial
    for (int i = 0; i < size; i++)
    {
        result.setTerm(terms[i].getCoefficient(), terms[i].getExponent());
    }

    // Subtract the polynomials
    for (int i = 0; i < operand2.size; i++)
    {
        int coeff = result.getCoefficient(operand2.terms[i].getExponent()) - operand2.terms[i].getCoefficient();
        result.setTerm(coeff, operand2.terms[i].getExponent());
    }

    return result;
}

// Overloading * operator to multiply the polynomials
Polynomial Polynomial::operator*(const Polynomial &operand2) const
{
    // Created result object to store the calculated polynomial
    Polynomial result(size + operand2.size);

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < operand2.size; j++)
        {
            int coeff = terms[i].getCoefficient() * operand2.terms[j].getCoefficient(); // Coefficient is multplied
            int expo = terms[i].getExponent() + operand2.terms[j].getExponent();        // Exponent is multiplied (it gets added so)
            int ifexisting = result.getCoefficient(expo);                               // If there value exist of coefficient

            result.setTerm(ifexisting + coeff, expo); // update the result polynomial
        }
    }

    return result; // return multiplied value of polynomial
}

// Overloading operator +=
Polynomial &Polynomial::operator+=(const Polynomial &operand2)
{
    *this = *this + operand2;
    return *this;
}

// Overloading operator -=
Polynomial &Polynomial::operator-=(const Polynomial &operand2)
{
    *this = *this - operand2;
    return *this;
}

// Overloading operator *=
Polynomial &Polynomial::operator*=(const Polynomial &operand2)
{
    *this = *this * operand2;
    return *this;
}

// Overloading output operator << to print in format of polynomial
std::ostream &operator<<(std::ostream &out, const Polynomial &poly)
{
    bool isFirst = true;
    for (int i = 0; i < poly.size; i++)
    {
        int coeff = poly.terms[i].getCoefficient();
        int expo = poly.terms[i].getExponent();
        if (coeff != 0)
        {
            if (!isFirst && coeff > 0)
            {
                out << " + ";
            }
            else if (coeff < 0)
            {
                out << " - ";
            }
            else if (isFirst)
            {
                out << " ";
            }

            out << abs(coeff);
            if (expo != 0)
            {
                out << "x^" << expo;
            }
            isFirst = false;
        }
    }
    if (isFirst)
    {
        out << "0";
    }
    return out;
}