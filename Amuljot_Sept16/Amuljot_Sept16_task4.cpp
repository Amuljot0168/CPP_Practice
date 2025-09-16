// Question 4: Radar Signal Strength Management in ADAS

#include <iostream>

class RadarSignal
{
public:
    // Data members
    int num_channels;
    float *signal_strength;

    // Constructor: allocate and initialize
    RadarSignal(int num_channels, float *signals)
    {
        // Validating input of channels must be greater than 0
        if (num_channels < 0)
        {
            throw std::invalid_argument("Channels must be non negative numbers.");
        }
        this->num_channels = num_channels;
        signal_strength = new float[num_channels];

        // Initializing values
        for (int index = 0; index < num_channels; index++)
        {
            signal_strength[index] = signals[index];
        }
    }

    // Copy Constructor to make a deep copy
    RadarSignal(const RadarSignal &other)
    {
        num_channels = other.num_channels;
        signal_strength = new float[num_channels];

        for (int index = 0; index < num_channels; index++)
        {
            signal_strength[index] = other.signal_strength[index];
        }
    }

    // Destructor: free memory
    ~RadarSignal()
    {
        delete[] signal_strength;
    }

    // Function to calculate average of signals
    float averageSignal() const
    {
        float signal_strength_sum = 0.0f;

        // loop to calculate the sum of signals
        for (int index = 0; index < num_channels; index++)
        {
            signal_strength_sum += signal_strength[index];
        }

        float average_strength = signal_strength_sum / num_channels; // average is stored in the variable
        return average_strength;                                     // return average of signals
    }

    // Boost by value (no effect on original)
    void boostSignalByValue(RadarSignal obj)
    {
        for (int i = 0; i < obj.num_channels; ++i)
        {
            obj.signal_strength[i] += 5.0f;
        }
    }

    // Boost by reference (modifies original)
    void boostSignalByReference(RadarSignal &obj)
    {
        for (int i = 0; i < obj.num_channels; ++i)
        {
            obj.signal_strength[i] += 5.0f;
        }
    }
};
// Global function: print signal strengths
void printRadarSignal(const RadarSignal &radar)
{
    std::cout << "Radar Signal Strengths:" << std::endl;
    for (int i = 0; i < radar.num_channels; ++i)
    {
        std::cout << "Channel " << i << ": " << radar.signal_strength[i] << std::endl;
    }
}

// Create RadarSignal on heap memory
RadarSignal *createRadarSignalHeap(int num, float *signals)
{
    return new RadarSignal(num, signals); // return a pointer
}

int main()
{

    // using Sample data
    int num_channels = 4;
    float signals[] = {55.5f, 48.2f, 60.1f, 52.6f};

    // Create Object on heap
    RadarSignal *radar = createRadarSignalHeap(num_channels, signals);

    // Initial Signal strengths
    std::cout << "Current Signal Strengths: " << std::endl;
    printRadarSignal(*radar);

    // Boost  by Value (No effect on original)
    radar->boostSignalByValue(*radar);

    std::cout << "\nAfter boostSignalByValue (original remains unchanged):" << std::endl;
    printRadarSignal(*radar); // display all radars signal strength

    // Boost by Reference (modifies signals)
    radar->boostSignalByReference(*radar);

    std::cout << "\nAfter boostSignalByReference (original modified):" << std::endl;
    printRadarSignal(*radar); // display all radars signal strength

    // Show average signal
    std::cout << "\nAverage Signal Strength: " << radar->averageSignal() << std::endl;

    // Clean up
    delete radar;

    return 0;
}