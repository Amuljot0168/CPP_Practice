#include <iostream>
#include <string>

class FleetVehicle
{
    // Private Data Members
private:
    int vehicleID;
    float fuelLevel;
    double distanceTravelled;
    char status;
    bool isAvailable;
    std::string driverName;

public:
    // Default Constructor
    FleetVehicle() : vehicleID(0), fuelLevel(50.0), distanceTravelled(0.0), status('A'), isAvailable(true), driverName("Unassigned") {}

    // Parameterized Constructor
    FleetVehicle(int vehicleID, float fuelLevel,
                 double distanceTravelled,
                 char status,
                 bool isAvailable,
                 std::string driverName) : vehicleID(vehicleID), fuelLevel(fuelLevel), distanceTravelled(distanceTravelled), status(status), isAvailable(isAvailable), driverName(driverName) {}

    // Destructor for Fleet Vehicle
    ~FleetVehicle()
    {
        std::cout << "Destructor called for vehicle ID: " << vehicleID << std::endl;
    }

    // Getter and Setter function of All Data Members

    // Getter function of vehicle ID
    int getVehicleID()
    {
        return vehicleID;
    }

    // Getter function for accessing fuel Level
    float getFuelLevel()
    {
        return fuelLevel;
    }

    // Getter function for accessing distance Travelled
    double getDistanceTravelled()
    {
        return distanceTravelled;
    }

    // Getter function for accessing status
    char getStatus()
    {
        return status;
    }

    // Getter function for accessing isAvailable
    bool getIsAvailable()
    {
        return isAvailable;
    }

    // Getter function for accessing Driver name
    std::string getdriverName()
    {
        return driverName;
    }

    // Setter function to set vehicle ID
    void setVehicleID(int vehicleID)
    {
        this->vehicleID = vehicleID;
    }

    // Setter function to set vehicle ID
    void setFuelLevel(float fuelLevel)
    {
        this->fuelLevel = fuelLevel;
    }

    // Setter function to set distance travelled
    void setDistanceTravelled(double distanceTravelled)
    {
        this->distanceTravelled = distanceTravelled;
    }

    // Setter function to set status
    void setStatus(char status)
    {
        this->status = status;
    }

    // Setter function to set availability
    void setIsAvailable(bool isAvailable)
    {
        this->isAvailable = isAvailable;
    }

    // Setter function to set driver name
    void setDriverName(std::string driverName)
    {
        this->driverName = driverName;
    }

    // Member functions

    // function to update status accordingly
    void updateStatus()
    {
        if (fuelLevel < 10.0 || !isAvailable)
        {
            status = 'I';
        }
        else
        {
            status = 'A';
        }
    }

    // function to Print all vehicle details
    void displayInfo()
    {
        std::cout << "Vehcile ID : " << vehicleID << std::endl;
        std::cout << "Fuel Level : " << fuelLevel << std::endl;
        std::cout << "Distance Travelled : " << distanceTravelled << std::endl;
        std::cout << "Status : " << status << std::endl;
        std::cout << "Is Available : " << isAvailable << std::endl;
        std::cout << "Driver Name : " << driverName << std::endl;

        std::cout << "------------------------------------" << std::endl;
        std::cout << std::endl;
    }
};

// Global functions
void assignDriver(FleetVehicle &vehicle, std::string name)
{
    // calling setDriverName function to set driver name
    vehicle.setDriverName(name);

    // Get the driver name
    std::string curr_drivername = vehicle.getdriverName();

    // Validating the drivername is assigned or not
    if (curr_drivername == name)
    {
        std::cout << "Driver name is assigned. " << std::endl;
    }
    else
    {
        std::cout << "Task Failed to assign the driver name. " << std::endl;
    }
}

// Function to refuel Vehicle
void refuelVehicle(FleetVehicle &vehicle, float fuelAmount)
{
    // Throw exception when fuel amount is 0 or less than 0
    if (fuelAmount <= 0)
    {
        throw std::invalid_argument("Fuel Amount must be more than 0");
    }
    else
    {
        // Store current level by calling getter function
        int currFuelLevel = vehicle.getFuelLevel();

        // Calling setter function to increase fuel level
        vehicle.setFuelLevel(currFuelLevel + fuelAmount);

        std::cout << "Vehicle is Refueled successfully! \n Current Fuel Level: " << vehicle.getFuelLevel() << std::endl; // Display the fuel level After refueling
    }
}

