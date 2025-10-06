#ifndef BASEPLUS_H
#define BASEPLUS_H

#include <string>
#include "Amuljot_Oct6_task1_CommissionEmployee.h"

class BasePlusCommissionEmployee
{
private:
    CommissionEmployee employee; // Composition
    double baseSalary;           // base salary

public:
    BasePlusCommissionEmployee(const std::string &, const std::string &, const std::string &, double = 0.0, double = 0.0, double = 0.0);
    void setBaseSalary(double);   // set base salary
    double getBaseSalary() const; // return base salary
    double earnings() const;      // calculate earnings
    void print() const;           // print BasePlusCommissionEmployee object

    ~BasePlusCommissionEmployee(); // Destructor
};

#endif