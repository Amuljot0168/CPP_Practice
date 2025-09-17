#include <iostream>
#include <cstdint> // for uint32_t

class Pedestrian
{
private:
    // Data members
    uint32_t pedestrian_id; // Unsigned 32 bits integer
    float distance_from_vehicle;

public:
    // Constructor of the class
    Pedestrian(uint32_t pedestrian_id, float distance) : pedestrian_id(pedestrian_id), distance_from_vehicle(distance) {}

    // Getter function
    uint32_t getPedestrianID() const
    {
        return pedestrian_id;
    }

    // Setter function
    void setPedestrianID(uint32_t ped_id)
    {
        pedestrian_id = ped_id;
    }

    // Member functions

    // Function which updates the distance like setter
    void updateDistance(float newDistance)
    {
        distance_from_vehicle = newDistance;
    }

    // Function to get distance (works like getter)
    float getDistance() const
    {
        return distance_from_vehicle;
    }
};

// Function to find closest pedestrian to vehicle
void findClosestPedestrian(Pedestrian *array, uint32_t size, const Pedestrian *&closest)
{
    // if size of array is zero or pointer points to nullptr then closest is a nullptr
    if (size == 0 || array == nullptr)
    {
        closest = nullptr;
        return;
    }

    closest = &array[0]; // assume and assign first element is closest

    // Loop to check which pedestrian has smallest distance from vehicle
    for (uint32_t i = 0; i < size; i++)
    {
        if (array[i].getDistance() < closest->getDistance())
        {
            closest = &array[i];
        }
    }
}

// Global functions

// Function to print pedestrian information
void printPedestrianInfo(const Pedestrian &ped)
{
    std::cout << "\nPedestrian Information \n";
    std::cout << "Pedestrian ID: " << ped.getPedestrianID() << std::endl;
    std::cout << "Pedestrian Distance from Vehcile : " << ped.getDistance() << std::endl;
    std::cout << std::endl;
}

// Print closest pedestrian information
void printClosestPedestrian(const Pedestrian *closest)
{
    // not nullptr then print closest one
    if (closest)
    {
        std::cout << "Closest Pedestrian is: " << std::endl;
        printPedestrianInfo(*closest);
    }
    else
    {
        std::cout << "No Pedestrian is Closest." << std::endl;
    }
}

int main()
{
    // Number of Pedestrian  is 3
    const uint32_t number_of_pedestrains = 3;

    // Dynamically allocating the memory
    Pedestrian *pedestrians = new Pedestrian[number_of_pedestrains]{
        Pedestrian(101, 12.4f),
        Pedestrian(102, 8.7f),
        Pedestrian(103, 15.1f)};

    // Find the closest pedestrian
    const Pedestrian *closest = nullptr;
    findClosestPedestrian(pedestrians, number_of_pedestrains, closest);

    // Print all pedestrian Inforomation
    std::cout << "All Pedestrians->\n";
    for (uint32_t i = 0; i < number_of_pedestrains; i++)
    {
        printPedestrianInfo(pedestrians[i]);
    }

    // Print the closest Pedestrian
    printClosestPedestrian(closest);

    // Clean Up Memory
    delete[] pedestrians;
    return 0;
}