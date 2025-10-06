#ifndef UNDERGRADUATE_STUDENT_H
#define UNDERGRADUATE_STUDENT_H

#include "Amuljot_Oct6_task2_Student.h"

class UndergraduateStudent : public Student
{
protected:
    int year;
    int creditsEarned;

public:
    UndergraduateStudent(const std::string &n, const std::string &id, const std::string &dept,
                         int y, int credits);
    void displayInfo() const override;
    std::string getLevel() const override;
};

class Freshman : public UndergraduateStudent
{
public:
    Freshman(const std::string &n, const std::string &id, const std::string &dept, int y, int credits);
    void displayInfo() const override;
    std::string getLevel() const override;
};

class Sophomore : public UndergraduateStudent
{
public:
    Sophomore(const std::string &n, const std::string &id, const std::string &dept, int y, int credits);
    void displayInfo() const override;
    std::string getLevel() const override;
};

class Junior : public UndergraduateStudent
{
public:
    Junior(const std::string &n, const std::string &id, const std::string &dept, int y, int credits);
    void displayInfo() const override;
    std::string getLevel() const override;
};

class Senior : public UndergraduateStudent
{
public:
    Senior(const std::string &n, const std::string &id, const std::string &dept, int y, int credits);
    void displayInfo() const override;
    std::string getLevel() const override;
};

class HonorsSenior : public Senior
{
    std::string thesisTitle;

public:
    HonorsSenior(const std::string &n, const std::string &id, const std::string &dept,
                 int y, int credits, const std::string &thesis);
    void displayInfo() const override;
    std::string getLevel() const override;
};

class ExchangeSenior : public Senior
{
    std::string homeUniversity;

public:
    ExchangeSenior(const std::string &n, const std::string &id, const std::string &dept,
                   int y, int credits, const std::string &uni);
    void displayInfo() const override;
    std::string getLevel() const override;
};

#endif
