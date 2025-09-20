#include <iostream>
#include <string>
#include <stdexcept>

class ServiceRecord
{
private:
    // Data Members
    std::string date_;        // Service Date
    int mileage_;             // Vehicle Mileage at time of service
    std::string description_; // Description of service performed

public:
    // Default Constructors
    ServiceRecord() : date_(""), mileage_(0), description_("") {};

    // Parameterized Constructor
    ServiceRecord(const std::string &date, int mileage, const std::string &description) : date_(date), description_(description)
    {
        if (mileage < 0)
        {
            throw std::invalid_argument("Mileage must be greater than 0 for the service.");
        }
        else
        {
            this->mileage_ = mileage;
        }
    }

    // Copy Constructor
    ServiceRecord(const ServiceRecord &other) : date_(other.date_), mileage_(other.mileage_), description_(other.description_) {}

    // Assignment Operator (explicitly defined for clarity and consistency)
    ServiceRecord &operator=(const ServiceRecord &other)
    {
        if (this != &other)
        {
            date_ = other.date_;
            mileage_ = other.mileage_;
            description_ = other.description_;
        }
        return *this;
    }

    // Getters function
    const std::string &getDate() const
    {
        return date_;
    }

    int getMileage() const
    {
        return mileage_;
    }

    const std::string &getDescription() const
    {
        return description_;
    }

    // Utility function
    // print function to display Service Record
    void print() const
    {
        std::cout << "\nDate: " << date_ << std::endl;
        std::cout << "Mileage: " << mileage_ << std::endl;
        std::cout << "Description: " << description_ << std::endl;
    }
};

// Car Class
class Car
{
private:
    std::string vin_;               // Vehicle Identification Number
    std::string make_;              // Manufacturer name
    std::string model_;             // Model name
    double price_;                  // Current market price (non-negative
    ServiceRecord *serviceHistory_; // Dynamic  array that  stores  the  service records
    size_t serviceCount_;           // Number of valid service records stored
    size_t serviceCap_;             // Allocated capacity of the serviceHistory_ array
    int *damageCodes_;              // Dynamic    array that    stores    “damage codes”
    size_t damageCount_;            // Number of valid damage-code entries
    size_t damageCap_;              // Allocated capacity of damageCodes_
    static size_t totalCars_;       // Counter of live Car objects

    // Resize seviceHistory_ if needed
    void reserveService(size_t newCap)
    {
        if (newCap <= serviceCap_)
            return;

        ServiceRecord *newHistory = new ServiceRecord[newCap];
        for (size_t i = 0; i < serviceCount_; i++)
        {
            newHistory[i] = serviceHistory_[i];
        }
        delete[] serviceHistory_;
        serviceHistory_ = newHistory;
        serviceCap_ = newCap;
    }

    void reserveDamage(size_t newCap)
    {
        if (newCap <= damageCap_)
        {
            return;
        }
        int *newdDamageCodes = new int[newCap];

        for (size_t i = 0; i < damageCount_; i++)
        {
            newdDamageCodes[i] = damageCodes_[i];
        }
        delete[] damageCodes_;
        damageCodes_ = newdDamageCodes;
        damageCap_ = newCap;
    }

public:
    // Default Constructor
    Car() : vin_(""), make_(""), model_(""), price_(0), serviceHistory_(nullptr), serviceCount_(0), serviceCap_(0), damageCodes_(nullptr), damageCount_(0), damageCap_(0)
    {
        totalCars_++;
    }

    // Parameterised Constructor
    Car(std::string vin, std::string make, std::string model, double price) : vin_(vin), make_(make), model_(model), serviceHistory_(nullptr), serviceCount_(0), serviceCap_(0), damageCodes_(nullptr), damageCount_(0), damageCap_(0)
    {
        // Validate price
        if (price < 0)
        {
            throw std::invalid_argument("Price cannot be negative.");
        }
        else
        {
            price_ = price;
        }
        totalCars_++;
    }

