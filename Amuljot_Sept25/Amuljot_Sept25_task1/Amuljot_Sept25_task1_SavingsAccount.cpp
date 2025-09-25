#include <iostream>
#include "Amuljot_Sept25_task1_SavingsAccount.h"

// Define static member
double SavingsAccount::annualInterestRate = 0.0;

// Constructor
SavingsAccount::SavingsAccount(const double initialBalance) : savingsBalance(initialBalance) {}

// return the current Saving balance
double SavingsAccount::getBalance() const
{
    return savingsBalance;
}

// Calculate and apply monthly interest
void SavingsAccount::calculateMonthlyInterest()
{
    double monthlyInterest = (savingsBalance * annualInterestRate) / 12;

    savingsBalance += monthlyInterest;
}

// Modify the annual Interest Rate
void SavingsAccount::modifyInterestRate(const double newInterestRate)
{
    annualInterestRate = newInterestRate;
}