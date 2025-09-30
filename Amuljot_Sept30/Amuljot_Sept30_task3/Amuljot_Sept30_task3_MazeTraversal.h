#ifndef MAZE_TRAVERSAL_H
#define MAZE_TRAVERSAL_H

// Size of maze is constant
const int SIZE = 12;

void mazeTraverse(char maze[SIZE][SIZE], int row, int col, int startRow, int startColumn); // Traverse the maze find exit

bool isExit(int row, int col, int startRow, int startColumn); // check if current row or column is exit or not

void printMaze(char maze[SIZE][SIZE]); // Function to print maze

#endif