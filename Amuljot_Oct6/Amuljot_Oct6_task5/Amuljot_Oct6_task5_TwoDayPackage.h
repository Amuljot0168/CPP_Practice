#ifndef TWODAYPACKAGE_H
#define TWODAYPACKAGE_H

#include "Amuljot_Oct6_task5_Package.h"

class TwoDayPackage : public Package
{
private:
    double flatFee;

public:
    TwoDayPackage(const std::string &, const std::string &, const std::string &, const std::string &, const std::string &,
                  const std::string &, const std::string &, const std::string &, const std::string &, const std::string &,
                  double, double, double);

    double calculateCost() const override; // Function to calculate the cost overriding function from package class
    void print() const override;           // overriding print function from package class
    ~TwoDayPackage();
};

#endif
