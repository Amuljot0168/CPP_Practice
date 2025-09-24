#include <iostream>
#include "Amuljot_Sept24_task5_globalFunctionalities.h"
#include "Amuljot_Sept24_task5_TicTacToe.h"

void playGameHumanVsComputer()
{
    // Creating game1 as object
    TicTacToe game1 = TicTacToe();
    int player;                                                  // Variable to store the value of player (1 or Computer)
    std::cout << "Do you want to go first? (1 = yes, 2 = no): "; // Ask user to go first or not
    std::cin >> player;                                          // Input the choice which player go first

    int row;
    int col;

    while (true)
    {
        game1.DisplayBoard(); // Display the  current board
        if (player == 1)      // If it's player 1 turn then
        {
            std::cout << "Player " << player << " turn .\n";
            std::cout << "Select row (row(0-2): "; // Choose the row on board
            std::cin >> row;

            std::cout << "Select column (column(0-2): "; // Choose the column on board
            std::cin >> col;

            if (!game1.makeMove(player, row, col)) // Make the move if valid move
            {
                std::cout << "Invalid Move! Please Try again.\n";
                continue;
            }
        }
        else
        {
            std::cout << "Computer Move\n";
            game1.computerMove(); // Make Computer move for its turn
        }

        int winner = game1.whoWin(); // Store who wins the game
        if (winner != 0)
        {
            game1.DisplayBoard(); // Display the board

            if (player == 1)
            {
                std::cout << "Player " << winner << " wins!\n"; // Display this if player 1 wins
            }
            else
            {
                std::cout << "Computer Wins! \n"; // Display this when Computer wins
            }
            break;
        }

        // Check Game is draw or not
        if (game1.isDraw())
        {
            game1.DisplayBoard(); // Display the board for the user
            std::cout << "OOps! It's a draw!\n";
            break;
        }

        // Switch the players for changing turns
        if (player == 1)
        {
            player = 2;
        }
        else
        {
            player = 1;
        }
    }
}

// Implement play game between Human and Human
void playGameHumanVsHuman()
{
    // Creating game1 as object
    TicTacToe game1 = TicTacToe();
    int player;                                                  // Variable to store the value of player (1 or 2)
    std::cout << "Do you want to go first? (1 = yes, 2 = no): "; // Ask user to go first or not
    std::cin >> player;                                          // Input the choice which player go first

    int row;
    int col;

    while (true)
    {
        game1.DisplayBoard(); // Display the  current board

        std::cout << "Player " << player << " turn .\n";
        std::cout << "Select row (row(0-2): "; // Choose the row on board
        std::cin >> row;

        std::cout << "Select column (column(0-2): "; // Choose the column on board
        std::cin >> col;

        // Make the move for player
        if (!game1.makeMove(player, row, col)) // Make the move if valid move
        {
            std::cout << "Invalid Move! Please Try again.\n";
            continue;
        }

        int winner = game1.whoWin(); // Store who wins the game

        // Show the Winner
        if (winner != 0)
        {
            game1.DisplayBoard();                           // Display the  current board
            std::cout << "Player " << winner << " wins!\n"; // Display the player who win the game
            break;
        }

        // Check Game is draw or not
        if (game1.isDraw())
        {
            game1.DisplayBoard(); // Display the  current board
            std::cout << "OOps! It's a draw!\n";
            break;
        }

        // Switch the players for changing turns
        if (player == 1)
        {
            player = 2;
        }
        else
        {
            player = 1;
        }
    }
}