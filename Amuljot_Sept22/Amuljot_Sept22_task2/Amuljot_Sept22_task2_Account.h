#ifndef ACCOUNT_H
#define ACCOUNT_H

// Declaring class Account
class Account
{
    // Data members
private:
    int accountBalance; // Store the account balance of customer

public:
    Account(int balance);          // Parameterised constructor
    void credit(const int amount); // function to credit some money
    void debit(const int amount);  // function to debit some money
    int getBalance() const;        // Function to get  the current Account Balance
};
// end Account class

#endif