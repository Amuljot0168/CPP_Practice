#ifndef DOUBLE_SCRIPTED_ARRAY_H
#define DOUBLE_SCRIPTED_ARRAY_H

#include <iostream>
class DoubleSubscriptedArray
{
private:
    int rows;
    int columns;
    int *board;

public:
    // Constructors
    DoubleSubscriptedArray(int row = 1, int col = 1);       // Default paramters
    DoubleSubscriptedArray(const DoubleSubscriptedArray &); // Copy Constructor

    // Destructor
    ~DoubleSubscriptedArray();

    // Get Functions
    int getRows() const;
    int getColumns() const;

    int index(int row, int col) const;

    // Overloading operators
    const DoubleSubscriptedArray &operator=(const DoubleSubscriptedArray &);
    bool operator==(const DoubleSubscriptedArray &) const;
    bool operator!=(const DoubleSubscriptedArray &) const;

    // Overloading () operator
    int &operator()(int row, int col);
    const int &operator()(int row, int col) const;

    // Overloading input and output operator
    friend std::ostream &operator<<(std::ostream &, const DoubleSubscriptedArray &);
    friend std::istream &operator>>(std::istream &, DoubleSubscriptedArray &);
};
#endif