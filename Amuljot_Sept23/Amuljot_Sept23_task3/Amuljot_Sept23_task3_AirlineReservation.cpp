#include "Amuljot_Sept23_task3_AirlineReservation.h"
#include <iostream>

// Searches for the first available seat in the specified range

int findAvaialbleSeats(bool seats[], int start, int end)
{
    int availableSeat = -1;
    for (int i = start; i < end; i++)
    {
        if (!seats[i])
        {
            availableSeat = i;

            break;
        }
    }
    return availableSeat;
}

void printBoardingPass(int seatNumber)
{
    std::cout << "\nBoarding pass->" << std::endl;
    std::cout << "Seat Number: " << seatNumber + 1 << std::endl;

    // Check if seat is First Class (1-5) Or an Economy Class (5-10)  but we use 0 based index so its(0-4)First class & (5-9) Economy
    if (seatNumber <= 4)
    {
        std::cout << "First Class \n"
                  << std::endl;
    }
    else if (seatNumber >= 5 && seatNumber < total_seats)
    {
        std::cout << "Economy Class \n"
                  << std::endl;
    }
}
