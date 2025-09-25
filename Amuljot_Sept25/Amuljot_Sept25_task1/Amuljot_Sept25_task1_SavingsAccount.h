#ifndef SAVINGS_ACCOUNT_H
#define SAVINGS_ACCOUNT_H

class SavingsAccount
{
private:
    static double annualInterestRate; // store annual interest rate
    double savingsBalance;            // store savings Balance

public:
    // Constructor
    SavingsAccount(const double initialBalance);

    // Member Functions
    // Function to calculate monthly Interest and also modify the Balance
    void calculateMonthlyInterest();

    // Function to modify interest rate with new interest rate
    static void modifyInterestRate(double newInterestRate);

    // getter for balance
    double getBalance() const;
};

#endif