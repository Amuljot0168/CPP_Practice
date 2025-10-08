#include "Amuljot_Oct8_task1_SensorReading.h"
#include <iostream>

// Constructor initializing all attributes
SensorReading::SensorReading(std::string name, double val, SeverityLevel level) : sensorName(name), value(val), severity(level) {}

// Function display the reading
void SensorReading::displayReading() const
{
    std::cout << "\nSensor name: " << sensorName << std::endl;
    std::cout << "Sensor Value: " << value << std::endl;
    std::cout << "Severity: ";
    switch (severity)
    {
    case SeverityLevel::Low:
        std::cout << "Low";
        break;
    case SeverityLevel::Medium:
        std::cout << "Medium";
        break;
    case SeverityLevel::High:
        std::cout << "High";
        break;
    case SeverityLevel::Critical:
        std::cout << "Critical";
        break;

        std::cout << "Severity: " << severity << std::endl;
    }
}

// function to retrieve the severity level
SeverityLevel SensorReading::getSeverityLevel() const
{
    return severity; // return severity level
}