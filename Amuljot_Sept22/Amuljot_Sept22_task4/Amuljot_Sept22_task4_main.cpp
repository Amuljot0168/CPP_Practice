#include <iostream>
#include "Amuljot_Sept22_task4_HeartRates.h"

int main()
{
    std::string firstName, lastName;
    int birthDay, birthMonth, birthYear;

    // Prompt user for personal info
    std::cout << "Enter first name: ";
    std::cin >> firstName;
    std::cout << "Enter last name: ";
    std::cin >> lastName;
    std::cout << "Enter birth day (1-31): ";
    std::cin >> birthDay;
    std::cout << "Enter birth month (1-12): ";
    std::cin >> birthMonth;
    std::cout << "Enter birth year: ";
    std::cin >> birthYear;

    // Inputing the current Date from user
    int currentDay, currentMonth, currentYear;
    std::cout << "Enter current day: ";
    std::cin >> currentDay;
    std::cout << "Enter current month: ";
    std::cin >> currentMonth;
    std::cout << "Enter current year: ";
    std::cin >> currentYear;

    // Create HeartRates object
    HeartRates *person1 = new HeartRates(firstName, lastName, birthDay, birthMonth, birthYear);

    // Display personal information
    std::cout << "\n--- Heart Rate Summary ---\n";
    std::cout << "Name: " << person1->getFirstName() << " " << person1->getLastName() << std::endl;
    std::cout << "Date of Birth: " << person1->getBirthDay() << "/"
              << person1->getBirthMonth() << "/" << person1->getBirthYear() << std::endl;

    // Display age of person

    std::cout << "Age: " << person1->getAge(currentDay, currentMonth, currentYear) << " years" << std::endl;

    // Display maximum heart rate of person
    std::cout << "Maximum Heart Rate: " << person1->getMaximumHeartRate(currentDay, currentMonth, currentYear) << " bpm" << std::endl;

    // Display target heart rate of person
    person1->getTargetHeartRate(currentDay, currentMonth, currentYear);

    // Freeing the memory
    delete person1;
    return 0;
}