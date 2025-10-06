#ifndef OVERNIGHTPACKAGE_H
#define OVERNIGHTPACKAGE_H

#include "Amuljot_Oct6_task5_Package.h"

class OvernightPackage : public Package
{
private:
    double extraFeePerOunce;

public:
    // Constructor
    OvernightPackage(const std::string &, const std::string &, const std::string &, const std::string &, const std::string &,
                     const std::string &, const std::string &, const std::string &, const std::string &, const std::string &,
                     double, double, double);

    double calculateCost() const override;
    void print() const override;
    ~OvernightPackage(); // Destructor
};

#endif
