#include <iostream>
#include <limits> //For initializing global_max_temperature
enum SensorType
{
    LIDAR,
    RADAR,
    CAMERA
};
// declare the function
const char *sensorTypeToString(SensorType t);

class SensorArray
{
private:
    int sensor_id;                        // Unique identifier for sensors
    SensorType type;                      // Type of Sensor
    double *temperature_readings;         // Readings of temeperatures
    int num_readings;                     // Number of Readings
    static double global_max_temperature; // Globally Max Temperature captured

public:
    // Default Constructor
    SensorArray()
        : sensor_id(0), type(LIDAR), temperature_readings(nullptr), num_readings(0) {}

    // Parameterized Constructor
    SensorArray(int sensor_id, SensorType type, double *readings, int num_readings) : sensor_id(sensor_id), type(type), num_readings(num_readings)
    {
        temperature_readings = new double[num_readings];
        for (int i = 0; i < num_readings; i++)
        {
            temperature_readings[i] = readings[i];
            if (global_max_temperature < readings[i])
            {
                global_max_temperature = readings[i];
            }
        }
    }

    // Free the allocated memory
    ~SensorArray()
    {
        delete[] temperature_readings;
    }

    // Function return maxTemperature of the readings
    double getMaxTemperature() const
    {
        double maxTemperature = temperature_readings[0];

        for (int i = 1; i < num_readings; i++)
        {
            if (temperature_readings[i] > maxTemperature)
            {
                maxTemperature = temperature_readings[i];
            }
        }
        return maxTemperature;
    }

    // print Sensor Information
    void printSensorInfo() const
    {
        std::cout << "\nSensor Information: \n";
        std::cout << "Sensor ID: " << sensor_id << std::endl;
        std::cout << "Sensor Type: " << sensorTypeToString(type) << std::endl;
        std::cout << "Max Temperature: " << getMaxTemperature() << std::endl;
    }

    // Return global maximum temperature
    static double getGlobalMaxTemperature()
    {
        return global_max_temperature;
    }
};

// Global Functions

// Function to change enum Sensortype to string
const char *sensorTypeToString(SensorType t)
{
    switch (t)
    {
    case LIDAR:
    {
        return "LIDAR";
    }
    case RADAR:
    {
        return "RADAR";
    }
    case CAMERA:
    {
        return "CAMERA";
    }
    default:
        return "UNKNOWN";
    }
}

// Global function Print Sensor Information

// print Sensor inforamtion
void printSensor(const SensorArray &s)
{

    s.printSensorInfo();
}

// Function prints all sensors information
void printAllSensors(const SensorArray *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printSensor(arr[i]);
    }
}

// Function to dynamically allocate memory
SensorArray *createSensorArrayonHeap(int &size)
{
    // Sample temperature data
    double readings1[] = {35.5, 36.1, 34.9};
    double readings2[] = {39.0, 38.7, 39.3};
    double readings3[] = {30.2, 31.0, 30.5};

    // Dynamically allocate array of SensorArray objects

    SensorArray *sensors = new SensorArray[size]{
        SensorArray(801, LIDAR, readings1, 3),
        SensorArray(802, RADAR, readings2, 3),
        SensorArray(803, CAMERA, readings3, 3)};

    return sensors;
}
// Initialize static member outside the class
double SensorArray::global_max_temperature = std::numeric_limits<double>::lowest();
int main()
{
    // Create array of sensors
    int size = 3;
    SensorArray *sensors = createSensorArrayonHeap(size);

    // Print all sensor info
    std::cout << "All Sensor Information:\n";
    printAllSensors(sensors, size);

    // Print global max temperature
    std::cout << "\nGlobal Max Temperature Recorded: " << SensorArray::getGlobalMaxTemperature() << " C\n";

    // Clean Up Memory
    delete[] sensors;

    return 0;
}
