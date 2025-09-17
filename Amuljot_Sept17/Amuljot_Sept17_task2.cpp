#include <iostream>
#include <cstdint> //for unint32_t
#include <limits>  // Required for std::numeric_limits

class TrackedVehicle
{
private:
    uint32_t vehicle_id;                // Identifier of Vehicle
    float speed;                        // Speed of vehicle
    float distance;                     // Distance of vehicle
    static float min_recorded_distance; // Minimum recorder distance
    static int vehicle_count;           // Number of vehicles

public:
    // Default Constructor
    TrackedVehicle() : vehicle_id(0), speed(0.0f), distance(0.0f)
    {
        vehicle_count++;
    }
    // Constructor
    TrackedVehicle(uint32_t vehicle_id, float speed, float distance) : vehicle_id(vehicle_id), speed(speed), distance(distance)
    {
        // updating minimum recorded distance if current vehicle’s distance is smaller
        if (distance < min_recorded_distance)
        {
            min_recorded_distance = distance;
        }

        // Incrementing vehicle count each time new object is created
        vehicle_count++;
    }

    // Getter functions
    uint32_t getVehicleID() const
    {
        return vehicle_id;
    }

    float getSpeed() const
    {
        return speed;
    }

    float getDistance() const
    {
        return distance;
    }

    // Member Functions

    //  Function to display the information
    void display() const
    {
        std::cout << "\nVehicle Details->\n";
        std::cout << "Vehicle ID: " << vehicle_id << std::endl;
        std::cout << "Speed: " << speed << " km/h " << std::endl;
        std::cout << "Distance: " << distance << " m" << std::endl;
        std::cout << std::endl;
    }

    // Function to return pointer of vehicle with smaller distance
    const TrackedVehicle *compareDistance(const TrackedVehicle &other) const
    {
        if (other.getDistance() < distance)
        {
            return &other;
        }
        return this;
    }

    // Function to get minimum recorded distance
    static float getMinRecordedDistance()
    {
        return min_recorded_distance;
    }

    // Function to get the vehicle count
    static int getVehicleCount()
    {
        return vehicle_count;
    }
};

// Initialize static members
float TrackedVehicle::min_recorded_distance = std::numeric_limits<float>::max();
int TrackedVehicle::vehicle_count = 0;

// Function to get lead vehicle with smallest distance
void findLeadVehicle(TrackedVehicle *arr, uint32_t size, const TrackedVehicle *&lead)
{
    if (size == 0 || arr == nullptr)
    {
        lead = nullptr;
        return;
    }

    lead = &arr[0];

    for (uint32_t i = 0; i < size; i++)
    {
        if (arr[i].getDistance() < lead->getDistance())
        {
            lead = &arr[i];
        }
    }
}
// Global functions

// Function to print a tracked vehicle's details
void printTrackedVehicle(const TrackedVehicle &vehicle)
{
    vehicle.display();
}

// Function to print lead vehicle's details
void printLeadVehicle(const TrackedVehicle *lead)
{
    if (lead)
    {
        std::cout << "Lead Vehicle is: " << std::endl;
        printTrackedVehicle(*lead);
    }
    else
    {
        std::cout << "None Found" << std::endl;
    }
}

TrackedVehicle *createTrackedVehicles(uint32_t &size)
{
    size = 4; // Number of vehicles is 4

    // Directly initialize with constructor arguments
    TrackedVehicle *vehicles = new TrackedVehicle[size]{
        TrackedVehicle(501, 80.0f, 60.0f),
        TrackedVehicle(502, 78.0f, 45.0f),
        TrackedVehicle(503, 85.0f, 100.0f),
        TrackedVehicle(504, 76.0f, 40.0f)};

    return vehicles;
}

int main()
{
    uint32_t size = 0;
    // Create tracked vehicles dynamically
    TrackedVehicle *vehicles = createTrackedVehicles(size);

    // Find Lead Vehicle
    const TrackedVehicle *lead = nullptr;
    findLeadVehicle(vehicles, size, lead);

    // Print all Vehicle details
    std::cout << "All Tracked Vehicles:\n";
    for (uint32_t i = 0; i < size; ++i)
    {
        printTrackedVehicle(vehicles[i]);
    }

    // Print Lead Vehicle
    printLeadVehicle(lead);

    // Print the minimum recorded distance
    std::cout << "Minimum Recorded Distance: " << TrackedVehicle::getMinRecordedDistance() << " m\n";

    // Print the total number of tracked vehicles
    std::cout << "Total Vehicles Created: " << TrackedVehicle::getVehicleCount() << "\n";

    //    deallocate the heap memory
    delete[] vehicles;

    return 0;
}
