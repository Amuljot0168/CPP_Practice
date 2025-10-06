#include "Amuljot_Oct6_task5_OvernightPackage.h"
#include <iostream>

OvernightPackage::OvernightPackage(const std::string &sName, const std::string &sAddr, const std::string &sCity,
                                   const std::string &sState, const std::string &sZip,
                                   const std::string &rName, const std::string &rAddr, const std::string &rCity,
                                   const std::string &rState, const std::string &rZip,
                                   double w, double cost, double extraFee)
    : Package(sName, sAddr, sCity, sState, sZip,
              rName, rAddr, rCity, rState, rZip, w, cost)
{
    // Validating exta fee per ounce and initializing extraFeePerOunce
    if (extraFee < 0)
    {
        throw std::invalid_argument("Extra fee per Ounce for overnight package must be positive!!!\n");
    }
    else
    {
        extraFeePerOunce = extraFee;
    }
}
// Destructor
OvernightPackage::~OvernightPackage()
{
    std::cout << "Overnight Package Destructor called!\n";
}
// Calculate cost according to extraFeePerOunce also
double OvernightPackage::calculateCost() const
{
    return weight * (costPerOunce + extraFeePerOunce);
}

// Print the details of package including Overnight Extra Fee
void OvernightPackage::print() const
{
    Package::print();
    std::cout << "Overnight Extra Fee/oz: $" << extraFeePerOunce << "\n";
}