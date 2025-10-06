#include "Amuljot_Oct6_task5_TwoDayPackage.h"
#include <iostream>

TwoDayPackage::TwoDayPackage(const std::string &sName, const std::string &sAddr, const std::string &sCity,
                             const std::string &sState, const std::string &sZip,
                             const std::string &rName, const std::string &rAddr, const std::string &rCity,
                             const std::string &rState, const std::string &rZip,
                             double w, double cost, double fee)
    : Package(sName, sAddr, sCity, sState, sZip,
              rName, rAddr, rCity, rState, rZip, w, cost)
{
    // Validating flat fee and initializing the flat fee
    if (fee < 0)
    {
        throw std::invalid_argument("Flat fee must be a positive value!!!!\n");
    }
    else
    {
        flatFee = fee;
    }
}
TwoDayPackage::~TwoDayPackage()
{
    std::cout << "Two Day package destructor called!\n";
}
// Function to calcualte cost according to flat Fee also
double TwoDayPackage::calculateCost() const
{
    return Package::calculateCost() + flatFee;
}

// Print the details of package including Flat Fee
void TwoDayPackage::print() const
{
    Package::print();
    std::cout << "Two-Day Flat Fee: $" << flatFee << "\n";
}