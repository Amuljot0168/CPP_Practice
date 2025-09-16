// Sensor Fusion for Object Distance Estimation in ADAS

#include <iostream>

// Class
class ObjectDistance
{
    // Data Members
public:
    float radar_distance;
    float camera_distance;

    // Parameterized Constructor of class
    ObjectDistance(float radar_distance, float camera_distance)
    {
        if (radar_distance < 0.0f || camera_distance < 0.0f)
        {
            throw std::invalid_argument("Invalid radar distance or camera distance");
        }
        this->radar_distance = radar_distance;
        this->camera_distance = camera_distance;
    }

    // Function adjust values to the copy of object
    void adjustDistancesByValue(ObjectDistance obj)
    {
        obj.camera_distance += 5.0;
        obj.radar_distance += 5.0;
    }

    // Function adjust values to the reference of actual object
    void adjustDistancesByReference(ObjectDistance &obj)
    {
        obj.camera_distance += 5.0;
        obj.radar_distance += 5.0;
    }
};

// Print the distances of object
void printObjectDistance(const ObjectDistance &obj)
{
    std::cout << "\nRadar Distance : " << obj.radar_distance << std::endl;
    std::cout << "Camera Distance: " << obj.camera_distance << std::endl;
    std::cout << std::endl;
}

// Create Dynamically allocated object on heap memory
ObjectDistance *createObjectDistanceOnHeap(float radar, float camera)
{
    ObjectDistance *Object = new ObjectDistance(radar, camera);
    return Object;
}
int main()
{
    ObjectDistance *Object1 = createObjectDistanceOnHeap(35.5, 34.8);

    // Initial Distances Value
    std::cout << "Current Distances: " << std::endl;
    printObjectDistance(*Object1);

    // Call pass by value function
    std::cout << "Calling adjustDistancesByValue (No change expected): " << std::endl;
    Object1->adjustDistancesByValue(*Object1); // Pass by Value
    printObjectDistance(*Object1);             // No changes happened

    // Call Pass by reference function
    std::cout << "Calling adjustDistancesByReference (changes expected): " << std::endl;
    Object1->adjustDistancesByReference(*Object1); // Pass by reference
    printObjectDistance(*Object1);                 // distance values updated by +5.0

    // Delete Heap object
    delete Object1;

    return 0;
}