#include <iostream>

#include "Amuljot_Sept24_task4_ErrorIndicators.h"

int main()
{
    Time test_time; // Create test time object for testing error indicators
    std::cout << "Testing valid time:\n";

    // Error Indicator for setTime
    if (!test_time.setTime(13, 45, 30))
    {
        throw std::invalid_argument("Error: Invalid time input\n");
    }
    test_time.printUniversal(); // Print Time in Universal-time format
    test_time.printStandard();  // Print Time in Standard-time format

    // Error Indicator for setHour
    std::cout << "\nTesting invalid hour:\n";
    if (!test_time.setHour(25)) // Giving Invalid value in hours for testing error indicators
    {
        throw std::invalid_argument("Error: Invalid Hour\n");
    }

    // Error Indicator for setMinute
    std::cout << "\nTesting invalid minute:\n";
    if (!test_time.setMinute(75)) // Fiving invalid value in minutes for testing error indicators
    {
        throw std::invalid_argument("Error: Invalid Minute\n");
    }

    // Error Indicator for setSecond
    std::cout << "\nTesting invalid second:\n";
    if (!test_time.setSecond(-5)) // Giving Invalid value in seconds for testing error indicators
    {
        throw std::invalid_argument("Error: Invalid Second\n");
    }

    std::cout << "\nFinal time state:\n";
    test_time.printUniversal();
    test_time.printStandard();

    std::cout << "Incrementing into next minute:\n";
    Time t1(4, 55, 58); // Creating object using constructor
    for (int i = 0; i < 5; ++i)
    {
        t1.printStandard();
        t1.tick();
    }

    return 0;
}