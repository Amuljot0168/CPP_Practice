#include <iostream>
#include "Amuljot_Oct8_task1_DiagnosticReport.h"

// Add Reading in the collection
void DiagnosticReport::addReading(const SensorReading &reading)
{
    sensors_readings.push_back(reading);
}

// Display all sensor readings
void DiagnosticReport::displayAllReadings() const
{
    int size = sensors_readings.size();
    for (int i = 0; i < size; i++)
    {
        sensors_readings[i].displayReading();
        std::cout << std::endl;
    }
}

// Method to count how many readings are of a given severity or higher
int DiagnosticReport::countReadings(SeverityLevel level) const
{
    int count = 0;
    int size = sensors_readings.size();
    for (int i = 0; i < size; i++)
    {
        if (sensors_readings[i].getSeverityLevel() >= level)
        {
            count++;
        }
    }
    return count;
}
