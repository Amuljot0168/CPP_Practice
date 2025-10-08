#ifndef SENSOR_READING_H
#define SENSOR_READING_H

#include <string>
#include "Amuljot_Oct8_task1_SeverityLevel.h"

class SensorReading
{
private:
    std::string sensorName; // name of sensor
    double value;           // value of sensor reading
    SeverityLevel severity; // severity level of sensor

public:
    // Parameterised Constructor
    SensorReading(std::string, double, SeverityLevel);

    // Display the readings
    void displayReading() const;

    // get severity level
    SeverityLevel getSeverityLevel() const;
};
#endif