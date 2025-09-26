#include <iostream>
#include <iomanip>
#include <cstdlib>

#include "Amuljot_Sept26_task1_DoubleScriptedArray.h"

// Constructor
DoubleSubscriptedArray::DoubleSubscriptedArray(int row, int col)
{
    if (row < 0)
    {
        rows = 1;
    }
    else
    {
        rows = row;
    }

    if (columns < 0)
    {
        columns = 1;
    }
    else
    {
        columns = col;
    }

    board = new int[rows * columns];

    for (int i = 0; i < rows * columns; i++)
    {
        board[i] = 0;
    }
}

// Copy Constructor
DoubleSubscriptedArray::DoubleSubscriptedArray(const DoubleSubscriptedArray &other) : rows(other.rows), columns(other.columns)
{
    board = new int[rows * columns];
    for (int i = 0; i < rows * columns; ++i)
    {
        board[i] = other.board[i];
    }
}

// Destructor
DoubleSubscriptedArray::~DoubleSubscriptedArray()
{
    delete[] board;
}

// Getter Functions
int DoubleSubscriptedArray::getRows() const { return rows; }
int DoubleSubscriptedArray::getColumns() const { return columns; }

// Overloading = operator for assigning one array to another
const DoubleSubscriptedArray &DoubleSubscriptedArray::operator=(const DoubleSubscriptedArray &other)
{
    if (this != &other)
    {
        if ((rows * columns) != (other.rows * other.columns))
        {
            delete[] board;
            board = new int[other.rows * other.columns];

            rows = other.rows;
            columns = other.columns;
            for (int i = 0; i < (rows * columns); i++)
            {
                board[i] = other.board[i];
            }
        }
    }
    return *this;
}

// Overloading != operator for comparison
bool DoubleSubscriptedArray::operator!=(const DoubleSubscriptedArray &right) const
{
    return !(*this == right);
}

// Overloading == operator for comparison
bool DoubleSubscriptedArray::operator==(const DoubleSubscriptedArray &other) const
{
    if (rows != other.rows || columns != other.columns)
        return false;
    for (int i = 0; i < rows * columns; ++i)
        if (board[i] != other.board[i])
            return false;
    return true;
}

// Overloading () operator
int &DoubleSubscriptedArray::operator()(int row, int col)
{
    if (row < 0 || row >= rows || col < 0 || col >= columns)
    {
        std::cerr << "Error: Subscript (" << row << "," << col << ") out of range\n";
        exit(1);
    }
    return board[index(row, col)];
}

// Overloading != operator for comparison for read only
const int &DoubleSubscriptedArray::operator()(int row, int col) const
{
    if (row < 0 || row >= rows || col < 0 || col >= columns)
    {
        std::cerr << "Error: Subscript (" << row << "," << col << ") out of range\n";
        exit(1);
    }
    return board[index(row, col)];
}

// Function to get the index of array
int DoubleSubscriptedArray::index(int row, int col) const
{
    return row * columns + col;
}

// Input and output operator overloaded
std::ostream &operator<<(std::ostream &out, const DoubleSubscriptedArray &arr)
{
    for (int i = 0; i < arr.rows; ++i)
    {
        for (int j = 0; j < arr.columns; ++j)
            out << std::setw(5) << arr(i, j);
        out << std::endl;
    }
    return out;
}

std::istream &operator>>(std::istream &in, DoubleSubscriptedArray &arr)
{
    for (int i = 0; i < arr.rows; ++i)
        for (int j = 0; j < arr.columns; ++j)
            in >> arr(i, j);
    return in;
}