    // Copy Constructor (making deep copy)
    Car(const Car &other) : vin_(other.vin_), make_(other.make_), model_(other.model_), price_(other.price_),
                            serviceCount_(other.serviceCount_), serviceCap_(other.serviceCap_),
                            damageCount_(other.damageCount_), damageCap_(other.damageCap_)
    {
        serviceHistory_ = new ServiceRecord[serviceCap_];
        for (size_t i = 0; i < serviceCount_; i++)
        {
            serviceHistory_[i] = other.serviceHistory_[i];
        }

        damageCodes_ = new int[damageCap_];
        for (size_t i = 0; i < damageCap_; i++)
        {
            damageCodes_[i] = other.damageCodes_[i];
        }
        totalCars_++;
    }

    // Destructor of class
    ~Car()
    {
        delete[] serviceHistory_;
        delete[] damageCodes_;
        --totalCars_;
    }

    // Assignment Operator (Copy-and-Swap Idiom)
    Car &operator=(Car other)
    {
        swap(*this, other);
        return *this;
    }

    friend void swap(Car &lhs, Car &rhs) noexcept
    {
        std::swap(lhs.vin_, rhs.vin_);
        std::swap(lhs.make_, rhs.make_);
        std::swap(lhs.model_, rhs.model_);
        std::swap(lhs.price_, rhs.price_);
        std::swap(lhs.serviceHistory_, rhs.serviceHistory_);
        std::swap(lhs.serviceCount_, rhs.serviceCount_);
        std::swap(lhs.serviceCap_, rhs.serviceCap_);
        std::swap(lhs.damageCodes_, rhs.damageCodes_);
        std::swap(lhs.damageCount_, rhs.damageCount_);
        std::swap(lhs.damageCap_, rhs.damageCap_);
    }

    // Friend Swap

    // Static Accessor
    // Function to return current value of total cars
    static size_t getTotalCars()
    {
        return totalCars_;
    }

    // Setters Functions
    void setVIN(const std::string &vin)
    {
        this->vin_ = vin;
    }

    void setMake(const std::string &make)
    {
        this->make_ = make;
    }

    void setModel(const std::string &model)
    {
        this->model_ = model;
    }

    void setPrice(double price)
    {
        if (price < 0)
        {
            throw std::invalid_argument("Price cannot be negative.\n");
        }
        this->price_ = price;
    }

    // Getters Function

    const std::string &getVIN() const { return vin_; }
    const std::string &getMake() const { return make_; }
    const std::string &getModel() const { return model_; }
    double getPrice() const { return price_; }
    size_t getServiceCount() const { return serviceCount_; }
    size_t getDamageCount() const { return damageCount_; }
    const ServiceRecord *getServiceHistory() const { return serviceHistory_; }
    const int *getDamageCodes() const { return damageCodes_; }

    // Buisness Logic Functions

    // Add Service Record
    void addService(const ServiceRecord &rec)
    {
        if (serviceCount_ == serviceCap_)
        {
            reserveService(serviceCap_ == 0 ? 2 : serviceCap_ * 2);
        }
        serviceHistory_[serviceCount_++] = rec;
    }

    // Add Damage Code
    void addDamageCode(int code)
    {
        if (damageCount_ == damageCap_)
        {
            reserveDamage(damageCap_ == 0 ? 2 : damageCap_ * 2);
        }
        damageCodes_[damageCount_++] = code;
    }

    // Print Car Info
    void printInfo() const
    {
        std::cout << "VIN: " << vin_ << ", \nMake: " << make_
                  << ", \nModel: " << model_ << ", \nPrice: " << price_ << std::endl;

        std::cout << "Service History (" << serviceCount_ << "):" << std::endl;
        for (size_t i = 0; i < serviceCount_; ++i)
        {
            serviceHistory_[i].print();
        }

        std::cout << "Damage Codes (" << damageCount_ << "): ";
        for (size_t i = 0; i < damageCount_; ++i)
        {
            std::cout << damageCodes_[i] << " ";
        }
        std::cout << std::endl;
        std::cout << std::endl;
    }

