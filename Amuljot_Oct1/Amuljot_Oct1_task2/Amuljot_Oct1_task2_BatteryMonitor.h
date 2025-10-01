#ifndef BATTERY_MONITOR_H
#define BATTERY_MONITOR_H

#include <string>
class BatteryMonitor
{
private:
    std::string scooterID;
    int chargeCycles;
    float batteryCapacity;  // — current capacity in kWh;
    float originalCapacity; // — original capacity in kWh;
    bool isActive;
    int *tripDistances; // — dynamically allocated array of trip distances;
    int tripCount;      // — number of trips

public:
    // Constructors
    BatteryMonitor(std::string id, int cycles, float bCapacity, float orgCapacity, bool active, int tCount);
    BatteryMonitor(const BatteryMonitor &other);
    ~BatteryMonitor();

    // Operators to overload
    BatteryMonitor &operator=(const BatteryMonitor &other);
    bool operator>(const BatteryMonitor &other) const;
    bool operator<(const BatteryMonitor &other) const;
    void operator+=(int degradation);
    int &operator[](int index);
    bool operator!() const;
    friend std::ostream &operator<<(std::ostream &out, const BatteryMonitor &other);
};

#endif