#include <iostream>

#include "Amuljot_Sept22_task2_Account.h"

int main()
{
    // creating two dynamically allocated object
    Account *account1 = new Account(1000);
    Account *account2 = new Account(2000);

    // Displaying the  initial account balance
    std::cout << "\nCurrent Balance of account1: " << account1->getBalance() << std::endl;
    std::cout << "Current Balance of account2: " << account2->getBalance() << std::endl;
    std::cout << std::endl;

    std::cout << "Crediting some money in both accounts!" << std::endl;

    // Using credit function to credit some money in the accounts
    account1->credit(100);
    account2->credit(500);

    // Displaying the current account balance after crediting some money
    std::cout << "\nCurrent Balance of account1: " << account1->getBalance() << std::endl;
    std::cout << "Current Balance of account2: " << account2->getBalance() << std::endl;
    std::cout << std::endl;

    std::cout << "Debtting some money in both accounts!" << std::endl;
    // Using debit function to debit some money in the accounts
    account1->debit(1150); // Account balance remain same as debit amount exceeding account balance
    account2->debit(1000); // Account balance changes

    // Displaying the current account balance after debiting  some money
    std::cout << "\nCurrent Balance of account1: " << account1->getBalance() << std::endl; // display 1100 as account balance(no change)
    std::cout << "Current Balance of account2: " << account2->getBalance() << std::endl;   // display 1500 as amount debitted successfully
    std::cout << std::endl;

    // Free Up Memory
    delete account1;
    delete account2;

    return 0;
}