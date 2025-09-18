#include <iostream>
#include <string>

// Enum for Satellite Status
enum SatelliteStatus
{
    OPERATIONAL,
    MAINTENANCE,
    DECOMMISSIONED
};

class SatelliteData
{
    // Data members
private:
    int satellite_id;
    int num_antennas;
    float *signal_strength;
    float orbital_altitude;
    SatelliteStatus status;
    static int active_satellites;

public:
    // Constructor of class
    SatelliteData(int id, int number_of_anetennas, float *strengths, float orb_altitude, SatelliteStatus status) : satellite_id(id), num_antennas(number_of_anetennas), orbital_altitude(orb_altitude), status(status)
    {
        signal_strength = new float[num_antennas];
        for (int i = 0; i < num_antennas; i++)
        {
            signal_strength[i] = strengths[i];
        }
        if (status == OPERATIONAL)
        {
            active_satellites++;
        }
    }

    // Copy Constructor
    SatelliteData(const SatelliteData &other)
        : satellite_id(other.satellite_id),
          num_antennas(other.num_antennas),
          orbital_altitude(other.orbital_altitude),
          status(other.status)
    {
        signal_strength = new float[num_antennas];
        for (int i = 0; i < num_antennas; ++i)
            signal_strength[i] = other.signal_strength[i];

        if (status == OPERATIONAL)
        {
            active_satellites++;
        }
    }

    // Destructor of class
    ~SatelliteData()
    {
        delete[] signal_strength;
        if (status == OPERATIONAL)
            active_satellites--;
    }

    // Getter Functions
    int getSatelliteID() const { return satellite_id; }
    float getAltitude() const { return orbital_altitude; }
    const float *getSignalStrengths() const { return signal_strength; }
    int getNumberOfAntennas() const { return num_antennas; }
    SatelliteStatus getStatus() const { return status; }

    // Const function to get average of signal strength
    float getAverageSignalStrength() const
    {
        float signalStrength_sum = 0;
        for (int i = 0; i < num_antennas; i++)
        {
            signalStrength_sum += signal_strength[i];
        }

        return signalStrength_sum / num_antennas;
    }

    // Function to boost signals of all factors
    void boostSignal(float factor)
    {
        for (int i = 0; i < num_antennas; i++)
        {
            signal_strength[i] *= factor;
        }
    }

    // Overloaded function to boost signal of those who are below threshold
    void boostSignal(float factor, float threshold)
    {
        for (int i = 0; i < num_antennas; i++)
        {
            if (signal_strength[i] < threshold)
                signal_strength[i] *= factor;
        }
    }

    // Function to get Active Satellites count
    static int getActiveSatelliteCount()
    {
        return active_satellites;
    }

    // Function to set status and update active_satellites
    void setStatus(SatelliteStatus newStatus)
    {
        if (status == OPERATIONAL && newStatus != OPERATIONAL)
            active_satellites--;
        else if (status != OPERATIONAL && newStatus == OPERATIONAL)
            active_satellites++;
        status = newStatus;
    }

    // Function to get Status in string format
    std::string getStatusString() const
    {
        switch (status)
        {
        case OPERATIONAL:
            return "OPERATIONAL";
        case MAINTENANCE:
            return "MAINTENANCE";
        case DECOMMISSIONED:
            return "DECOMMISSIONED";
        default:
            return "UNKNOWN";
        }
    }
};

// Initialize active satellites to zero
int SatelliteData::active_satellites = 0;

// Global Functions

void printSatelliteData(const SatelliteData &sd)
{
    std::cout << "\nSatellite Data: \n";
    std::cout << "Satellite ID: " << sd.getSatelliteID() << std::endl;
    std::cout << "Orbital Altitude: " << sd.getAltitude() << std::endl;
    std::cout << "Signal Strengths: " << std::endl;
    for (int i = 0; i < sd.getNumberOfAntennas(); i++)
    {
        std::cout << "Signal strength: " << sd.getSignalStrengths()[i] << std::endl;
    }

    std::cout << "Status: " << sd.getStatusString() << std::endl;
    std::cout << std::endl;
}

// Function to compare altitude
bool compareAltitude(const SatelliteData &s1, const SatelliteData &s2)
{
    return s1.getAltitude() > s2.getAltitude();
}

// Function to clone satellite using copy constructor
void cloneSatellite(const SatelliteData &source, SatelliteData *&target)
{
    target = new SatelliteData(source);
}

// Function to print Active Satellites count
void printActiveSatelliteCount()
{
    std::cout << "\nActive Satellites are: " << SatelliteData::getActiveSatelliteCount() << std::endl;
}

// Function to update status to MAINTENANCE if weak
void updateStatusIfWeak(SatelliteData &sd, float confidence_threshold)
{
    if (sd.getAverageSignalStrength() < confidence_threshold)
    {
        sd.setStatus(MAINTENANCE);
    }
}

int main()
{
    // Dynamically allocating satellites
    float satellite1_strengths[] = {78.5f, 80.2f, 79.0f};
    float satellite2_strengths[] = {75.0f, 76.5f};
    SatelliteData *satellite1 = new SatelliteData(101, 3, satellite1_strengths, 550.0f, OPERATIONAL);
    SatelliteData *satellite2 = new SatelliteData(102, 2, satellite2_strengths, 600.0f, MAINTENANCE);

    // Boosting signal strength
    satellite1->boostSignal(2.0f);        // boost all
    satellite2->boostSignal(2.0f, 80.0f); // boost only below threshold ones

    // Compare the altitudes
    if (compareAltitude(*satellite1, *satellite2))
    {
        std::cout << "Satellite1 has higher altitude than Satellite 2 \n";
    }
    else
    {
        std::cout << "Satellite2 has higher altitude than Satellite 1\n";
    }

    // Clone one satellite
    SatelliteData *satellite3 = nullptr;
    cloneSatellite(*satellite2, satellite3);

    // printing all satellites data
    std::cout << "Satellite 1:";
    printSatelliteData(*satellite1);
    std::cout << "Satellite 2:";
    printSatelliteData(*satellite2);
    std::cout << "Cloned Satellite :";
    printSatelliteData(*satellite3);

    // Update status if weak
    updateStatusIfWeak(*satellite2, 76.0f);

    // Print updated status
    std::cout << "After status update:\n";
    printSatelliteData(*satellite2);

    // Printing active satellite counts
    printActiveSatelliteCount();

    //  Clean up memory
    delete satellite1;
    delete satellite2;
    delete satellite3;

    return 0;
}
