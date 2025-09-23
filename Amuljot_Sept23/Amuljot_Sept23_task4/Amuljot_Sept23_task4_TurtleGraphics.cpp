#include <iostream>
#include "Amuljot_Sept23_task4_TurtleGraphics.h"

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

// Function to print the floor and drawing made by turtle
void printFloor(bool floor[size][size])
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (floor[i][j]) // true mean something written by turtle
            {
                std::cout << "* "; // print aestrick sign if its true
            }
            else // false means nothing written by turtle
            {
                std::cout << "  "; // print blank space if its false
            }
        }
        std::cout << std::endl;
    }
}

void moveTurtle(bool floor[size][size], int &x, int &y, int direction, int steps, bool penDown)
{
    for (int i = 0; i < size; i++)
    {
        if (x >= 0 && x < size && y >= 0 && y < size)
        {
            floor[x][y] = true;
        }

        x += dx[direction];
        y += dy[direction];

        if (x < 0)
        {
            x = 0;
        }
        if (x >= size)
        {
            x = size - 1;
        }
        if (y < 0)
        {
            y = 0;
        }
        if (y >= size)
        {
            y = size - 1;
        }
    }
}