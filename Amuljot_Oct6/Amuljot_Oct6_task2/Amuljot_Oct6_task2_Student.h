#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
// Base class representing a generic student
class Student
{
protected:
    // Basic student attributes
    std::string name;
    std::string studentID;
    std::string department;

public:
    // Constructor to initialize student details
    Student(std::string n, std::string id, std::string dept);

    // Virtual destructor to allow proper cleanup in derived classes
    virtual ~Student() {}

    // Displays student information (can be overridden)
    virtual void displayInfo() const;

    // Returns the academic level (e.g., Freshman, Masters) — meant to be overridden
    virtual std::string getLevel() const;
};

#endif
