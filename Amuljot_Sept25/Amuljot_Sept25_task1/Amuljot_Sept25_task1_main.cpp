#include <iostream>
#include "Amuljot_Sept25_task1_SavingsAccount.h"

int main()
{
    SavingsAccount *saver1 = new SavingsAccount(2000.0);
    SavingsAccount *saver2 = new SavingsAccount(3000.0);

    std::cout << "Initial Balance of saver1: $" << saver1->getBalance() << std::endl;
    std::cout << "Initial Balance of saver2: $" << saver2->getBalance() << std::endl;

    // Set the annual interest rate to 3 percent
    SavingsAccount::modifyInterestRate(3.0);
    std::cout << "\nAnnual Interest Rate is set to 3 percent.\n\n";

    // Calculating monthly interest at the rate of 3%
    saver1->calculateMonthlyInterest();
    std::cout << "New Balances of saver1: $" << saver1->getBalance() << std::endl;

    saver2->calculateMonthlyInterest();
    std::cout << "New Balances of saver2: $" << saver2->getBalance() << std::endl;

    // Calculating monthly intereset at the interest rate of 4%
    SavingsAccount::modifyInterestRate(4.0);
    std::cout << "\nAnnual Interest Rate is set to 4 percent.\n\n";

    saver1->calculateMonthlyInterest();
    std::cout << "New Balances of saver1: $" << saver1->getBalance() << std::endl;

    saver2->calculateMonthlyInterest();
    std::cout << "New Balances of saver2: $" << saver2->getBalance() << std::endl;

    // Free Up memory
    delete saver1;
    delete saver2;
    return 0;
}