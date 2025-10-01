#include <iostream>
#include <string>

#include "Amuljot_Oct1_task1_SmartFleet.h"

// Default and Parameterised Constructor
HybridVehicle::HybridVehicle(std::string name, float eKm, float gasKm, float gasUsed) : modelName(name), electricKm(eKm), gasolineKm(gasKm), gasolineUsed(gasUsed), tripCount(0)
{
    trips = new int[10];
    for (int i = 0; i < 10; i++)
    {
        trips[i] = 10;
    }
}

// Copy Constructor
HybridVehicle::HybridVehicle(const HybridVehicle &other) : modelName(other.modelName), electricKm(other.electricKm), gasolineKm(other.gasolineKm), gasolineUsed(other.gasolineUsed), tripCount(other.tripCount)
{
    trips = new int[10];
    for (int i = 0; i < 10; i++)
    {
        trips[i] = other.trips[i];
    }
}

// Destructor for free up dynamically allocated memory
HybridVehicle::~HybridVehicle()
{
    delete[] trips;
}

// Overlaod = assigning operator
HybridVehicle &HybridVehicle::operator=(const HybridVehicle &other)
{
    if (this != &other)
    {
        modelName = other.modelName;
        electricKm = other.electricKm;
        gasolineKm = other.gasolineKm;
        gasolineUsed = other.gasolineUsed;
        tripCount = other.tripCount;
        delete[] trips;
        trips = new int[10];
        for (int i = 0; i < 10; i++)
        {
            trips[i] = other.trips[i];
        }
    }
    return *this;
}

// Overloading +operator to get combined values of two objects
HybridVehicle HybridVehicle::operator+(const HybridVehicle &other) const
{
    HybridVehicle result;
    result.modelName = modelName + " " + other.modelName;
    result.electricKm = electricKm + other.electricKm;
    result.gasolineKm = gasolineKm + other.gasolineKm;
    result.gasolineUsed = gasolineUsed + other.gasolineUsed;
    result.tripCount = ((tripCount + other.tripCount) > 10) ? 10 : tripCount + other.tripCount;
    for (int i = 0; i < result.tripCount; i++)
    {
        result.trips[i] = trips[i] + other.trips[i];
    }
    return result;
}

// Overloading == operator to compare the efficincey of vehicles
bool HybridVehicle::operator==(const HybridVehicle &other) const
{
    return float(*this) == float(other);
}

// Overloading pre-increment ++ operator to increment the tripCount and add dummy value
HybridVehicle &HybridVehicle::operator++()
{
    if (tripCount < 10)
    {
        if (trips[tripCount] == 0)
            trips[tripCount] = 20; // Dummy Trip
        tripCount++;
    }
    return *this;
}

// Overloading []operator to access the vehicle trips[] by index
int &HybridVehicle::operator[](int index)
{
    if (index >= 10 || index < 0)
    {
        static int dummy = -1;
        std::cout << "Index is out of range!!!! \n\n";
        return dummy;
    }

    return trips[index];
}

// Overloading () operator to get total distance of vehicle object
int HybridVehicle::operator()() const
{
    int totalDistance = 0;
    for (int i = 0; i < tripCount; i++)
    {
        totalDistance += trips[i];
    }

    return totalDistance;
}

// Overloading float() operator to get efficiency of vehicle
HybridVehicle::operator float() const
{
    if (gasolineUsed == 0)
    {
        return 0;
    }
    else
    {
        return gasolineKm / gasolineUsed;
    }
}

// Overloading << output operator to get the details of vehicle
std::ostream &operator<<(std::ostream &out, const HybridVehicle &vehicle)
{
    out << "Model: " << vehicle.modelName
        << "\nElectric Km: " << vehicle.electricKm
        << "\nGasoline Km: " << vehicle.gasolineKm
        << "\nGasoline Used: " << vehicle.gasolineUsed
        << "\nEfficiency: " << float(vehicle) << " km/L"
        << "\nTrips: ";
    for (int i = 0; i < vehicle.tripCount; ++i)
    {
        out << vehicle.trips[i] << " ";
    }
    out << "\nTotal Distance: " << vehicle() << " km\n";
    return out;
}