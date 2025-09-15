#include <iostream>
#include <string>

// Enum to define the types of aerospace components
enum ComponentType
{
    COMPONENT_TYPE_ENGINE = 0,
    COMPONENT_TYPE_AVIONICS,
    COMPONENT_TYPE_LANDING_GEAR,
    COMPONENT_TYPE_FUEL_SYSTEM
};

// Enum to define the status of aerospace components
enum ComponentStatus
{
    COMPONENT_STATUS_OPERATIONAL = 0,
    COMPONENT_STATUS_MAINTENANCE_REQUIRED,
    COMPONENT_STATUS_FAILED
};

// AerospaceComponent class to represent aircraft components
class AerospaceComponent
{
private:
    int componentIdentifier;           // Unique ID of the component
    double componentEfficiency;        // Efficiency percentage of the component
    std::string componentManufacturer; // Manufacturer name
    ComponentType componentType;       // Type of component (Engine, Avionics, etc.)
    ComponentStatus componentStatus;   // Current status of the component

public:
    // Default Constructor - initializes with default values
    AerospaceComponent()
        : componentIdentifier(0),
          componentEfficiency(100.0),
          componentManufacturer("Unknown"),
          componentType(COMPONENT_TYPE_ENGINE),
          componentStatus(COMPONENT_STATUS_OPERATIONAL) {}

    // Parameterized Constructor - initializes with given values
    AerospaceComponent(int componentIdentifier,
                       double componentEfficiency,
                       std::string componentManufacturer,
                       ComponentType componentType,
                       ComponentStatus componentStatus)
        : componentIdentifier(componentIdentifier),
          componentEfficiency(componentEfficiency),
          componentManufacturer(componentManufacturer),
          componentType(componentType),
          componentStatus(componentStatus) {}

    // Destructor - prints when component object is destroyed
    ~AerospaceComponent()
    {
        std::cout << "Component " << componentIdentifier << " destroyed." << std::endl;
    }

    // Setter for manufacturer
    void SetManufacturer(const std::string &manufacturer)
    {
        componentManufacturer = manufacturer;
    }

    // Getters
    int GetIdentifier() const { return componentIdentifier; }
    double GetEfficiency() const { return componentEfficiency; }
    ComponentType GetType() const { return componentType; }
    ComponentStatus GetStatus() const { return componentStatus; }

    // Updates component status based on efficiency
    void UpdateStatus()
    {
        if (componentEfficiency < 50.0)
        {
            componentStatus = COMPONENT_STATUS_FAILED;
        }
        else if (componentEfficiency > 50.0 && componentEfficiency < 80.0)
        {
            componentStatus = COMPONENT_STATUS_MAINTENANCE_REQUIRED;
        }
        else
        {
            componentStatus = COMPONENT_STATUS_OPERATIONAL;
        }
    }

    // Simulates component usage over given hours (efficiency decreases)
    void SimulateUsage(int usageHours)
    {
        for (int i = 0; i < usageHours; i++)
        {
            componentEfficiency -= componentEfficiency * 0.005; // decrease by 0.5% each hour
            if (componentEfficiency < 0.0)
            {
                componentEfficiency = 0.0; // efficiency cannot go below 0
                break;
            }
        }
        UpdateStatus(); // update status after usage
    }

    // Performs a maintenance check and prints status
    void PerformMaintenanceCheck()
    {
        ComponentStatus curr_ComponentStatus = componentStatus;
        switch (curr_ComponentStatus)
        {
        case COMPONENT_STATUS_OPERATIONAL:
        {
            std::cout << "COMPONENT_STATUS_OPERATIONAL" << std::endl;
            break;
        }
        case COMPONENT_STATUS_MAINTENANCE_REQUIRED:
        {
            std::cout << "COMPONENT_STATUS_MAINTENANCE_REQUIRED" << std::endl;
            break;
        }
        case COMPONENT_STATUS_FAILED:
        {
            std::cout << "COMPONENT_STATUS_FAILED" << std::endl;
            break;
        }
        }
    }

    // Boosts efficiency back to 100%
    void BoostEfficiency()
    {
        while (componentEfficiency < 100.0)
        {
            componentEfficiency += 1.0;
            if (componentEfficiency >= 100.0)
            {
                componentEfficiency = 100.0;
            }
        }
        UpdateStatus(); // update status after boosting
    }

