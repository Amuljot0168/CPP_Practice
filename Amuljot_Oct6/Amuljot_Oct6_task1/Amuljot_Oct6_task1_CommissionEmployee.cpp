#include "Amuljot_Oct6_task1_CommissionEmployee.h"
#include <iostream>

CommissionEmployee::CommissionEmployee(const std::string &first, const std::string &last, const std::string &ssn, double sales, double rate)
{
  firstName = first;          // should validate
  lastName = last;            // should validate
  socialSecurityNumber = ssn; // should validate
  setGrossSales(sales);       // validate and store gross sales
  setCommissionRate(rate);    // validate and store commission rate
}

CommissionEmployee::~CommissionEmployee()
{

  std::cout << "\nCommissionEmployee object destroyed.\n";
}

void CommissionEmployee::setFirstName(const std::string &first)
{
  firstName = first; // should validate

} // end function setFirstName
  // return first name
std::string CommissionEmployee::getFirstName() const

{
  return firstName;

} // end function getFirstName
  // set last name
void CommissionEmployee::setLastName(const std::string &last)
{
  lastName = last; // should validate

} // end function setLastName
  // return last name
std::string CommissionEmployee::getLastName() const

{
  return lastName;

} // end function getLastName
  // set social security number
void CommissionEmployee::setSocialSecurityNumber(const std::string &ssn)
{
  socialSecurityNumber = ssn; // should validate

} // end function setSocialSecurityNumber
// return social security number
std::string CommissionEmployee::getSocialSecurityNumber() const

{
  return socialSecurityNumber;

} // end function getSocialSecurityNumber
  // set gross sales amount
void CommissionEmployee::setGrossSales(double sales)
{
  grossSales = (sales < 0.0) ? 0.0 : sales;

} // end function setGrossSales
  // return gross sales amount
double CommissionEmployee::getGrossSales() const

{
  return grossSales;

} // end function getGrossSales
  // set commission rate
void CommissionEmployee::setCommissionRate(double rate)
{
  commissionRate = (rate > 0.0 && rate < 1.0) ? rate : 0.0;

} // end function setCommissionRate
// return commission rate
double CommissionEmployee::getCommissionRate() const

{
  return commissionRate;

} // end function getCommissionRate

// calculate earnings
double CommissionEmployee::earnings() const
{
  return commissionRate * grossSales;
} // end function earnings

// print CommissionEmployee object
void CommissionEmployee::print() const
{
  std::cout << "commission employee: " << firstName << ' ' << lastName
            << "\nsocial security number: " << socialSecurityNumber
            << "\ngross sales: " << grossSales
            << "\ncommission rate: " << commissionRate << std::endl;
}