#include <iostream>
#include "Amuljot_Oct8_task2_DiagnosticReport.h"

int main()
{
    DiagnosticReport report;

    report.addReading(SensorReading("EngineTemp", 105, SeverityLevel::High));
    report.addReading(SensorReading("OilPressure", 20, SeverityLevel::Medium));
    report.addReading(SensorReading("BrakeFluidLevel", 5, SeverityLevel::Critical));
    report.addReading(SensorReading("BatteryVoltage", 12.5, SeverityLevel::Low));

    std::cout << "\nAll Sensor Readings:\n";
    report.displayAllReadings();

    std::cout << "\nSeverity Distribution:\n";
    report.severityDistribution();

    std::cout << "\nSorted by Severity (Descending):\n";
    report.sortBySeverityDescending();
    report.displayAllReadings();

    std::cout << "\nFiltered: Critical Readings Only:\n";
    int criticalCount = 0;
    SensorReading *criticals = report.filterBySeverity(SeverityLevel::Critical, criticalCount);
    if (criticals)
    {
        for (int i = 0; i < criticalCount; ++i)
        {
            criticals[i].displayReading();
        }
        delete[] criticals;
    }

    std::cout << "\nFinding: BrakeFluidLevel\n";
    SensorReading *found = report.findReadingByName("BrakeFluidLevel");
    if (found)
    {
        found->displayReading();
    }
    else
    {
        std::cout << "Sensor not found.\n";
    }

    return 0;
}
