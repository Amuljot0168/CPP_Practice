#include <iostream>
#include "Amuljot_Sept24_task3_DateAndTime.h"

int main()
{
    std::cout << "Testing tick into next day:\n";
    DateAndTime date(12, 2025, 31, 23, 59, 58); // Dec 31, 11:59:58 PM

    // Triggering tick and print Standard Function
    for (int i = 0; i < 5; ++i)
    {
        date.printStandard(); // print Date and Time COmbined
        date.tick();          // Tick Function to increment the time and also the day if necessary
    }

    return 0;
}