    // helper function
    void updateDamageCodes(size_t index, int newCode)
    {
        damageCodes_[index] = newCode;
    }
};

size_t Car::totalCars_ = 0;

// ------------------ Global Functions ------------------

// Print all cars in an array
void printAllCars(const Car *cars, size_t count)
{
    for (size_t i = 0; i < count; ++i)
    {
        std::cout << "\nCar " << (i + 1) << " Info:\n";
        cars[i].printInfo();
    }
}

// Calculate average price of all cars
double averagePrice(const Car *arr, size_t n)
{
    if (n == 0)
        return 0.0;
    double sum = 0.0;
    for (size_t i = 0; i < n; ++i)
        sum += arr[i].getPrice();
    return sum / n;
}

// Compare the price ascending means Car (a) price is less than car (b)
bool compareByPriceAsc(const Car &a, const Car &b)
{
    return a.getPrice() < b.getPrice();
}

// Compare the price descending means Car (a) price is greater than car (b)
bool compareByPriceDesc(const Car &a, const Car &b)
{
    return a.getPrice() > b.getPrice();
}

// Check both cars are equal based on VIN
bool areCarsEqual(const Car &a, const Car &b)
{
    return a.getVIN() == b.getVIN();
}

// Calculate which car has maximum price
const Car *maxPriceCar(const Car *arr, size_t n)
{
    if (n == 0)
        return nullptr;
    const Car *maxCar = &arr[0];
    for (size_t i = 1; i < n; ++i)
        if (arr[i].getPrice() > maxCar->getPrice())
            maxCar = &arr[i];
    return maxCar;
}

// Find the car by its vin in the Car array
const Car *findCarByVIN(const Car *arr, size_t n, const std::string &vin)
{
    for (size_t i = 0; i < n; ++i)
        if (arr[i].getVIN() == vin)
            return &arr[i];
    return nullptr;
}

// Count Cars with specific Damage
size_t countCarsWithDamage(const Car *arr, size_t n, int code)
{
    size_t count = 0;
    for (size_t i = 0; i < n; ++i)
    {
        const int *codes = arr[i].getDamageCodes();
        size_t len = arr[i].getDamageCount();
        for (size_t j = 0; j < len; ++j)
            if (codes[j] == code)
            {
                ++count;
                break;
            }
    }
    return count;
}

// Swap two Car objects using the friend swap
void swapCars(Car &a, Car &b)
{
    swap(a, b);
}

// Helper function for 8b to setup a car
void setupCar(Car &car, const int *damageCodes, size_t damageCount,
              const ServiceRecord *serviceRecords, size_t serviceCount)
{
    for (size_t i = 0; i < damageCount; ++i)
    {
        car.addDamageCode(damageCodes[i]);
    }
    for (size_t i = 0; i < serviceCount; ++i)
    {
        car.addService(serviceRecords[i]);
    }
}

