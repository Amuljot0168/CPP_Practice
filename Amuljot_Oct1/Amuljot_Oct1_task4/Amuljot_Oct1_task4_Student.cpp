
#include "Amuljot_Oct1_task4_Student.h"

Student::Student(std::string name, std::string id, std::string dept) : name(name), studentID(id), department(dept) {};

void Student::displayInfo() const
{
    std::cout << "Name of Student: " << name << std::endl;
    std::cout << "Student ID: " << studentID << std::endl;
    std::cout << "Department: " << department << std::endl;
    std::cout << std::endl;
}

std::string Student::getLevel() const
{
    return "Student";
}