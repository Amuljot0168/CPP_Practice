#include <iostream>

#include "Amuljot_Oct8_task1_DiagnosticReport.h"

int main()
{
    // created object of DiagnosticReport
    DiagnosticReport report;

    // Adding sample readings to report
    report.addReading(SensorReading("EngineTemp", 105, High));
    report.addReading(SensorReading("OilPressure", 20, SeverityLevel::Medium));
    report.addReading(SensorReading("BrakeFluidLevel", 5, SeverityLevel::Critical));
    report.addReading(SensorReading("BatteryVoltage", 12.5, SeverityLevel::Low));

    // Display all sensors readings
    std::cout << "All Sensor Readings:\n";
    report.displayAllReadings();

    // Count of readings which severityLevel is High or Critical
    int severeCount = report.countReadings(SeverityLevel::High);
    std::cout << "\nReadings with severity High or Critical: " << severeCount << std::endl;

    return 0;
}