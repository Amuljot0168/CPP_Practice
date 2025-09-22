#include "Amuljot_Sept22_task5_HeartProfile.h"
#include <utility>

// Parameterised Constructor
HealthProfile::HealthProfile(const std::string &fName, const std::string &lName, const std::string &gen,
                             int day, int month, int year, int height, int weight)
    : firstName(fName), lastName(lName), gender(gen),
      birthDay(day), birthMonth(month), birthYear(year),
      height(height), weight(weight) {}

// Setters Functions
void HealthProfile::setFirstName(const std::string &fName) { firstName = fName; }
void HealthProfile::setLastName(const std::string &lName) { lastName = lName; }
void HealthProfile::setGender(const std::string &gen) { gender = gen; }
void HealthProfile::setBirthDay(int day) { birthDay = day; }
void HealthProfile::setBirthMonth(int month) { birthMonth = month; }
void HealthProfile::setBirthYear(int year) { birthYear = year; }
void HealthProfile::setHeight(int height) { this->height = height; }
void HealthProfile::setWeight(int weight) { this->weight = weight; }

// Getters Functions
std::string HealthProfile::getFirstName() const
{
    return firstName; // return First Name of person
}
std::string HealthProfile::getLastName() const
{
    return lastName; // return Last name of person
}
std::string HealthProfile::getGender() const
{
    return gender; // return gender of person
}
int HealthProfile::getBirthDay() const
{
    return birthDay; // return birth day of person
}
int HealthProfile::getBirthMonth() const
{
    return birthMonth; // return birth Month of person
}
int HealthProfile::getBirthYear() const
{
    return birthYear; // return birth Year of person
}
int HealthProfile::getHeight() const
{
    return height; // return height of person
}
int HealthProfile::getWeight() const
{
    return weight; // return weight of person
}

// Age calculation
int HealthProfile::getAge(int currentDay, int currentMonth, int currentYear) const
{
    int age = currentYear - birthYear;
    if (currentMonth < birthMonth || (currentMonth == birthMonth && currentDay < birthDay))
    {
        age--;
    }
    return age;
}

// BMI calculation
double HealthProfile::getBMI() const
{
    return (weight * 703.0) / (height * height);
}

// Max heart rate
int HealthProfile::getMaximumHeartRate(int age) const
{
    return 220 - age;
}

// Target heart rate range
std::pair<int, int> HealthProfile::getTargetHeartRateRange(int age) const
{
    int maxRate = getMaximumHeartRate(age);
    int lower = static_cast<int>(maxRate * 0.50);
    int upper = static_cast<int>(maxRate * 0.85);
    return {lower, upper};
}