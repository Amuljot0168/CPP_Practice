#ifndef PACKAGE_H
#define PACKAGE_H

#include <string>

class Package
{
protected:
    // Sender Info
    std::string senderName, senderAddress, senderCity, senderState, senderZip;
    // Recipient Info
    std::string recipientName, recipientAddress, recipientCity, recipientState, recipientZip;
    // Package Info
    double weight;       // in ounces
    double costPerOunce; // cost per ounce

public:
    // Constructor
    Package(const std::string &, const std::string &, const std::string &, const std::string &, const std::string &,
            const std::string &, const std::string &, const std::string &, const std::string &, const std::string &,
            double, double);

    virtual double calculateCost() const;
    virtual void print() const;
    virtual ~Package(); // Destructor
};

#endif