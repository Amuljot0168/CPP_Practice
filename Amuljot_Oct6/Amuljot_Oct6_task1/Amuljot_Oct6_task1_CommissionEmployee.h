#ifndef COMMISSION_EMPLOYEE_H
#define COMMISSION_EMPLOYEE_H

#include <string>
class CommissionEmployee
{
private:
    std::string firstName;
    std::string lastName;
    std::string socialSecurityNumber;
    double grossSales;     // gross weekly sales
    double commissionRate; // commission percentage
public:
    CommissionEmployee(const std::string &fname, const std::string &lname, const std::string &ssnumber, const double gsales = 0.0, const double crate = 0.0);

    void setFirstName(const std::string &); // set first name
    std::string getFirstName() const;       // return first name

    void setLastName(const std::string &); // set last name
    std::string getLastName() const;       // return last name

    void setSocialSecurityNumber(const std::string &); // set SSN
    std::string getSocialSecurityNumber() const;       // return SSN

    void setGrossSales(double);   // set gross sales amount
    double getGrossSales() const; // return gross sales amount

    void setCommissionRate(double);   // set commission rate (percentage)
    double getCommissionRate() const; // return commission rate

    double earnings() const; // calculate earnings
    void print() const;      // print CommissionEmployee object

    ~CommissionEmployee(); // Destructor
};
#endif