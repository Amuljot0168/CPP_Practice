
#include <iostream>

class VehicleStatus
{
private:
    int num_wheels;
    float *wheel_speed;
    int num_temps;
    float *engine_temp;

public:
    // Constructor of class
    VehicleStatus(int num_wheels, float *speed, int num_temps, float *e_temp) : num_wheels(num_wheels), num_temps(num_temps)
    {
        wheel_speed = new float[num_wheels];
        for (int i = 0; i < num_wheels; i++)
        {
            wheel_speed[i] = speed[i];
        }

        engine_temp = new float[num_temps];
        for (int i = 0; i < num_temps; i++)
        {
            engine_temp[i] = e_temp[i];
        }
    }

    // Destructor of class
    ~VehicleStatus()
    {
        delete[] wheel_speed;
        delete[] engine_temp;
    }

    // Getter functions
    int getNumberOfWheels() const
    {
        return num_wheels;
    }

    const float *getWheelSpeeds() const
    {
        return wheel_speed;
    }

    int getNumberOfTemps() const
    {
        return num_temps;
    }

    const float *getEngineTemp() const
    {
        return engine_temp;
    }

    // Member Functions

    // Function to get average wheel speed
    float averageWheelSpeed() const
    {
        float sum_wheel_speed = 0.0f;
        for (int i = 0; i < num_wheels; i++)
        {
            sum_wheel_speed += wheel_speed[i];
        }

        float average_Wheel_Speed = sum_wheel_speed / num_wheels;
        return average_Wheel_Speed;
    }

    // Function to get Maximum Engine Temperature
    float maxEngineTemp() const
    {
        float max_Engine_Temp = engine_temp[0];
        for (int i = 0; i < num_temps; i++)
        {
            if (engine_temp[i] > max_Engine_Temp)
            {
                max_Engine_Temp = engine_temp[i];
            }
        }
        return max_Engine_Temp;
    }
    // Helper function to get maximum wheel speed
    float getMaximumWheelSpeed() const
    {
        float max_Wheel_Speed = wheel_speed[0];
        for (int i = 0; i < num_wheels; i++)
        {
            if (wheel_speed[i] > max_Wheel_Speed)
            {
                max_Wheel_Speed = wheel_speed[i];
            }
        }
        return max_Wheel_Speed;
    }
    // Function comapares which wheel speed is higher
    bool isWheelSpeedHigher(const VehicleStatus &other) const
    {
        return getMaximumWheelSpeed() > other.getMaximumWheelSpeed();
    }
};

// Global Functions
// Function to print Vehicle Status
void printVehicleStatus(const VehicleStatus &vs)
{
    const float *wheel_speeds_temp = vs.getWheelSpeeds();
    const float *engine_temp = vs.getEngineTemp();
    std::cout << "\nVehicle Status->\n";
    std::cout << "Vehicle Speeds->\n";
    for (int i = 0; i < vs.getNumberOfWheels(); i++)
    {
        std::cout << "Wheel " << i << " Speed is: " << wheel_speeds_temp[i] << std::endl;
    }

    std::cout << "\nVehicle Engine Temperature->\n";
    for (int i = 0; i < vs.getNumberOfTemps(); i++)
    {
        std::cout << "Engine " << i << " Temperature is: " << engine_temp[i] << std::endl;
    }
    std::cout << std::endl;
}

// Global Function: Compare the wheel speed
bool compareWheelSpeedGlobal(const VehicleStatus &vs1, const VehicleStatus &vs2)
{
    return vs1.isWheelSpeedHigher(vs2);
}

int main()
{
    float wheel1[] = {55.5f, 56.6f, 57.2f, 55.9f};
    float temp1[] = {90.5f, 88.9f};

    float wheel2[] = {50.0f, 51.2f, 49.8f, 50.4f};
    float temp2[] = {92.0f, 89.5f};

    // Dynamically allocating memory
    VehicleStatus *vehicle1 = new VehicleStatus(4, wheel1, 2, temp1);
    VehicleStatus *vehicle2 = new VehicleStatus(4, wheel2, 2, temp2);

    // Printing the status for Vehicle1
    std::cout << "Vehicle 1 Status:\n";
    printVehicleStatus(*vehicle1);

    // Printing average and Maximum Engine Temperature of Vehicle1
    std::cout << "Average Wheel Speed: " << vehicle1->averageWheelSpeed() << "\n";
    std::cout << "Max Engine Temp: " << vehicle1->maxEngineTemp() << "\n\n";

    // Print the status for vehicle2
    std::cout << "Vehicle 2 Status:\n";
    printVehicleStatus(*vehicle2);

    // Printing average and Maximum Engine Temperature of Vehicle2
    std::cout << "Average Wheel Speed: " << vehicle2->averageWheelSpeed() << "\n";
    std::cout << "Max Engine Temp: " << vehicle2->maxEngineTemp() << "\n\n";

    // Calling member function for checking which vehicle has higher speed
    std::cout << "Member Comparison: Vehicle 1 has higher wheel speed? "
              << (vehicle1->isWheelSpeedHigher(*vehicle2) ? "Yes" : "No") << "\n";

    // Calling global functions to compare wheel speed
    std::cout << "Global Comparison: Vehicle 1 has higher wheel speed? "
              << (compareWheelSpeedGlobal(*vehicle1, *vehicle2) ? "Yes" : "No") << "\n";

    // Clean Up Memory
    delete vehicle1;
    delete vehicle2;

    return 0;
}