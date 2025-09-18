#include <iostream>

class EgoVehicleData
{
private:
    // Data Members
    int num_lanes;
    float *lane_positions;
    float *sensor_confidence;

public:
    // Default Constructor
    EgoVehicleData() : num_lanes(0), lane_positions(nullptr), sensor_confidence(nullptr) {}

    // Parameterized Constructor
    EgoVehicleData(int num_lanes, const float *positions, const float *confidences) : num_lanes(num_lanes)
    {
        if (num_lanes <= 0 || positions == nullptr || confidences == nullptr)
        {
            throw std::invalid_argument("Invalid Input! ");
        }

        lane_positions = new float[num_lanes];
        sensor_confidence = new float[num_lanes]; // Assuming one sensor per lane

        for (int i = 0; i < num_lanes; i++)
        {
            lane_positions[i] = positions[i];
            sensor_confidence[i] = confidences[i];
        }
    }

    // Destructor
    ~EgoVehicleData()
    {
        delete[] lane_positions;
        delete[] sensor_confidence;
    }

    // Copy Constructor
    EgoVehicleData(const EgoVehicleData &other) : num_lanes(other.num_lanes)
    {
        lane_positions = new float[num_lanes];
        sensor_confidence = new float[num_lanes];
        for (int i = 0; i < num_lanes; ++i)
        {
            lane_positions[i] = other.lane_positions[i];
            sensor_confidence[i] = other.sensor_confidence[i];
        }
    }

    // Assignment Operator
    EgoVehicleData &operator=(const EgoVehicleData &other)
    {
        if (this == &other)
            return *this;

        delete[] lane_positions;
        delete[] sensor_confidence;

        num_lanes = other.num_lanes;
        lane_positions = new float[num_lanes];
        sensor_confidence = new float[num_lanes];
        for (int i = 0; i < num_lanes; ++i)
        {
            lane_positions[i] = other.lane_positions[i];
            sensor_confidence[i] = other.sensor_confidence[i];
        }
        return *this;
    }

    // Public Getters
    int getNumLanes() const { return num_lanes; }
    const float *getLanePositions() const { return lane_positions; }
    const float *getSensorConfidence() const { return sensor_confidence; }

    // Const function to get averaf=ge of lane positions
    float getAverageLanePosition() const
    {
        float sum_LanePosition = 0.0f;

        for (int i = 0; i < num_lanes; i++)
        {
            sum_LanePosition += lane_positions[i];
        }

        return sum_LanePosition / num_lanes;
    }
    // Function to update Sensor Confidence
    void updateSensorConfidence(float factor)
    {
        for (int i = 0; i < num_lanes; i++)
        {
            sensor_confidence[i] *= factor;
        }
    }

    // Sum of sensor confidence
    float getTotalConfidence() const
    {
        float sum = 0.0f;
        for (int i = 0; i < num_lanes; ++i)
            sum += sensor_confidence[i];
        return sum;
    }
};

// Global Functions
// Function to find highest Confidence vehicle
void findHighestConfidenceVehicle(EgoVehicleData *array, int size, const EgoVehicleData *&highest)
{
    if (size <= 0 || array == nullptr)
    {
        highest = nullptr;
        return;
    }
    highest = &array[0];
    float max_confidence = highest->getTotalConfidence();
    for (int i = 1; i < size; i++)
    {
        if (array[i].getTotalConfidence() > max_confidence)
        {
            max_confidence = array[i].getTotalConfidence();
            highest = &array[i];
        }
    }
}

// Function to print ego vehicle Data
void printEgoVehicleData(const EgoVehicleData &data)
{

    const float *lane_positions = data.getLanePositions();
    const float *sensor_confidence = data.getSensorConfidence();

    std::cout << "\nVehicle Data->\n";
    std::cout << "Vehicle Lane Positions: \n";

    for (int i = 0; i < data.getNumLanes(); i++)
    {
        std::cout << " Lane " << i << " : " << lane_positions[i] << std::endl;
    }

    std::cout << "\nVehicle Sensor Confidences: \n";

    for (int i = 0; i < data.getNumLanes(); i++)
    {
        std::cout << " Lane " << i << " : " << sensor_confidence[i] << std::endl;
    }
    std::cout << std::endl;
}

// function to print highest confidence vehicle
void printHighestConfidenceVehicle(const EgoVehicleData *vehicle)
{
    if (vehicle == nullptr)
    {
        std::cout << "No vehicle data available.\n";
    }
    else
    {
        std::cout << "Vehicle with Highest Confidence:\n";
        printEgoVehicleData(*vehicle);
    }
}

// Function to dynamically allocate memory
EgoVehicleData *createEgoVehicleOnHeap(int &size)
{
    float lane1[] = {3.2f, 3.0f, 3.4f};
    float conf1[] = {0.95f, 0.97f, 0.93f};

    float lane2[] = {2.9f, 2.8f, 3.1f};
    float conf2[] = {0.92f, 0.90f, 0.88f};

    float lane3[] = {3.4f, 3.5f, 3.6f};
    float conf3[] = {0.99f, 0.98f, 0.97f};
    EgoVehicleData *vehicles = new EgoVehicleData[size]{
        // Update confidence scores
        EgoVehicleData(3, lane1, conf1),
        EgoVehicleData(3, lane2, conf2),
        EgoVehicleData(3, lane3, conf3)};

    return vehicles;
}

int main()
{
    // Dynamically allocate memory
    int size = 3;
    EgoVehicleData *vehicles = createEgoVehicleOnHeap(size);

    // Update confidence scores
    vehicles[0].updateSensorConfidence(1.05f);
    vehicles[1].updateSensorConfidence(1.10f);
    vehicles[2].updateSensorConfidence(1.02f);

    // Print all vehicles
    for (int i = 0; i < size; ++i)
    {
        std::cout << "Vehicle " << i + 1 << ":\n";
        printEgoVehicleData(vehicles[i]);
    }

    // Find and print highest confidence vehicle
    const EgoVehicleData *highest = nullptr;
    findHighestConfidenceVehicle(vehicles, size, highest);

    printHighestConfidenceVehicle(highest);

    delete[] vehicles;
    return 0;
}