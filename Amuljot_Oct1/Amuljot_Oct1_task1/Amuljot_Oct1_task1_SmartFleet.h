#ifndef SMARTFLEET_H
#define SMARTFLEET_H

#include <string>
class HybridVehicle
{
private:
    std::string modelName;
    float electricKm;
    float gasolineKm;
    float gasolineUsed;
    int *trips;
    int tripCount;

public:
    HybridVehicle(std::string name = "", float ekm = 0, float gkm = 0, float gused = 0);
    HybridVehicle(const HybridVehicle &);
    ~HybridVehicle();

    HybridVehicle &operator=(const HybridVehicle &other);
    HybridVehicle operator+(const HybridVehicle &other) const;
    bool operator==(const HybridVehicle &other) const;
    HybridVehicle &operator++(); // prefix
    int &operator[](int index);
    int operator()() const;
    operator float() const;
    friend std::ostream &operator<<(std::ostream &out, const HybridVehicle &vehicle);
};

#endif