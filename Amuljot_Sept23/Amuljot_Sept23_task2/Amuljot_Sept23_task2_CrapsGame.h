#ifndef CRAPS_GAME_H
#define CRAPS_GAME_H

const int total_games = 1000;
const int tracked_rolls = 20;
enum Status
{
    CONTINUE,
    WON,
    LOST
};

// Rolls two dice and returns their sum
int rollDice();

// Simulates a single game of craps and returns result + roll count
Status playGame(int &rollCount);

// Prints win/loss statistics by roll number
void printStatsAll(const int wins[], const int losses[]);

// Calculates and prints overall statistics
void printSummary(int totalWins, int totalLosses, int totalRolls, const int wins[], const int losses[]);

#endif