#include <iostream>
#include "Amuljot_Oct1_task1_SmartFleet.h"

int main()
{
    // Creating two objects from sample data
    HybridVehicle vehicle1("Prius", 120.5, 80.0, 4.5);
    HybridVehicle vehicle2("Volt", 100.0, 90.0, 5.0);

    // Accessing values of objects trips  by [] opearator
    vehicle1[0] = 50;
    ++vehicle1;
    vehicle1[1] = 60;
    ++vehicle1;
    vehicle2[0] = 70;
    ++vehicle2;
    vehicle2[1] = 40;
    ++vehicle2;

    // Printing the details of both vehicle1 and vehicle2
    std::cout << "Vehicle 1:\n"
              << vehicle1;
    std::cout << "\nVehicle 2:\n"
              << vehicle2;

    // Using + operator to combined both objects
    HybridVehicle combined = vehicle1 + vehicle2;
    std::cout << "\nCombined Vehicle:\n"
              << combined; // printing the details of combined object

    // Compare the efficency using == operator
    std::cout << "\nEfficiency Comparison: ";
    if (vehicle1 == vehicle2)
    {
        std::cout << "Efficiency is equal \n";
    }
    else
    {
        std::cout << "Efficiency is not equal\n";
    }

    // Pre increment ++ operator to increment tripCount and add dummy value
    ++vehicle1;
    std::cout << "\nAfter Simulating New Trip (vehicle1):\n"
              << vehicle1;

    std::cout << "\nAccessing vehicle2 trips[1]: " << vehicle2[1] << " km\n";    // Access vehicle2 trips[1] element
    std::cout << "Total Distance of vehicle2: " << vehicle2() << " km\n";        // Print the total distance of vehicle 2
    std::cout << "Efficiency float(vehicle2): " << float(vehicle2) << " km/L\n"; // Print the efficiency of vehcile 2

    // Using assigning operator =
    HybridVehicle vehicle3;
    vehicle3 = vehicle1;

    // Modify vehicle1 after assignment
    vehicle1[0] = 999;
    vehicle1[1] = 888;

    // Show both vehicles to verify deep copy
    std::cout << "\nAfter modifying vehicle1 trips:\n";
    std::cout << "Vehicle 1:\n"
              << vehicle1;
    std::cout << "\nVehicle 3 (should remain unchanged):\n"
              << vehicle3;

    return 0;
}
