#include <iostream>

#include "Amuljot_Sept30_task3_MazeTraversal.h"

// Function to print the maze for user
void printMaze(char maze[SIZE][SIZE])
{
    for (int row = 0; row < SIZE; row++)
    {
        for (int col = 0; col < SIZE; col++)
        {
            std::cout << maze[row][col] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl
              << std::endl;
}

// Check the the current position is exit or not
bool isExit(int row, int col, int startRow, int startColumn)
{
    if ((row != startRow || col != startColumn) && (row == 0 || row == SIZE - 1 || col == 0 || col == SIZE - 1))
    {
        return true;
    }
    return false;
}
// Boolean flag to check if we have found exit or not
bool foundExit = false;
void mazeTraverse(char maze[SIZE][SIZE], int row, int col, int startRow, int startCol)
{
    if (foundExit || row < 0 || row >= SIZE || col < 0 || col >= SIZE) // if position is out of bound return
        return;

    if (maze[row][col] != '.') // if position is wall or visited return
        return;

    // Mark position visited
    maze[row][col] = 'X';

    printMaze(maze); // Print each move

    if (isExit(row, col, startRow, startCol)) // check if current position or not
    {
        std::cout << "Exit at [" << row << "," << col << "] " << std::endl;
        foundExit = true; // set true when found exit
        return;
    }

    mazeTraverse(maze, row, col + 1, startRow, startCol); // Right
    mazeTraverse(maze, row + 1, col, startRow, startCol); // Down
    mazeTraverse(maze, row, col - 1, startRow, startCol); // Left
    mazeTraverse(maze, row - 1, col, startRow, startCol); // Up
}