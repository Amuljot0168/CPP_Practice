#include "Amuljot_Oct6_task5_Package.h"
#include <iostream>

// Constructor initalizing values
Package::Package(const std::string &sName, const std::string &sAddr, const std::string &sCity,
                 const std::string &sState, const std::string &sZip,
                 const std::string &rName, const std::string &rAddr, const std::string &rCity,
                 const std::string &rState, const std::string &rZip,
                 double w, double cost)
    : senderName(sName), senderAddress(sAddr), senderCity(sCity),
      senderState(sState), senderZip(sZip),
      recipientName(rName), recipientAddress(rAddr), recipientCity(rCity),
      recipientState(rState), recipientZip(rZip)
{
    // Validating weight and cost (must be positive value)
    if (w < 0)
    {
        throw std::invalid_argument("Weight must be positive value!!\n");
    }
    else
    {
        weight = w;
    }
    if (cost < 0)
    {
        throw std::invalid_argument("Cost must be positive value!!\n");
    }
    else
    {
        costPerOunce = cost;
    }
}

// Destructor
Package::~Package()
{
    std::cout << senderName << " Package Destructor called!\n";
}

// Function to calculate cost
double Package::calculateCost() const
{
    return weight * costPerOunce;
}

// Function to print details of package
void Package::print() const
{
    std::cout << "Sender: " << senderName << ", " << senderCity << ", " << senderState << "\n"
              << "Recipient: " << recipientName << ", " << recipientCity << ", " << recipientState << "\n"
              << "Weight: " << weight << " oz, Cost/oz: $" << costPerOunce << "\n";
}