    // Displays details of the component
    void DisplayDetails() const
    {
        std::cout << "Component ID: " << componentIdentifier << std::endl;
        std::cout << "Efficiency: " << componentEfficiency << " % " << std::endl;
        std::cout << "Manufacturer: " << componentManufacturer << std::endl;
        std::cout << "Component Type: " << GetTypeString(componentType) << std::endl;
        std::cout << "Component Status: " << GetStatusString(componentStatus) << std::endl;
    }

    // Converts enum type to string
    static std::string GetTypeString(const ComponentType type)
    {
        switch (type)
        {
        case COMPONENT_TYPE_ENGINE:
            return "Engine";
        case COMPONENT_TYPE_AVIONICS:
            return "Avionics";
        case COMPONENT_TYPE_LANDING_GEAR:
            return "Landing Gear";
        case COMPONENT_TYPE_FUEL_SYSTEM:
            return "Fuel System";
        default:
            return "Unknown";
        }
    }

    // Converts enum status to string
    static std::string GetStatusString(const ComponentStatus status)
    {
        switch (status)
        {
        case COMPONENT_STATUS_OPERATIONAL:
            return "Operational";
        case COMPONENT_STATUS_MAINTENANCE_REQUIRED:
            return "Maintenance Required";
        case COMPONENT_STATUS_FAILED:
            return "Failed";
        default:
            return "Unknown";
        }
    }
};

// Global function to assign manufacturer name
void AssignManufacturer(AerospaceComponent &component, const std::string &manufacturerName)
{
    component.SetManufacturer(manufacturerName);
    std::cout << "Manufacturer Name assigned successfully!" << std::endl;
}

// Checks if component efficiency is greater than 85%
bool IsEfficient(const AerospaceComponent &component)
{
    return (component.GetEfficiency() > 85.0);
}

// Checks if two components are of same type
bool IsSameType(const AerospaceComponent &componentA, const AerospaceComponent &componentB)
{
    return (componentA.GetType() == componentB.GetType());
}

// Checks if two components have same status
bool IsSameStatus(const AerospaceComponent &componentA, const AerospaceComponent &componentB)
{
    return (componentA.GetStatus() == componentB.GetStatus());
}

// Prints formatted details of all components in a list
void PrintFormattedComponentList(const AerospaceComponent componentList[], const int listSize)
{
    for (int i = 0; i < listSize; ++i)
    {
        std::cout << "\n Component " << i << ": \n";
        componentList[i].DisplayDetails();
    }
}

// Searches for a component by ID and returns index if found, else -1
int SearchComponentByIdentifier(const AerospaceComponent componentList[], const int listSize, const int searchIdentifier)
{
    int resultIndex = -1;
    for (int index = 0; index < listSize; index++)
    {
        if (componentList[index].GetIdentifier() == searchIdentifier)
        {
            resultIndex = index;
            break;
        }
    }
    return resultIndex;
}

// Helper function to check valid index for 3 components
bool isValidIndex(int index)
{
    return !(index < 0 || index >= 3);
}

