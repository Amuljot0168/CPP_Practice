#ifndef SENSOR_READING_H
#define SENSOR_READING_H

#include <string>
#include "Amuljot_Oct8_task2_SeverityLevel.h"

class SensorReading
{
private:
    std::string sensorName; // name of sensor
    double value;           // value of sensor reading
    SeverityLevel severity; // severity level of sensor

public:
    // Default COnstructor
    SensorReading();
    // Parameterised Constructor
    SensorReading(std::string, double, SeverityLevel);

    // Severity Level to readable string
    static std::string severityToString(SeverityLevel level);

    // Display the readings
    void displayReading() const;

    // get severity level
    SeverityLevel getSeverityLevel() const;

    // get Sensor name
    std::string getSensorName() const;
};
#endif