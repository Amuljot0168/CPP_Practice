#include "Amuljot_Oct6_task5_Package.h"
#include "Amuljot_Oct6_task5_TwoDayPackage.h"
#include "Amuljot_Oct6_task5_OvernightPackage.h"
#include <iostream>

int main()
{
    // Creating objects of all Packages and initializing there values
    Package standard("ABC", "#Hno 1,Sector1", "Pune", "Maharashtra", "147005",
                     "XYZ", "#Hno 2 Sector2", "Pune", "Maharashtra", "147005",
                     20.0, 0.5);

    TwoDayPackage twoDay("EFG", "#Hno 1,Sector1", "Pune", "Maharashtra", "147005",
                         "XYZ", "#Hno 2 Sector2", "Pune", "Maharashtra", "147005",
                         25.0, 0.8, 10.0);

    OvernightPackage overnight("HIJ", "#Hno 1,Sector1", "Pune", "Maharashtra", "147005",
                               "XYZ", "#Hno 2 Sector2", "Pune", "Maharashtra", "147005",
                               10.0, 0.5, 0.25);

    // Standard Package
    std::cout << "\nStandard Package:\n";
    standard.print();
    std::cout << "Total Cost: $" << standard.calculateCost() << "\n";

    // Two Day Package
    std::cout << "\nTwo-Day Package:\n";
    twoDay.print();
    std::cout << "Total Cost: $" << twoDay.calculateCost() << "\n";

    // Overnight Package
    std::cout << "\nOvernight Package:\n";
    overnight.print();
    std::cout << "Total Cost: $" << overnight.calculateCost() << "\n";

    return 0;
}
