#include <iostream>
#include <cstdlib>
#include "Amuljot_Sept29_task4_TurtleHareRace.h"

int main()
{
    // Generate random seed
    srand((time(0)));

    // Initializing position of tortoise and hare to 1
    int tortoisePosition = START_POSITION;
    int harePosition = START_POSITION;

    // Printing race start message
    std::cout << "BANG !!!!! \n";
    std::cout << "AND THEY'RE OFF !!!!! \n";

    // Flag for check RaceOver
    bool raceOver = false;

    int tick = 1;
    while (!raceOver)
    {

        // Moving both Tortoise and Hare
        moveTortoise(&tortoisePosition);
        moveHare(&harePosition);

        // Clamp positions
        if (tortoisePosition < 1)
            tortoisePosition = 1;
        if (harePosition < 1)
            harePosition = 1;

        // Print track positions
        std::cout << "Tick " << tick << ": ";
        printTrack(tortoisePosition, harePosition);

        // Check for winners and breaking the loop
        if (tortoisePosition >= RACE_TRACK_LENGTH && harePosition >= RACE_TRACK_LENGTH)
        {
            std::cout << "It's a tie. \n";
            raceOver = true;
        }
        else if (tortoisePosition >= RACE_TRACK_LENGTH)
        {
            std::cout << "TORTOISE WINS!!! YAY!!! \n";
            raceOver = true;
        }
        else if (harePosition >= RACE_TRACK_LENGTH)
        {
            std::cout << "Hare wins. Yuch. \n";
            raceOver = true;
        }

        // Incrementing the ticks
        tick++;
    }

    return 0;
}