#include <iostream>
#include <ctime>
#include "Amuljot_Sept23_task2_CrapsGame.h"

int main()
{

    int wins[tracked_rolls + 1] = {0};
    int losses[tracked_rolls + 1] = {0};
    int totalWins = 0;
    int totalLosses = 0;
    int number_of_rolls = 0;

    srand(time(0));
    for (int i = 0; i < total_games; i++)
    {
        int rollCount;
        Status result = playGame(rollCount);
        number_of_rolls += rollCount;

        int index;
        if (rollCount <= tracked_rolls)
        {
            index = rollCount;
        }
        else
        {
            index = tracked_rolls + 1;
        }

        if (result == WON)
        {
            totalWins++;
            wins[index]++;
        }
        else
        {
            totalLosses++;
            losses[index]++;
        }
    }

    printStatsAll(wins, losses);
    printSummary(totalWins, totalLosses, number_of_rolls, wins, losses);
    return 0;
}