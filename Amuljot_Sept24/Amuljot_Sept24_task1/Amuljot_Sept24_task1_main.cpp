#include <iostream>
#include "Amuljot_Sept24_task1_EnhancingClass.h"

int main()
{

    // Test cases for checking the function works
    std::cout << "Incrementing into next minute:\n";
    Time t1(4, 55, 58); // Creating object using constructor

    for (int i = 0; i < 5; ++i)
    {
        t1.printStandard(); // Print the time
        t1.tick();          // Calling tick function on each iteration
    }

    std::cout << "\nIncrementing into next hour:\n";
    Time t2(1, 59, 58);

    for (int i = 0; i < 5; ++i)
    {
        t2.printStandard(); // Print the time
        t2.tick();          // Calling tick function on each iteration
    }

    std::cout << "\nIncrementing into next day:\n";
    Time t3(23, 59, 58);
    for (int i = 0; i < 5; ++i)
    {
        t3.printStandard(); // Print the time
        t3.tick();          // Calling tick function on each iteration
    }

    return 0;
}