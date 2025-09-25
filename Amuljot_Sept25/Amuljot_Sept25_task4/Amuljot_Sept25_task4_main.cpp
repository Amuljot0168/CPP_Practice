#include <iostream>
#include "Amuljot_Sept25_task4_Flight.h"

int main()
{
    std::cout << "Air Traffic Control Simulator\n\n";

    // Create 3 flights in different states
    Flight flight1("IndiGo", "6E203", "A320", 25000, 450, 90, "DEL", "BLR", "10:00", "12:30", AT_GATE);
    Flight flight2("Air India", "AI101", "Boeing 787", 0, 500, 270, "BOM", "LHR", "14:00", "20:00", WAITING_TO_TAKEOFF);
    Flight flight3("SpiceJet", "SG456", "737 MAX", 20000, 480, 180, "HYD", "MAA", "16:00", "17:15", DESCENDING);

    // Simulate air traffic control instructions
    std::cout << "[Air Traffic Control] IndiGo 6E203 climb to 30000 feet.\n";
    flight1.changeAltitude(30000); // a) display message, b) change status, c) update newAltitude
    std::cout << std::endl;

    std::cout << "[Air Traffic Control] Air India AI101 reduce speed to 420 knots.\n";
    flight2.reduceSpeed(420); // confirmation message + update speed
    std::cout << std::endl;

    std::cout << "[Air Traffic Control] SpiceJet SG456 begin landing approach.\n";
    flight3.beginLandingApproach(); // confirmation message + update status
    std::cout << std::endl;

    // Print full status reports
    std::cout << "\n--- Flight Status Reports ---\n\n";
    std::cout << flight1.toString() << std::endl;
    std::cout << flight2.toString() << std::endl;
    std::cout << flight3.toString() << std::endl;

    return 0;
}