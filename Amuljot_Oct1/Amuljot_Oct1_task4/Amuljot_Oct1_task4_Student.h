#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>

class Student
{
protected:
    std::string name;
    std::string studentID;
    std::string department;

public:
    Student(std::string n, std::string id, std::string dept);
    virtual ~Student() {}

    virtual void displayInfo() const;
    virtual std::string getLevel() const;
};

#endif