int main()
{
    // Dynamically allocate array of 3 components
    AerospaceComponent *componentList = new AerospaceComponent[3];

    // Initialize first two with parameterized constructor
    componentList[0] = AerospaceComponent(101, 92.5, "GE Aviation", COMPONENT_TYPE_ENGINE, COMPONENT_STATUS_OPERATIONAL);
    componentList[1] = AerospaceComponent(102, 45.0, "Honeywell", COMPONENT_TYPE_AVIONICS, COMPONENT_STATUS_FAILED);
    // componentList[2] uses default constructor

    int choice; // menu choice
    int index;  // index for component

    // Menu loop until user selects Exit
    while (choice != 9)
    {
        std::cout << "\nComponent Menu:\n";
        std::cout << "1. Add Component Details\n";
        std::cout << "2. Assign Manufacturer \n";
        std::cout << "3. Simulate Usage\n";
        std::cout << "4. Boost Efficiency\n";
        std::cout << "5. Check Maintenance \n";
        std::cout << "6. Compare Maintenance\n";
        std::cout << "7. Search by Component ID\n";
        std::cout << "8. Display all components\n";
        std::cout << "9. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1: // Add Component Details
        {
            std::cout << "Enter Component index [0-2] : ";
            std::cin >> index;

            if (!isValidIndex(index))
            {
                std::cout << "Invalid Index! \n";
                break;
            }
            int id;
            double efficiency;
            std::string manufacturer;
            int typeInput, statusInput;

            std::cout << "Enter component ID: ";
            std::cin >> id;

            std::cout << "Enter efficiency (0.0–100.0): ";
            std::cin >> efficiency;

            if (efficiency < 0.0 || efficiency > 100.0)
            {
                std::cout << "Invalid efficiency.\n"; // must be 0–100
                continue;
            }

            std::cin.ignore();
            std::cout << "Enter manufacturer name: ";
            std::getline(std::cin, manufacturer);
            if (manufacturer.empty())
            {
                std::cout << "Manufacturer name cannot be empty.\n";
                continue;
            }

            std::cout << "Select component type:\n"
                      << "0. Engine\n1. Avionics\n2. Landing Gear\n3. Fuel System\n";
            std::cin >> typeInput;
            if (typeInput < 0 || typeInput > 3)
            {
                std::cout << "Invalid type selection.\n";
                continue;
            }

            std::cout << "Select component status:\n"
                      << "0. Operational\n1. Maintenance Required\n2. Failed\n";
            std::cin >> statusInput;
            if (statusInput < 0 || statusInput > 2)
            {
                std::cout << "Invalid status selection.\n";
                continue;
            }

            // Update component details
            componentList[index] = AerospaceComponent(id, efficiency, manufacturer,
                                                      static_cast<ComponentType>(typeInput),
                                                      static_cast<ComponentStatus>(statusInput));
            std::cout << "Component details updated successfully.\n";
            break;
        }

        case 2: // Assign Manufacturer
        {
            std::cout << "Enter Component index [0-2] : ";
            std::cin >> index;

            if (!isValidIndex(index))
            {
                std::cout << "Invalid Index! \n";
                break;
            }

            std::string name;
            std::cin.ignore();
            std::getline(std::cin, name);

            AssignManufacturer(componentList[index], name);
            std::cout << "Manufacturer name is assigned!" << std::endl;
            break;
        }

        case 3: // Simulate Usage
        {
            std::cout << "Enter Component index [0-2] : ";
            std::cin >> index;

            if (!isValidIndex(index))
            {
                std::cout << "Invalid Index! \n";
                break;
            }

            int usageHours;
            std::cout << "Enter the usage hours: ";
            std::cin >> usageHours;

            componentList[index].SimulateUsage(usageHours);
            break;
        }

        case 4: // Boost Efficiency
        {
            std::cout << "Enter Component index [0-2] : ";
            std::cin >> index;

            if (!isValidIndex(index))
            {
                std::cout << "Invalid Index! \n";
                break;
            }

            componentList[index].BoostEfficiency();
            break;
        }

        case 5: // Perform Maintenance Check
        {
            std::cout << "Enter Component index [0-2] : ";
            std::cin >> index;

            if (!isValidIndex(index))
            {
                std::cout << "Invalid Index! \n";
                break;
            }

            componentList[index].PerformMaintenanceCheck();
            break;
        }

        case 6: // Compare Maintenance (type & status)
        {
            int indexA, indexB;
            std::cout << "Enter Component index [0-2] : ";
            std::cin >> indexA;

            if (!isValidIndex(indexA))
            {
                std::cout << "Invalid Index! \n";
                break;
            }

            std::cout << "Enter Component index [0-2] : ";
            std::cin >> indexB;

            if (!isValidIndex(indexB))
            {
                std::cout << "Invalid Index! \n";
                break;
            }

            std::cout << "Same Type: " << (IsSameType(componentList[indexA], componentList[indexB]) ? "Yes" : "No") << "\n";
            std::cout << "Same Status: " << (IsSameStatus(componentList[indexA], componentList[indexB]) ? "Yes" : "No") << "\n";
            break;
        }

        case 7: // Search by Component ID
        {
            int id;
            std::cout << "Enter component ID to search: ";
            std::cin >> id;
            int result = SearchComponentByIdentifier(componentList, 3, id);
            if (result != -1)
            {
                std::cout << "Component found at index: " << result << "\n";
                componentList[result].DisplayDetails();
            }
            else
            {
                std::cout << "Component not found.\n";
            }
            break;
        }

        case 8: // Display all components
        {
            PrintFormattedComponentList(componentList, 3);
            break;
        }

        case 9: // Exit
        {
            std::cout << "Exiting the program.......Done!" << std::endl;
            break;
        }
        }
    }

    // Free memory
    delete[] componentList;
    return 0;
}
