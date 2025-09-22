#ifndef HEART_RATES_H
#define HEART_RATES_H

#include <string>

// Declaring HearyRates class
class HeartRates
{
    // Data members
private:
    std::string firstName; // Store First name of person
    std::string lastName;  // Store Last name of person
    int birthDay;          // Store Birth Day of person
    int birthMonth;        // Store Birth Month of person
    int birthYear;         // Store Birth Year of person

public:
    // Parameterised Constructor
    HeartRates(const std::string &fName, const std::string &lName, int day, int month, int year);

    // Setters
    void setFirstName(const std::string &fName); // set firstName
    void setLastName(const std::string &lName);  // set lastName
    void setBirthDay(int day);                   // Set birthDay
    void setBirthMonth(int month);               // set birthMonth
    void setBirthYear(int year);                 // set birthYear

    // Const  Getters Function
    std::string getFirstName() const; // get FirstName of person
    std::string getLastName() const;  // get lastName of person
    int getBirthDay() const;          // get Birth Day of person
    int getBirthMonth() const;        // get Birth Month of person
    int getBirthYear() const;         // get Birth Year of person

    // Heart rate calculations
    int getAge(int currentDay, int currentMonth, int currentYear) const;              // function to calculate age of person
    int getMaximumHeartRate(int currentDay, int currentMonth, int currentYear) const; // function to get maximum heart rate of person
    void getTargetHeartRate(int currentDay, int currentMonth, int currentYear) const; // function to display target heart rate of person
};

#endif