int main()
{
    std::cout << "Initial Car Count = " << Car::getTotalCars() << std::endl; // give output 0

    // creating object using Calling Default Constructor
    Car cDefault;
    cDefault.printInfo();

    // Creating car object with parameterised constructor
    Car cHonda("1HGCM", "Honda", "Accord", 19999.99);
    cHonda.printInfo();

    // Adding damage Codes
    int damageCodes[] = {101, 205, 307};
    for (int code : damageCodes)
        cHonda.addDamageCode(code);

    // printing the cHonda damageCodes
    cHonda.printInfo();

    // Creating ServiceRoad Objects
    ServiceRecord srOilChange("2022-03-15", 15000, "Oil Change");
    ServiceRecord srBrakeReplace("2023-01-10", 25000, "Brake pads replacement");

    // Adding to cHonda
    cHonda.addService(srOilChange);
    cHonda.addService(srBrakeReplace);

    // Printing the information of cHonda
    cHonda.printInfo();

    // Using Copy Constructor to copy cHonda to cCopyHonda
    Car cCopyHonda = Car(cHonda);

    std::cout << "Current Total Cars: " << Car::getTotalCars() << std::endl; // Total Cars are 3

    // Displaying the damageCode arrays of original cHonda and copy cCopyHonda
    cCopyHonda.updateDamageCodes(1, 55);
    std::cout << "Original Honda Damage Codes:\n";
    for (size_t i = 0; i < cHonda.getDamageCount(); i++)
    {
        std::cout << cHonda.getDamageCodes()[i] << " ";
    }

    std::cout << "\nCopy Damage Codes (after modification):\n";
    for (size_t i = 0; i < cCopyHonda.getDamageCount(); ++i)
        std::cout << cCopyHonda.getDamageCodes()[i] << " ";

    std::cout << "\n \n";

    // Service Count of both original and copy object
    std::cout << "\nService Count (Original): " << cHonda.getServiceCount();
    std::cout << "\nService Count (Copy): " << cCopyHonda.getServiceCount() << "\n";

    // Using assignment operator to copy the objects
    Car cAssign = cHonda;
    // Print total cars
    std::cout << "\nCurrent Total Cars: " << Car::getTotalCars() << std::endl;

    // Confirming deep copy of damage code arrays
    cAssign.updateDamageCodes(0, 10);
    std::cout << "\nAssigned Honda Damage Codes:\n";
    for (size_t i = 0; i < cAssign.getDamageCount(); ++i)
        std::cout << cAssign.getDamageCodes()[i] << " ";

    std::cout << "\nOriginal Honda Damage Codes (after assignment):\n";
    for (size_t i = 0; i < cHonda.getDamageCount(); ++i)
        std::cout << cHonda.getDamageCodes()[i] << " ";
    std::cout << "\n";

    // 8: Allocating dynamic array
    size_t N = 3;
    Car *garage = new Car[N];

    // 8a: Initialising each element on heap array
    garage[0] = Car("JH4KA", "Acura", "TLX", 27999.49);
    garage[1] = Car("5YJ3E", "Tesla", "Model 3", 39999.00);
    garage[2] = Car("WBA4", "BMW", "3 Series", 34999.99);

    // 8b:Use helper function that helps in intializing Cars Easily
    int damageAcura[] = {102, 208};
    int damageTesla[] = {110, 220, 330, 440};
    int damageBMW[] = {150, 250};

    ServiceRecord srTireRotate("2023-06-20", 30000, "Tire rotation");
    ServiceRecord srInspection("2024-02-05", 35000, "Annual safety inspection");

    setupCar(garage[0], damageAcura, 2, &srTireRotate, 1);
    setupCar(garage[1], damageTesla, 4, &srInspection, 1);
    setupCar(garage[2], damageBMW, 2, &srBrakeReplace, 1);

    // 8c: Printing the three cars information
    printAllCars(garage, N);

    // 9: Average price
    std::cout << "\nAverage Price: $" << averagePrice(garage, N) << "\n";

    // 10: Global utilities
    const Car *maxCar = maxPriceCar(garage, N);
    if (maxCar)
    {
        std::cout << "\nMost Expensive Car: \n";
        maxCar->printInfo();
    }

    const Car *foundCar = findCarByVIN(garage, N, "WBA4");
    if (foundCar)
    {
        std::cout << "\nFound Car by VIN 'WBA4': $" << foundCar->getPrice() << "\n";
    }

    size_t damagedCount = countCarsWithDamage(garage, N, 440);
    std::cout << "\nCars with damage code 440: " << damagedCount << "\n";

    bool equal = areCarsEqual(garage[0], garage[1]);
    std::cout << "\nAre Acura and Tesla equal by VIN? " << (equal ? "Yes" : "No") << "\n";

    // 11: delete heap array
    delete[] garage;

    // 12. Attempt to modify const Car&
    const Car cFord("1FA6P", "Ford", "Mustang", 31200.00);

    // cFord.setMake("Acura"); // Compilation Error

    // 13: Final Car Count
    std::cout << "\nFinal Car Count: " << Car::getTotalCars() << "\n";

    return 0;
}
