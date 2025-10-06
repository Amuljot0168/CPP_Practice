
#include "Amuljot_Oct6_task2_Student.h"

// Constructor of Student Class
Student::Student(std::string name, std::string id, std::string dept) : name(name), studentID(id), department(dept) {};

// Displays the student's basic information
void Student::displayInfo() const
{
    std::cout << "Name of Student: " << name << std::endl;
    std::cout << "Student ID: " << studentID << std::endl;
    std::cout << "Department: " << department << std::endl;
    std::cout << std::endl;
}

// Returns the default academic level for base Student class
std::string Student::getLevel() const
{
    return "Student";
}