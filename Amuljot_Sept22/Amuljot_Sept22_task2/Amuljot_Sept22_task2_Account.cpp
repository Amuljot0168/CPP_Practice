#include "Amuljot_Sept22_task2_Account.h"

#include <iostream>
// Defining the Account class constructor
Account::Account(int balance)
{
    if (balance < 0)
    {
        accountBalance = 0;
        std::cout << "Error: Initial balance is invalid. Setting balance to 0." << std::endl; // Print this error message when given invalid input
    }
    else
    {
        accountBalance = balance;
    }
}

// Defining credit,debit and getBalance  function of Account class declare in .h file

// Function credits the account balance of user
void Account::credit(const int amount)
{
    accountBalance += amount;
}

// Function used to debit the amount from account of the user
void Account::debit(const int amount)
{
    // Checks the amount to be debited must be equal or less than account balance of user
    if (amount > accountBalance)
    {
        std::cout << "Error: Debit amount exceeded account balance!" << std::endl;
    }
    else
    {
        accountBalance -= amount; // If the amount is less than or equal to Account balance debit the amount from user account
    }
}

// Function to get Balance of account
int Account::getBalance() const
{
    return accountBalance;
}