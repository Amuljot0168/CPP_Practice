#include <iostream>
#include <string>
#include "Amuljot_Oct1_task2_BatteryMonitor.h"

// Constructor
BatteryMonitor::BatteryMonitor(std::string id, int cycles, float bCapacity, float orgCapacity, bool active, int tripCount) : scooterID(id), chargeCycles(cycles), batteryCapacity(bCapacity), originalCapacity(orgCapacity), isActive(active), tripCount(tripCount)
{
    tripDistances = new int[tripCount]; // Dynamically allocating memory
    for (int i = 0; i < tripCount; i++) // Initialize all trips distance to 0
    {
        tripDistances[i] = 0;
    }
}

// Copy Constructor
BatteryMonitor::BatteryMonitor(const BatteryMonitor &other) : scooterID(other.scooterID), chargeCycles(other.chargeCycles), batteryCapacity(other.batteryCapacity), originalCapacity(other.originalCapacity), isActive(other.isActive), tripCount(other.tripCount)
{
    // Making Deep Copy of trips Distances
    tripDistances = new int[tripCount];
    for (int i = 0; i < tripCount; i++)
    {
        tripDistances[i] = other.tripDistances[i];
    }
}

// Destructor (Free Up Memory)
BatteryMonitor::~BatteryMonitor()
{
    delete[] tripDistances;
    std::cout << "Memory cleaned Up by Destructor " << scooterID << "\n";
}

// Overloading = operator to assign the values as deep copy
BatteryMonitor &BatteryMonitor::operator=(const BatteryMonitor &other)
{
    if (this != &other)
    {
        scooterID = other.scooterID;
        chargeCycles = other.chargeCycles;
        batteryCapacity = other.batteryCapacity;
        originalCapacity = other.originalCapacity;
        isActive = other.isActive;
        tripCount = other.tripCount;

        // Deep Copy
        delete[] tripDistances;
        tripDistances = new int[tripCount];
        for (int i = 0; i < tripCount; i++)
        {
            tripDistances[i] = other.tripDistances[i];
        }
    }
    return *this;
}

// Overloading < operator to compare the Capacity ratio of both Battery Monitors
bool BatteryMonitor::operator<(const BatteryMonitor &other) const
{
    float curr_capacityRatio = batteryCapacity / originalCapacity;
    float other_capacityRatio = other.batteryCapacity / other.originalCapacity;

    if (curr_capacityRatio < other_capacityRatio)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Overloading > operator to compare the Capacity ratio of both Battery Monitors
bool BatteryMonitor::operator>(const BatteryMonitor &other) const
{
    float curr_capacityRatio = batteryCapacity / originalCapacity;
    float other_capacityRatio = other.batteryCapacity / other.originalCapacity;

    if (curr_capacityRatio > other_capacityRatio)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Overloading += operator to Add    charge    cycles    and    simulate degradation
void BatteryMonitor::operator+=(int degradation)
{
    chargeCycles += degradation;
    // Simulate degradation: reduce battery capacity by 0.01 kWh per cycle
    batteryCapacity -= degradation * 0.01;
    if (batteryCapacity < 0)
        batteryCapacity = 0; // prevent negative capacity
}

// For Accessing the element of tripDistances of current Battery Monitor
int &BatteryMonitor::operator[](int index)
{
    if (index >= tripCount || index < 0)
    {
        static int dummy = -1;
        std::cout << "Index is not valid!!!\n\n";
        return dummy;
    }
    return tripDistances[index];
}

// Check status of Battery Monitor is InActive or not
bool BatteryMonitor::operator!() const
{
    if (isActive)
    {
        return false; // return false if scooter is active
    }
    return true; // return true if scooter is inactive
}

// Print The Details of Battery Monitor
std::ostream &operator<<(std::ostream &out, const BatteryMonitor &batterymonitor)
{
    out << "\nScooterID: " << batterymonitor.scooterID << std::endl;
    out << "Charge Cycles: " << batterymonitor.chargeCycles << std::endl;
    out << "Battery Capacity: " << batterymonitor.batteryCapacity << std::endl;
    out << "Original Capacity: " << batterymonitor.originalCapacity << std::endl;
    out << "Is Active: " << ((batterymonitor.isActive) ? "Active" : "InActive") << std::endl;
    out << "Trip Counts: " << batterymonitor.tripCount << std::endl;

    out << "Trips: ";
    for (int i = 0; i < batterymonitor.tripCount; i++)
    {
        out << batterymonitor.tripDistances[i] << " ";
    }

    std::cout << "\n";

    float batteryHealth;
    if (batterymonitor.originalCapacity > 0)
    {
        batteryHealth = batterymonitor.batteryCapacity / batterymonitor.originalCapacity;
    }
    else
    {
        batteryHealth = 0;
    }

    std::cout << "Battery Health: " << batteryHealth * 100 << "%\n\n";
    return out;
}