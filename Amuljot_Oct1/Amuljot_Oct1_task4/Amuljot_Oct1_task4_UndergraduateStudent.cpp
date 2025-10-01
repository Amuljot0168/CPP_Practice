#include "Amuljot_Oct1_task4_UndergraduateStudent.h"

UndergraduateStudent::UndergraduateStudent(const std::string &n, const std::string &id, const std::string &dept,
                                           int y, int credits)
    : Student(n, id, dept), year(y), creditsEarned(credits) {}

void UndergraduateStudent::displayInfo() const
{
    Student::displayInfo();
    std::cout << "Year: " << year << "\nCredits Earned: " << creditsEarned << "\n";
}

std::string UndergraduateStudent::getLevel() const
{
    return "Undergraduate";
}

Freshman::Freshman(const std::string &n, const std::string &id, const std::string &dept, int y, int credits)
    : UndergraduateStudent(n, id, dept, y, credits) {}

void Freshman::displayInfo() const
{
    UndergraduateStudent::displayInfo();
}
std::string Freshman::getLevel() const
{
    return "Freshman";
}

Sophomore::Sophomore(const std::string &n, const std::string &id, const std::string &dept, int y, int credits)
    : UndergraduateStudent(n, id, dept, y, credits) {}
void Sophomore::displayInfo() const
{
    UndergraduateStudent::displayInfo();
}

std::string Sophomore::getLevel() const
{
    return "Sophomore";
}

Junior::Junior(const std::string &n, const std::string &id, const std::string &dept, int y, int credits)
    : UndergraduateStudent(n, id, dept, y, credits) {}
void Junior::displayInfo() const
{
    UndergraduateStudent::displayInfo();
}
std::string Junior::getLevel() const
{
    return "Junior";
}

Senior::Senior(const std::string &n, const std::string &id, const std::string &dept, int y, int credits)
    : UndergraduateStudent(n, id, dept, y, credits) {}
void Senior::displayInfo() const
{
    UndergraduateStudent::displayInfo();
}

std::string Senior::getLevel() const
{
    return "Senior";
}
HonorsSenior::HonorsSenior(const std::string &n, const std::string &id, const std::string &dept,
                           int y, int credits, const std::string &thesis)
    : Senior(n, id, dept, y, credits), thesisTitle(thesis) {}
void HonorsSenior::displayInfo() const
{
    Senior::displayInfo();
    std::cout << "Thesis Title: " << thesisTitle << std::endl;
}

std::string HonorsSenior::getLevel() const
{
    return "HonorsSenior";
}

ExchangeSenior::ExchangeSenior(const std::string &n, const std::string &id, const std::string &dept,
                               int y, int credits, const std::string &uni)
    : Senior(n, id, dept, y, credits), homeUniversity(uni) {}

void ExchangeSenior::displayInfo() const
{
    Senior::displayInfo();
    std::cout << "Exchange from: " << homeUniversity << std::endl;
}

std::string ExchangeSenior::getLevel() const { return "ExchangeSenior"; }