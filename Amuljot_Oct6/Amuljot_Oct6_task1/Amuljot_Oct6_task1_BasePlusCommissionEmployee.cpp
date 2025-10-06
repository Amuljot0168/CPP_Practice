#include "Amuljot_Oct6_task1_BasePlusCommissionEmployee.h"
#include <iostream>

BasePlusCommissionEmployee::BasePlusCommissionEmployee(const std::string &first, const std::string &last, const std::string &ssn, double sales, double rate, double salary) : employee(first, last, ssn, sales, rate)
{
    setBaseSalary(salary);
}

BasePlusCommissionEmployee::~BasePlusCommissionEmployee()
{
    std::cout << "\nBasePlusCommissionEmployee object destroyed.\n";
}

void BasePlusCommissionEmployee::setBaseSalary(double salary)
{
    baseSalary = (salary < 0.0) ? 0.0 : salary;

} // end function setBaseSalary
  // return base salary
double BasePlusCommissionEmployee::getBaseSalary() const

{
    return baseSalary;

} // end function getBaseSalary
  // calculate earnings
double BasePlusCommissionEmployee::earnings() const
{

    // can access protected data of base class
    return baseSalary + employee.earnings();

} // end function earnings

// print BasePlusCommissionEmployee object
void BasePlusCommissionEmployee::print() const

{

    employee.print();
    std::cout << "Base Salary: " << baseSalary << std::endl;
}
