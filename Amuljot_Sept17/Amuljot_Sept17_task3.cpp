// Question 3: ADAS Forward Collision Warning

#include <iostream>
#include <cstdint> //for uint32_t

class DetectedObject
{
private:
    uint32_t object_id; // Unique identifier for object
    float rel_speed;    // Relative Speed
    float distance;     // Distance from ego vehicle

public:
    // Default Constructor
    DetectedObject() : object_id(0), rel_speed(0.0f), distance(0.0f) {}

    //  Parameterized Constructor
    DetectedObject(uint32_t object_id, float rel_speed, float distance) : object_id(object_id), rel_speed(rel_speed), distance(distance) {}

    // Getter functions
    uint32_t getObjectID() const
    {
        return object_id;
    }

    float getRelativeSpeed() const
    {
        return rel_speed;
    }

    float getDistance() const
    {
        return distance;
    }

    // function to display the detail of object
    void display() const
    {
        std::cout << "\nDetected Object Details: \n";
        std::cout << "Object ID: " << object_id << std::endl;
        std::cout << "Relative Speed: " << rel_speed << std::endl;
        std::cout << "Distance: " << distance << std::endl;
        std::cout << std::endl;
    }

    // Check if object has smaller distance and high rel_speed than other
    bool isHigherRisk(const DetectedObject &other) const
    {
        return (this->getDistance() < other.getDistance()) && (this->getRelativeSpeed() > other.getRelativeSpeed());
    }

    // Modifies the copy of object (No effect on original values)
    void updateValuesByValue(DetectedObject obj)
    {
        obj.rel_speed += 2;
        obj.distance -= 5;
    }

    // Modifies the actual value
    void updateValuesByReference(DetectedObject &obj)
    {
        obj.rel_speed += 2.0;
        obj.distance -= 5.0;
    }
};

// Global Functions

// Function to dynamically allocate and initialize detected objects
DetectedObject *createDetectedObjectOnHeap(uint32_t &size)
{

    DetectedObject *objects = new DetectedObject[size]{
        DetectedObject(701, 15.0f, 55.0f),
        DetectedObject(702, 20.0f, 35.0f),
        DetectedObject(703, 10.0f, 30.0f),
        DetectedObject(704, 25.0f, 40.0f)};

    return objects;
}

// Function to find highest risk object
void findHighestRiskObject(DetectedObject *arr, uint32_t size, const DetectedObject *&riskObj)
{
    if (size == 0 || arr == nullptr)
    {
        riskObj = nullptr;
        return;
    }

    riskObj = &arr[0];

    for (int i = 1; i < size; i++)
    {
        if (arr[i].isHigherRisk(*riskObj))
        {
            riskObj = &arr[i];
        }
    }
}

// print a sepecific object
void printDetectedObject(const DetectedObject &obj)
{
    obj.display();
}

// Print Highest Risk Object
void printHighestRiskObject(const DetectedObject *obj)
{
    if (obj)
    {
        std::cout << "Highest Risk Object->";
        printDetectedObject(*obj);
    }
    else
    {
        std::cout << "Warning obj is a nullptr!" << std::endl;
    }
}

// Function to update values by call by value and also printing the objects
void updateObjectValuesByValueGlobal(DetectedObject obj)
{
    obj.updateValuesByValue(obj);
    printDetectedObject(obj);
}

// Function to update values by call by reference and also printing the objects
void updateObjectValuesByReferenceGlobal(DetectedObject &obj)
{
    obj.updateValuesByReference(obj);
    printDetectedObject(obj);
}

int main()
{
    // Dynamically allocated Memory
    uint32_t size = 4;
    DetectedObject *objects = createDetectedObjectOnHeap(size);

    // Initial Detected Object 3rd object
    printDetectedObject(objects[2]); // Let's take object[2]

    // After updated values (after calling by value)
    std::cout << "Calling  updateObjectValuesByValueGlobal function (Call By Value): \n";
    updateObjectValuesByValueGlobal(objects[2]);

    // After updated values (after calling by refernce)
    std::cout << "Calling  updateObjectValuesByReferenceGlobal function (Call By Reference): \n";
    updateObjectValuesByReferenceGlobal(objects[2]);

    // Find and print highest risk object
    const DetectedObject *riskObj = nullptr;
    findHighestRiskObject(objects, size, riskObj);
    printHighestRiskObject(riskObj);

    // Clean up memory
    delete[] objects;

    return 0;
}