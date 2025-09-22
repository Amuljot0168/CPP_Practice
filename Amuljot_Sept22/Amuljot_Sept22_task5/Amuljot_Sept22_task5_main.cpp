#include <iostream>
#include <iomanip>
#include "Amuljot_Sept22_task5_HeartProfile.h"

int main()
{
    std::string firstName, lastName, gender;
    int birthDay, birthMonth, birthYear;
    int height, weight;
    int currentDay, currentMonth, currentYear;

    // Input personal details
    std::cout << "Enter First Name: ";
    std::cin >> firstName; // Input the first name
    std::cout << "Enter Last Name: ";
    std::cin >> lastName; // Input last name
    std::cout << "Enter Gender: ";
    std::cin >> gender; // Input Gender
    std::cout << "Enter Birth Day: ";
    std::cin >> birthDay; // Input Birth Day
    std::cout << "Enter Birth Month: ";
    std::cin >> birthMonth; // Input Birth Month
    std::cout << "Enter Birth Year: ";
    std::cin >> birthYear; // Input Birth Year
    std::cout << "Enter Height (in inches): ";
    std::cin >> height;                        // Input Height in inches
    std::cout << "Enter Weight (in pounds): "; // Input weight in pounds
    std::cin >> weight;

    // Input current date
    std::cout << "\nEnter Current Day: ";
    std::cin >> currentDay; // Input current day
    std::cout << "Enter Current Month: ";
    std::cin >> currentMonth; // Input current month
    std::cout << "Enter Current Year: ";
    std::cin >> currentYear; // Input current year

    // Create HealthProfile object
    HealthProfile person(firstName, lastName, gender, birthDay, birthMonth, birthYear, height, weight);

    // Calculate the age by giving current date as parameter
    int age = person.getAge(currentDay, currentMonth, currentYear);
    // Calculate BMI of person
    double bmi = person.getBMI();
    // Calculate Maximum Heart Rate
    int maxRate = person.getMaximumHeartRate(age);
    // Calculate target Heart Rate Range
    auto [lowerTarget, upperTarget] = person.getTargetHeartRateRange(age);

    // Display health report
    std::cout << "\nHEALTH PROFILE REPORT\n";
    std::cout << "Name: " << person.getFirstName() << " " << person.getLastName() << std::endl;                                           // Display first name and last name
    std::cout << "Gender: " << person.getGender() << std::endl;                                                                           // Display Gender of person
    std::cout << "Date of Birth: " << person.getBirthDay() << "/" << person.getBirthMonth() << "/" << person.getBirthYear() << std::endl; // Display Date of Birth of person
    std::cout << "Height: " << person.getHeight() << " inches\n";                                                                         // Display height of person
    std::cout << "Weight: " << person.getWeight() << " pounds\n";                                                                         // Display weight of person
    std::cout << "Age: " << age << " years\n";                                                                                            // Display age of person
    std::cout << "BMI: " << bmi << "\n";                                                                                                  // Display Body Mass Index of person
    std::cout << "Maximum Heart Rate: " << maxRate << " bpm\n";                                                                           // Display Maximum heart Rate of person
    std::cout << "Target Heart Rate Range: " << lowerTarget << " - " << upperTarget << " bpm\n\n";                                        // Display Target heart Rate of person

    // Displaying BMI Chart
    std::cout << "\n--- BMI VALUES ---\n";
    std::cout << "Underweight: less than 18.5\n";
    std::cout << "Normal:      between 18.5 and 24.9\n";
    std::cout << "Overweight:  between 25 and 29.9\n";
    std::cout << "Obese:       30 or greater\n";

    return 0;
}