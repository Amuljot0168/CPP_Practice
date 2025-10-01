#include <iostream>
#include "Amuljot_Oct1_task2_BatteryMonitor.h"

int main()
{
    // Created two objects of Battery Monitor as guven in sample Data
    BatteryMonitor s1("SCT101", 300, 4.0, 5.0, true, 3); // 80% health
    BatteryMonitor s2("SCT202", 150, 3.5, 5.0, true, 2); // 70% health

    // Initalizing distances for each Battery Monitor
    s1[0] = 12;
    s1[1] = 18;
    s1[2] = 25;

    s2[0] = 10;
    s2[1] = 15;

    // Print the details of Battery Monitors
    std::cout << "Battery Monitor 1: \n"
              << s1 << std::endl;
    std::cout << "Battery Monitor 2: \n"
              << s2 << std::endl;

    // Compare the Battery Monitors
    if (s1 < s2)
    {
        std::cout << "Battery Monitor1 has better battery health.\n";
    }
    else
    {
        std::cout << "Battery Monitor2 has better battery health.\n";
    }

    // Use += operator to increment cycleCharge and simulate degradation
    s1 += 50;

    // Check the status of battery Mointor
    if (!s1)
    {
        std::cout << "Battery Monitor 1 is inactive.\n";
    }
    else
    {
        std::cout << "Battery Monitor 1 is Active\n";
    }

    // Copy the values of s1 to s3 Battery Monitor Using Deep Copy
    BatteryMonitor s3 = s1;

    std::cout << "Battery Monitor 1: \n"
              << s1 << std::endl;
    std::cout << "Battery Monitor 3: \n"
              << s3 << std::endl;

    // Modifying values of s1 to confirm deep copy
    s1[0] = 10;
    s1[1] = 20;

    std::cout << "After Modifying values in Battery Monitor s1: \n";
    std::cout << "Battery Monitor 1: \n"
              << s1 << std::endl;
    std::cout << "Battery Monitor 3: \n"
              << s3 << std::endl;

    return 0;
}