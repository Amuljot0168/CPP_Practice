#include <iostream>
#include "Amuljot_Sept23_task2_CrapsGame.h"

int rollDice()
{
    int die1 = 1 + rand() % 6;
    int die2 = 1 + rand() % 6;
    return die1 + die2;
}

Status playGame(int &rollCount)
{
    int sumOfDice = rollDice();
    int point;
    Status gameStatus;

    rollCount = 1;
    if (sumOfDice == 7 || sumOfDice == 11)
    {
        return WON;
    }
    else if (sumOfDice == 2 || sumOfDice == 3 || sumOfDice == 12)
    {
        return LOST;
    }
    else
    {
        gameStatus = CONTINUE;
        point = sumOfDice;
    }

    while (gameStatus == CONTINUE)
    {
        sumOfDice = rollDice();
        ++rollCount;

        if (sumOfDice == point)
        {
            gameStatus = WON;
        }
        else if (sumOfDice == 7)
        {
            gameStatus == false;
        }
    }
    return gameStatus;
}

void printStatsAll(const int wins[], const int losses[])
{
    std::cout << "\nWins by rolls: \n";
    for (int i = 1; i <= tracked_rolls; ++i)
        std::cout << "Roll " << i << ": " << wins[i] << " wins\n";
    std::cout << "After roll 20: " << wins[tracked_rolls + 1] << " wins\n";

    std::cout << "\n Losses by rolls: \n";
    for (int i = 1; i <= tracked_rolls; ++i)
        std::cout << "Roll " << i << ": " << losses[i] << " losses\n";
    std::cout << "After roll 20th : " << losses[tracked_rolls + 1] << " losses\n\n";
}

void printSummary(int totalWins, int totalLosses, int totalRolls, const int wins[], const int losses[])
{
    double winChance = static_cast<double>(totalWins) / total_games * 100;
    double avgLength = static_cast<double>(totalRolls) / total_games;

    std::cout << "\nOverall Statistics:\n";
    std::cout << "Total Wins: " << totalWins << "\n";
    std::cout << "Total Losses: " << totalLosses << "\n";
    std::cout << "Chance of Winning: " << winChance << "%\n";
    std::cout << "Average Game Length: " << avgLength << " rolls\n";

    std::cout << "\nWin Rate by Roll Length:\n";
    for (int i = 1; i <= tracked_rolls; ++i)
    {
        int total = wins[i] + losses[i];
        if (total > 0)
        {
            double rate = static_cast<double>(wins[i]) / total * 100;
            std::cout << "Roll " << i << ": " << rate << "% win rate\n";
        }
    }

    std::cout << "\n Yes, the chances of winning improves with the length of the game \n";
}