#include <iostream>
#include "Amuljot_Sept23_task3_AirlineReservation.h"

int main()
{
    bool seats[total_seats] = {false}; // Initialize seats array as false
    int choice = -1;                   // Choice taken from user

    // Loop will run until choice is not equal to 0
    while (choice != 0)
    {
        std::cout << "Airline Reservation System Menu!\n";
        std::cout << "Type 1 to reserve First Class\n";
        std::cout << "Type 2 to reserve Economy Class\n";
        std::cout << "Type 0 to exit the program....\n"
                  << std::endl;

        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == 0)
            break;

        int seatIndex = -1;
        char response; // variable to store the response from user(Yes(Y)/No(N))
        switch (choice)
        {
        case 1: // Check if there is seat in First Class
        {
            seatIndex = findAvaialbleSeats(seats, 0, 5); // Calling findAvailableSeats function in range of First Class
            // If Seat is not available then ask for booking economy class
            if (seatIndex == -1)
            {
                std::cout << "First Class Section is fully occupied.\n";
                std::cout << "Would you like to reserve any economy class seat? (y/n): ";
                std::cin >> response; // Take response from user (y-yes/n-No)

                // If response is yes then check for seats in economy section
                if (response == 'y' || response == 'Y')
                {
                    seatIndex = findAvaialbleSeats(seats, 5, total_seats);
                }
            }
            break;
        }
        case 2: // Check if there is seat in Economy Class
        {
            seatIndex = findAvaialbleSeats(seats, 5, total_seats); // Calling findAvailableSeats function in range of Economy Class
            if (seatIndex == -1)
            {
                std::cout << "Economy Class Section is fully occupied.\n";
                std::cout << "Would you like to reserve any First class seat? (y/n): ";
                std::cin >> response; // Take response from user (y-yes/n-No)

                // If response is yes then check for seats in First class section
                if (response == 'y' || response == 'Y')
                {
                    seatIndex = findAvaialbleSeats(seats, 0, 5);
                }
            }
            break;
        }

        default: // If user input invalid input then print error message
            std::cout << "Invalid choice. Please enter 0, 1 or 2.\n\n";
            continue;
        }

        // Check if Seat is available than mark as true and print boarding pass of user
        if (seatIndex != -1)
        {
            seats[seatIndex] = true;
            printBoardingPass(seatIndex);
        }
        // If seat is not available then print this
        else if (choice == 1 || choice == 2)
        {
            std::cout << "Next Flight is in 3 hours.\n\n";
            std::cout << "Current Flight is All Booked!\n\n";
            break;
        }
    }

    return 0;
}