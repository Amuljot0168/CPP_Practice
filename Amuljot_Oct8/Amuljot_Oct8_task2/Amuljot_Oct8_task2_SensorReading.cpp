#include "Amuljot_Oct8_task2_SensorReading.h"
#include <iostream>

// Default Constructor
SensorReading::SensorReading()
{
    sensorName = "";
    value = 0;
    severity = SeverityLevel::Low;
}

// Constructor initializing all attributes
SensorReading::SensorReading(std::string name, double val, SeverityLevel level) : sensorName(name), value(val), severity(level) {}

// Static function to convert Severity to string
std::string SensorReading::severityToString(SeverityLevel level)
{
    switch (level)
    {
    case SeverityLevel::Low:
        return "Low";

    case SeverityLevel::Medium:
        return "Medium";

    case SeverityLevel::High:
        return "High";

    case SeverityLevel::Critical:
        return "Critical";

    default:
        return "Unknown";
    }
}

// Function display the reading
void SensorReading::displayReading() const
{
    std::cout << "\nSensor name: " << sensorName << std::endl;
    std::cout << "Sensor Value: " << value << std::endl;
    std::cout << "Severity: " << severityToString(severity) << std::endl;
}

// function to retrieve the severity level
SeverityLevel SensorReading::getSeverityLevel() const
{
    return severity; // return severity level
}

// Function to get Sensor name
std::string SensorReading::getSensorName() const
{
    return sensorName;
}