// Question 3: Camera Configuration Management in ADAS

#include <iostream>

class CameraConfig
{
private:
    // Data Members
    int num_modes;
    int *resolution_width;
    int *resolution_height;

public:
    // Constructor of CamerConfigClass
    CameraConfig(int num_modes)
    {
        if (num_modes < 0)
        {
            throw std::invalid_argument("Modes must be non negative numbers. ");
        }
        this->num_modes = num_modes;
        resolution_width = new int[num_modes];
        resolution_height = new int[num_modes];
    }

    // Copy Constructor of CameraConfig class
    CameraConfig(const CameraConfig &other)
    {
        num_modes = other.num_modes;
        resolution_width = new int[num_modes];
        resolution_height = new int[num_modes];
        for (int i = 0; i < num_modes; ++i)
        {
            resolution_width[i] = other.resolution_width[i];
            resolution_height[i] = other.resolution_height[i];
        }
    }

    // Destructors of class
    ~CameraConfig()
    {
        delete[] resolution_width;
        delete[] resolution_height;
    }

    // Getters
    //  Getters
    int getResolutionWidth(int modeIndex) const
    {

        return resolution_width[modeIndex];
    }

    int getResolutionHeight(int modeIndex) const
    {

        return resolution_height[modeIndex];
    }

    int getNumberOfModes() const
    {
        return num_modes;
    }

    // Setters and also have default values if not given any value
    void setResolution(int modeIndex, int width = 1260, int height = 1080)
    {
        validateModeIndex(modeIndex);
        resolution_width[modeIndex] = width;
        resolution_height[modeIndex] = height;
    }

    // Member function

    // Function to check which mode has higher resolution
    bool isHigherResolution(int mode1, int mode2) const
    {
        int res1 = this->resolution_width[mode1] * this->resolution_height[mode1];
        int res2 = this->resolution_width[mode2] * this->resolution_height[mode2];
        return res1 > res2;
    }

    // Const function to print config
    void printConfig() const
    {
        std::cout << "\nCamera Modes Configuration : " << std::endl;
        for (int i = 0; i < num_modes; ++i)
        {
            std::cout << "Mode " << i << ": " << resolution_width[i] << " X" << resolution_height[i] << std::endl;
        }
    }

private:
    void validateModeIndex(int modeIndex) const
    {
        if (modeIndex < 0 || modeIndex >= num_modes)
        {
            throw std::out_of_range("Invalid mode index.");
        }
    }
};

// Global function to print config
void printCameraConfig(const CameraConfig &config)
{
    config.printConfig();
}

// function to compare resolution
bool globalCompareResolution(const CameraConfig &config, int m1, int m2)
{
    return config.isHigherResolution(m1, m2);
}

// Check Mode resolution height assigned by some value or not
bool isModeHeightValid(const CameraConfig &config, int mode)
{
    return config.getResolutionHeight(mode) > 0;
}

// Check Mode resolution width assigned by some value or not
bool isModeWidthValid(const CameraConfig &config, int mode)
{
    return config.getResolutionWidth(mode) > 0;
}

int main()
{
    // Create CameraConfig object with 3 modes
    CameraConfig config(3);

    //  Initialize sample data
    config.setResolution(0, 1920, 1080);
    config.setResolution(1, 1280, 2160);

    config.setResolution(2, 3840); // use default value

    // Print configuration
    printCameraConfig(config);

    // Compare mode 0 and mode 2 using member function
    std::cout << "\nCalled member function->\n";
    if (config.isHigherResolution(0, 2))
        std::cout << "Mode 0 has higher resolution than mode 2." << std::endl;
    else
        std::cout << "Mode 2 has higher resolution than mode 0." << std::endl;

    // Compare mode 0 and mode 2 using global function
    std::cout << "\nCalled Global Function\n";
    if (globalCompareResolution(config, 0, 2))
        std::cout << "Mode 0 has higher resolution. " << std::endl;
    else
        std::cout << "Mode 2 has higher resolution. " << std::endl;

    return 0;
}