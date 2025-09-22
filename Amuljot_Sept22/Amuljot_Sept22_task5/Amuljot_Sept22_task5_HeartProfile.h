#ifndef HEALTH_PROFILE_H
#define HEALTH_PROFILE_H

#include <string>
#include <utility>

// Declaring HeartProfile class
class HealthProfile
{
    // Data members
private:
    std::string firstName; // First name of person
    std::string lastName;  // Last name of person
    std::string gender;    // Gender of person
    int birthDay;          // Birth day of person
    int birthMonth;        // Birth Month of person
    int birthYear;         // Birth Year of person
    int height;            // Height of person
    int weight;            // Weight of person

public:
    // Parameterised Constructor
    HealthProfile(const std::string &fName, const std::string &lName, const std::string &gen,
                  int day, int month, int year, int height, int weight);

    // Setters Function
    void setFirstName(const std::string &fName);
    void setLastName(const std::string &lName);
    void setGender(const std::string &gen);
    void setBirthDay(int day);
    void setBirthMonth(int month);
    void setBirthYear(int year);
    void setHeight(int height);
    void setWeight(int weight);

    // Getters Function
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getGender() const;
    int getBirthDay() const;
    int getBirthMonth() const;
    int getBirthYear() const;
    int getHeight() const;
    int getWeight() const;

    // Health Calculations
    // Function to calculate age
    int getAge(int currentDay, int currentMonth, int currentYear) const;

    // Function to get BMI
    double getBMI() const;

    // Function to get Maximum Heart rate
    int getMaximumHeartRate(int age) const;

    // Function to get Target heart range
    std::pair<int, int> getTargetHeartRateRange(int age) const;
};

#endif