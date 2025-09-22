#include <iostream>
#include "Amuljot_Sept22_task4_HeartRates.h"

// Defining Parameterised Constructor to initialize data members of object
HeartRates::HeartRates(const std::string &fName, const std::string &lName, int day, int month, int year)
    : firstName(fName), lastName(lName), birthDay(day), birthMonth(month), birthYear(year) {}

// Defining Setters Function
void HeartRates::setFirstName(const std::string &fName) { firstName = fName; }
void HeartRates::setLastName(const std::string &lName) { lastName = lName; }
void HeartRates::setBirthDay(int day) { birthDay = day; }
void HeartRates::setBirthMonth(int month) { birthMonth = month; }
void HeartRates::setBirthYear(int year) { birthYear = year; }

// Defining Getters function
std::string HeartRates::getFirstName() const
{
    return firstName; // return first name of person
}
std::string HeartRates::getLastName() const
{
    return lastName; // return last name of person
}
int HeartRates::getBirthDay() const
{
    return birthDay; // return  Birth Day of person
}
int HeartRates::getBirthMonth() const
{
    return birthMonth; // return  Birth Month of person
}
int HeartRates::getBirthYear() const
{
    return birthYear; // return  Birth Year of person
}

// Age calculation
int HeartRates::getAge(int currentDay, int currentMonth, int currentYear) const
{

    // Calculate age by subtracting birth year from current year
    int age = currentYear - birthYear;

    // Decrease the calculate age if month or day of birth is greater than current one
    if (currentMonth < birthMonth || (currentMonth == birthMonth && currentDay < birthDay))
    {
        age--;
    }

    // return the age in years
    return age;
}

int HeartRates::getMaximumHeartRate(int currentDay, int currentMonth, int currentYear) const
{
    return 220 - getAge(currentDay, currentMonth, currentYear);
}

void HeartRates::getTargetHeartRate(int currentDay, int currentMonth, int currentYear) const
{
    int maxRate = getMaximumHeartRate(currentDay, currentMonth, currentYear);
    int lowerBound = static_cast<int>(maxRate * 0.50);
    int upperBound = static_cast<int>(maxRate * 0.85);

    std::cout << "Target Heart Rate Range: " << lowerBound << " - " << upperBound << " bpm" << std::endl;
}
