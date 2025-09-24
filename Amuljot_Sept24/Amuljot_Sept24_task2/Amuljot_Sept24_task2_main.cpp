#include <iostream>
#include "Amuljot_Sept24_task2_EnhancingDate.h"

int main()
{
    std::cout << "\nIncrement to the next month \n";
    Date date1 = Date(3, 31, 2025); // Date is 31/3/2025
    date1.nextDay();                // Calling nextDay Function
    date1.print();                  // Calling print Function to display the date

    std::cout << "\nIncrement to the next year \n";
    Date date2 = Date(12, 31, 2025); // Date is 31/15/2025
    date2.nextDay();                 // Calling nextDay Function
    date2.print();                   // Calling print Function to display the date

    return 0;
}