#include <iostream>
#include <map>
#include "Amuljot_Oct8_task2_DiagnosticReport.h"

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

// Function returns all readings that match given severity exactly
SensorReading *DiagnosticReport::filterBySeverity(SeverityLevel level, int &count) const
{
    count = 0; // set default value of count to 0
    for (int i = 0; i < sensors_readings.size(); i++)
    {
        if (sensors_readings[i].getSeverityLevel() == level) // count the number of readings with given severityLevel
        {
            count++;
        }
    }

    if (count == 0)
        return nullptr; // if not present any then return nullptr

    SensorReading *filteredReadings = new SensorReading[count]; // created an array of size count

    int index = 0; // index for accesing filtered reading
    for (const auto &reading : sensors_readings)
    {
        if (reading.getSeverityLevel() == level)
        {
            filteredReadings[index++] = reading; // Add the readings that match given severity in filtered readings array
        }
    }
    return filteredReadings; // return filteredreadings
}

// Sort the Readings in descending order
void DiagnosticReport::sortBySeverityDescending()
{

    int size = sensors_readings.size();
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (sensors_readings[j].getSeverityLevel() < sensors_readings[j + 1].getSeverityLevel())
            {
                std::swap(sensors_readings[j], sensors_readings[j + 1]);
            }
        }
    }
}

// Display Severity Distribution Map
void DiagnosticReport::severityDistribution() const
{
    int size = sensors_readings.size();
    std::map<SeverityLevel, int> severityDistributionMap; // used map to store severity and their count

    for (const auto &reading : sensors_readings)
    {
        severityDistributionMap[reading.getSeverityLevel()]++; // Map all severity
    }

    std::cout << "Severity Distribution:\n";
    for (const auto &pair : severityDistributionMap)
    {
        std::cout << SensorReading::severityToString(pair.first) << ": " << pair.second << std::endl; // Display all Severity Level with their counts
    }
}

// Function to find reading by sensor name
SensorReading *DiagnosticReport::findReadingByName(const std::string &name)
{
    for (auto &reading : sensors_readings)
    {
        if (reading.getSensorName() == name) // find reading by name of sensor
        {
            return &reading; // return pointer to reading
        }
    }
    return nullptr; // return nullptr if there is not a reading as given sensor name
}