int main()
{
    // Creating array dynamically
    FleetVehicle *fleet_Vehicles = new FleetVehicle[3];

    // Sample Data for Testing
    fleet_Vehicles[0] = FleetVehicle(101, 45.5, 120.0, 'A', true, "Raj");
    fleet_Vehicles[1] = FleetVehicle(102, 8.0, 300.0, 'A', true, "Priya");
    // fleet_Vehicles[2] uses default constructor

    int choice = 0;
    int index;

    // Show Menu
    while (choice != 6)
    {
        std::cout << "\n--- Vehicle Menu ---\n";
        std::cout << "1. Add vehicle details\n";
        std::cout << "2. Assign a driver\n";
        std::cout << "3. Refuel vehicle\n";
        std::cout << "4. Update status\n";
        std::cout << "5. Display vehicle info\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        // If '1' then add Vehicle Details
        case 1:
        {
            // Choose the index
            std::cout << "Enter vehicle index [0-2] : ";
            std::cin >> index;

            // Check for invalid indices
            if (index < 0 || index >= 3)
            {
                std::cout << "Invalid Index! \n";
                break;
            }

            // Input the details
            int id;
            float fuel;
            double distance;
            char status;
            bool available;
            std::string driver;

            std::cout << "Enter Vehicle ID: ";
            std::cin >> id;
            std::cout << "Enter Fuel Level: ";
            std::cin >> fuel;
            std::cout << "Enter Distance Travelled: ";
            std::cin >> distance;
            std::cout << "Enter Status (A-[Active] /I- [InActive]): ";
            std::cin >> status;
            std::cout << "Is Available (true - 1 /false- 0): ";
            std::cin >> available;
            std::cout << "Enter Driver Name: ";
            std::cin.ignore();
            getline(std::cin, driver);

            fleet_Vehicles[index] = FleetVehicle(id, fuel, distance, status, available, driver);
            std::cout << "Vehicle Details Added Successfully !" << std::endl; // Display this message if vehicle details are added
            break;
        }

        case 2:
        {
            // Choose the index
            std::cout << "Enter vehicle index [0-2] : ";
            std::cin >> index;

            // Check for invalid indices
            if (index < 0 || index >= 3)
            {
                std::cout << "Invalid Index! \n";
                break;
            }

            std::string name;
            std::cout << "Enter Driver's Name : ";

            // Input the driver name
            std::cin.ignore();
            getline(std::cin, name);

            // Use assignDriver function to assign the driver
            assignDriver(fleet_Vehicles[index], name);
            break;
        }
        case 3:
        { // Choose the index
            std::cout << "Enter vehicle index [0-2] : ";
            std::cin >> index;

            // Check for invalid indices
            if (index < 0 || index >= 3)
            {
                std::cout << "Invalid Index! \n";
                break;
            }

            float fuelAmount;
            std::cout << "Enter the Fuel Amount: ";

            // Input the amount of fuel
            std::cin >> fuelAmount;

            // Use refuelVehicle function to refuel the vehicle
            refuelVehicle(fleet_Vehicles[index], fuelAmount);
            break;
        }

        case 4:
        {
            // Choose the index
            std::cout << "Enter vehicle index [0-2] : ";
            std::cin >> index;

            // Check for invalid indices
            if (index < 0 || index >= 3)
            {
                std::cout << "Invalid Index! \n";
                break;
            }

            // Update the status
            fleet_Vehicles[index].updateStatus();

            std::cout << "Status updated successfully!" << std::endl;
            break;
        }

        case 5:
        {
            // Choose the index
            std::cout << "Enter vehicle index [0-2] : ";
            std::cin >> index;

            // Check for invalid indices
            if (index < 0 || index >= 3)
            {
                std::cout << "Invalid Index! \n";
                break;
            }

            // Display the information of vehicles
            fleet_Vehicles[index].displayInfo();
            break;
        }
        case 6:
        {
            std::cout << "Exiting program....Done! " << std::endl;
            break;
        }
        default:
            std::cout << "Invalid choice!" << std::endl;
        }
    }

    delete[] fleet_Vehicles; // free dynamic memory

    return 0;
}
