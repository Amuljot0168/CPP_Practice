#include "Amuljot_Oct6_task2_UndergraduateStudent.h"

// Constructor for UngraduateStudent class
UndergraduateStudent::UndergraduateStudent(const std::string &n, const std::string &id, const std::string &dept,
                                           int y, int credits)
    : Student(n, id, dept), year(y), creditsEarned(credits) {}

// Displays full info including year and credits
void UndergraduateStudent::displayInfo() const
{
    Student::displayInfo();
    std::cout << "Year: " << year << "\nCredits Earned: " << creditsEarned << "\n";
}

// Returns level identifier for UndergraduateStudent
std::string UndergraduateStudent::getLevel() const
{
    return "Undergraduate";
}

// Freshman constructor
Freshman::Freshman(const std::string &n, const std::string &id, const std::string &dept, int y, int credits)
    : UndergraduateStudent(n, id, dept, y, credits) {}

// Displays full information
void Freshman::displayInfo() const
{
    UndergraduateStudent::displayInfo();
}

// Returns level identifier for Freshman
std::string Freshman::getLevel() const
{
    return "Freshman";
}

// Sophomore constructor
Sophomore::Sophomore(const std::string &n, const std::string &id, const std::string &dept, int y, int credits)
    : UndergraduateStudent(n, id, dept, y, credits) {}

// Displays Sophomore info
void Sophomore::displayInfo() const
{
    UndergraduateStudent::displayInfo();
}

// Returns level for Sophomore
std::string Sophomore::getLevel() const
{
    return "Sophomore";
}

// Junior Constructor
Junior::Junior(const std::string &n, const std::string &id, const std::string &dept, int y, int credits)
    : UndergraduateStudent(n, id, dept, y, credits) {}

// Dsiplay Junior information
void Junior::displayInfo() const
{
    UndergraduateStudent::displayInfo();
}

// Return level for Junior
std::string Junior::getLevel() const
{
    return "Junior";
}

// Senior Constructor
Senior::Senior(const std::string &n, const std::string &id, const std::string &dept, int y, int credits)
    : UndergraduateStudent(n, id, dept, y, credits) {}

// Display Senior information
void Senior::displayInfo() const
{
    UndergraduateStudent::displayInfo();
}

// Return level for Senior
std::string Senior::getLevel() const
{
    return "Senior";
}

// Constructor of HonorsSenior
HonorsSenior::HonorsSenior(const std::string &n, const std::string &id, const std::string &dept,
                           int y, int credits, const std::string &thesis)
    : Senior(n, id, dept, y, credits), thesisTitle(thesis) {}

// Display information including Thesis Title
void HonorsSenior::displayInfo() const
{
    Senior::displayInfo();
    std::cout << "Thesis Title: " << thesisTitle << std::endl;
}

// Return level of HonorSenior
std::string HonorsSenior::getLevel() const
{
    return "HonorsSenior";
}

// Constructor for ExhcangeSenior
ExchangeSenior::ExchangeSenior(const std::string &n, const std::string &id, const std::string &dept,
                               int y, int credits, const std::string &uni)
    : Senior(n, id, dept, y, credits), homeUniversity(uni) {}

// Display Information including exchnage form
void ExchangeSenior::displayInfo() const
{
    Senior::displayInfo();
    std::cout << "Exchange from: " << homeUniversity << std::endl;
}

// return level of exchangeSenior
std::string ExchangeSenior::getLevel() const { return "ExchangeSenior"; }