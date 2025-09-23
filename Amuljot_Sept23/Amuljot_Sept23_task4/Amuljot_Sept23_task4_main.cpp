#include <iostream>
#include "Amuljot_Sept23_task4_TurtleGraphics.h"

int main()
{
    // Initialize the 20x20 sketchpad to false (blank)
    bool floor[size][size] = {false};

    // Turtle's starting position
    int x = 0;
    int y = 0;

    // Initial direction: facing right (0)
    int direction = 0;

    // Pen starts in the up position (not drawing)
    bool penDown = false;

    std::cout << "Turtle Graphics Simulation\n";

    int command = -1;

    // Main loop: runs until user enters command 9 (exit)
    while (command != 9)
    {
        std::cout << "\nCommands:\n";
        std::cout << "1 - Pen Up\n";
        std::cout << "2 - Pen Down\n";
        std::cout << "3 - Turn Right\n";
        std::cout << "4 - Turn Left\n";
        std::cout << "5 - Move Forward (you'll enter steps)\n";
        std::cout << "6 - Print Floor\n";
        std::cout << "7 - Turtle current poistion\n";
        std::cout << "8 - Clear floor\n";
        std::cout << "9 - Exit\n";
        std::cout << "Enter command: ";
        std::cin >> command;

        switch (command)
        {
        case 1: // Turtle freely moves without writing anything
            penDown = false;
            std::cout << "Pen is now UP.\n";
            break;

        case 2: // Pen is down means turtle can write when it moves
            penDown = true;
            std::cout << "Pen is now DOWN.\n";
            break;

        case 3: // Change direction to right
            direction = (direction + 1) % 4;
            std::cout << "Turned RIGHT.\n";
            break;

        case 4: // Change direction to left
            direction = (direction + 3) % 4;
            std::cout << "Turned LEFT.\n";
            break;

        case 5: // Move the turtles by n steps input by user
        {
            int steps;
            std::cout << "Enter number of steps to move the turtle: ";
            std::cin >> steps;
            moveTurtle(floor, x, y, direction, steps, penDown);
            break;
        }

        case 6: // Print the floor
            printFloor(floor);
            break;

        case 7: // Show current position of turtle
            std::cout << "Turtle position is : [" << x << " , " << y << " ] \n";
            std::cout << "Direction Facing: ";
            if (direction == 0)
            {
                std::cout << "Right";
            }
            else if (direction == 1)
            {
                std::cout << "Down";
            }
            else if (direction == 2)
            {
                std::cout << "Left";
            }
            else
            {
                std::cout << "Up";
            }
            std::cout << std::endl;
            break;

        case 8: // Reset all floor to blank
            for (int i = 0; i < size; ++i)
                for (int j = 0; j < size; ++j)
                    floor[i][j] = false;
            std::cout << "Floor cleared.\n";
            break;

        case 9: // Exit the program
            std::cout << "Exiting the program... Done!\n";
            break;

        default: // Invalid Command enetered by user
            std::cout << "Invalid Command! Please enter 1 to 9 only.\n";
        }
    }

    return 0;
}