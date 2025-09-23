#ifndef AIRLINE_RESERVATION_H
#define AIRLINE_RESERVATION_H

const int total_seats = 10; // Total number of seats are 10;

// Find the available seats in airline
int findAvaialbleSeats(bool seats[], int start, int end);

// Print the board pass according to seatNumber
void printBoardingPass(int seatNumber);

#endif