#include <iostream>
#include <iomanip>
#include "Amuljot_Oct6_task1_BasePlusCommissionEmployee.h"

int main()
{
    // instantiate BasePlusCommissionEmployee object
    BasePlusCommissionEmployee employee("Bob", "Lewis", "333-33-3333", 5000, .04, 300);

    // get commission employee data
    employee.print();

    employee.setBaseSalary(1000); // set base salary
    std::cout << "\nUpdated employee information output by print function: \n"
              << std::endl;
    employee.print(); // display the new employee information

    // display the employee's earnings
    std::cout << "\n\nEmployee's earnings: $" << employee.earnings() << std::endl;
    return 0;
}