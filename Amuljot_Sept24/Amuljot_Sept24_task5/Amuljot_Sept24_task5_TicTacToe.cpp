#include <iostream>
#include <cstdlib> // for rand()
#include <ctime>
#include "Amuljot_Sept24_task5_TicTacToe.h"

// Initializing the 3X3 board to 0 using constructor
TicTacToe::TicTacToe()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = 0;
        }
    }
}

// Function to display the board to user
void TicTacToe::DisplayBoard()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

// Function to make move
bool TicTacToe::makeMove(int player, int row, int col)
{
    if (row < 0 || row >= 3 || col < 0 || col >= 3) // Check the bounds
    {
        return false; // return false if given index is out of range
    }
    if (board[row][col] != 0)
    {
        return false; // return false as place is already been filled earlier
    }

    board[row][col] = player; // Place 1 or 2 based on player on the board

    return true; // return true ,sucessfully placed the move
}

// Funnction finds out which player wins
int TicTacToe::whoWin()
{
    // Check rows and columns
    for (int i = 0; i < 3; i++)
    {
        // Check columns
        if (board[0][i] != 0 && (board[0][i] == board[1][i]) && (board[1][i] == board[2][i]))
        {
            return board[0][i];
        }

        // Check rows
        if (board[i][0] != 0 && (board[i][0] == board[i][1]) && (board[i][1] == board[i][2]))
        {
            return board[i][0];
        }
    }

    // Check Diagonals
    // Diagonals
    if (board[0][0] != 0 &&
        board[0][0] == board[1][1] &&
        board[1][1] == board[2][2])
        return board[0][0];

    if (board[0][2] != 0 &&
        board[0][2] == board[1][1] &&
        board[1][1] == board[2][0])
        return board[0][2];

    return 0; // No Winner yet
}

// Function to check if the game is draw
bool TicTacToe::isDraw()
{
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (board[i][j] == 0)
                return false;
    return whoWin() == 0;
}

// Computer Move Function
void TicTacToe::computerMove()
{
    int row, col;
    do
    {
        row = rand() % 3;
        col = rand() % 3;
    } while (board[row][col] != 0);
    board[row][col] = 2;
}
