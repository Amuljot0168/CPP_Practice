#include <iostream>
#include "Amuljot_Sept29_task4_TurtleHareRace.h"

void moveTortoise(int *position)
{
    int move = rand() % 10 + 1; // Random move
    if (move >= 1 && move <= 5) // Fast Plod (50%)
    {
        *position += 3; // move +3 square and add to its position
    }
    else if (move >= 6 && move <= 7) // Slip
    {
        *position -= 6; // move -6 square and reduce the position on slip
    }
    else if (move >= 8 && move <= 10) // Slow Pod
    {
        *position += 1; // move +1 square and add it into the position
    }

    if (*position < 1)
        *position = START_POSITION; // if position gets less than 1 then resets its value to starting position
}

// Function which will move the hare
void moveHare(int *position)
{
    int move = rand() % 10 + 1; // Random move
    if (move >= 1 && move <= 2) // Sleep
    {
        *position += 0; // No move
    }
    else if (move >= 3 && move <= 4) // Big Hop
    {
        *position += 9; // move 9 square and Add to the position
    }
    else if (move == 5) // Big Slip
    {
        *position -= 12; // move -12 square (means backward) and reduce the position on slip
    }
    else if (move >= 6 && move <= 8) // Small Hop
    {
        *position += 1; // move +1 square and add to the position
    }
    else if (move >= 9 && move <= 10) // Small Slip
    {
        *position -= 2; // move -2 square (means backward) and reduce the position at slip
    }

    if (*position < 1)
        *position = START_POSITION; // if position gets less than 1 then resets its value to starting position
}

// Print the status of positions of Tortoise and Hare
void printTrack(int TortoisePosition, int HarePosition) // Print the positions of Tortoise and Hare
{
    for (int i = 1; i <= RACE_TRACK_LENGTH; i++)
    {
        if (i == TortoisePosition && i == HarePosition)
        {
            std::cout << "OUCH!!!";
        }
        else if (i == TortoisePosition)
        {
            std::cout << "T";
        }
        else if (i == HarePosition)
        {
            std::cout << "H";
        }
        else
        {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}