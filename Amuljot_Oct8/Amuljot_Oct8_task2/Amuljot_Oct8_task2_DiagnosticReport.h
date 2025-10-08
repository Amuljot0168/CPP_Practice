#ifndef DIAGNOSTIC_REPORT_H
#define DIAGNOSTIC_REPORT_H

#include "Amuljot_Oct8_task2_SensorReading.h"
#include <vector>
class DiagnosticReport
{
private:
    std::vector<SensorReading> sensors_readings;

public:
    // Add a new sensor reading
    void addReading(const SensorReading &reading);

    // Display all readings
    void displayAllReadings() const;

    // count number of readings of given severity or higher
    int countReadings(SeverityLevel level) const;

    // Severity based filtering
    SensorReading *filterBySeverity(SeverityLevel level, int &count) const;

    // sort readings in descending order of severity
    void sortBySeverityDescending();

    // Severity Distribution
    void severityDistribution() const;

    // Search the readings by sensor name
    SensorReading *findReadingByName(const std::string &name);
};
#endif