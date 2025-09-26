#include <iostream>
#include <string>
#include "Amuljot_Sept26_task3_HugeInt.h"

// COnstructor
HugeInt::HugeInt(long value)
{
    // Initialize the HugeInt as 0
    for (int i = 0; i < digits; i++)
    {
        integer[i] = 0;
    }

    int j = digits - 1;
    while (value != 0)
    {
        integer[j--] = value % 10;
        value /= 10;
    }
}

// Constructor which takes string as parameter
HugeInt::HugeInt(const std::string &number)
{
    for (int i = 0; i < digits; i++)
    {
        integer[i] = 0;
    }

    int j = digits - 1;

    int length = number.size();
    for (int j = digits - length, k = 0; j < digits; ++j, ++k)
        if (isdigit(number[k]))
            integer[j] = number[k] - '0';
}

// Overloading + operator to add HugeInt values
HugeInt HugeInt::operator+(const HugeInt &op2) const
{
    HugeInt temp;
    int carry = 0;

    for (int i = digits - 1; i >= 0; --i)
    {
        temp.integer[i] = integer[i] + op2.integer[i] + carry;
        if (temp.integer[i] > 9)
        {
            temp.integer[i] %= 10;
            carry = 1;
        }
        else
        {
            carry = 0;
        }
    }

    return temp;
}

// Overloading + operator to add HugeInt and int values
HugeInt HugeInt::operator+(int op2) const
{
    return *this + HugeInt(op2);
}

// Overloading + operator to add HugeInt and string values
HugeInt HugeInt::operator+(const std::string &op2) const
{
    return *this + HugeInt(op2);
}

// Overloading * operator to add HugeInt values
HugeInt HugeInt::operator*(const HugeInt &op2) const
{
    HugeInt result;

    for (int i = digits - 1; i >= 0; --i)
    {
        int carry = 0;
        for (int j = digits - 1; j >= 0; --j)
        {
            int pos = i + j - (digits - 1);
            if (pos >= 0)
            {
                int product = integer[i] * op2.integer[j] + result.integer[pos] + carry;
                result.integer[pos] = product % 10;
                carry = product / 10;
            }
        }
    }

    return result;
}

// Overloading - operator for subtracting two HugeInt
HugeInt HugeInt::operator-(const HugeInt &operand2) const
{
    HugeInt result;
    int borrow = 0;

    for (int i = digits - 1; i >= 0; i--)

    {
        int top = integer[i] - borrow;
        int bottom = operand2.integer[i];

        if (top < bottom)
        {
            top += 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }
        result.integer[i] = top - bottom;
    }
    return result;
}

// Overloading / operator for dividing two HugeInt
HugeInt HugeInt::operator/(const HugeInt &divisor) const
{
    HugeInt result;
    HugeInt remainder = *this;
    HugeInt one(1);

    while (remainder >= divisor)
    {
        remainder = remainder - divisor;
        result = result + one;
    }

    return result;
}

// Overloading == operator to compare HugeInt
bool HugeInt::operator==(const HugeInt &rhs) const
{
    for (int i = 0; i < digits; ++i)
        if (integer[i] != rhs.integer[i])
            return false;
    return true;
}

// Overloading != operator to compare HugeInt
bool HugeInt::operator!=(const HugeInt &rhs) const
{
    return !(*this == rhs);
}

// Overloading < operator to compare HugeInt
bool HugeInt::operator<(const HugeInt &rhs) const
{
    for (int i = 0; i < digits; ++i)
    {
        if (integer[i] < rhs.integer[i])
            return true;
        if (integer[i] > rhs.integer[i])
            return false;
    }
    return false;
}

// Overloading <= operator to compare HugeInt
bool HugeInt::operator<=(const HugeInt &rhs) const
{
    return *this < rhs || *this == rhs;
}

// Overloading > operator to compare HugeInt
bool HugeInt::operator>(const HugeInt &rhs) const
{
    return !(*this <= rhs);
}

// Overloading >= operator to compare HugeInt
bool HugeInt::operator>=(const HugeInt &rhs) const
{
    return !(*this < rhs);
}

// Overloading << operator to show output of HugeInt
std::ostream &operator<<(std::ostream &output, const HugeInt &num)
{
    int i = 0;

    // Skip leading zeros
    while (i < HugeInt::digits && num.integer[i] == 0)
        ++i;

    // If all digits are zero, print a single 0
    if (i == HugeInt::digits)
        output << 0;
    else
    {
        // Print digits from first non-zero to the end
        for (; i < HugeInt::digits; ++i)
            output << num.integer[i];
    }

    return output;
}
