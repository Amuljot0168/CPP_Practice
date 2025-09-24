#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Amuljot_Sept24_task5_TicTacToe.h"
#include "Amuljot_Sept24_task5_globalFunctionalities.h"

int main()
{
    std::srand(std::time(0)); // Seed random generator

    int choice; // Choice to be chosen by user

    do
    {
        std::cout << "\n===== TicTacToe Menu =====\n";
        std::cout << "1. Start New Game (Human vs Computer)\n";
        std::cout << "2. Start New Game (Human vs Human)\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice: ";

        std::cin >> choice;

        switch (choice)
        {
        case 1:
            playGameHumanVsComputer(); // Start the game between Human And Computer
            break;
        case 2:
            playGameHumanVsHuman(); // Start the game between Human And Human
            break;
        case 3: // Exit the program
            std::cout << "Thanks for playing!\n";
            break;
        default: // Invalid Choice
            std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 3);

    return 0;
}