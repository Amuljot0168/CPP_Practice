#include "Amuljot_Oct6_task2_GraduateStudent.h"

// Constructor to initialize graduate student details
GraduateStudent::GraduateStudent(const std::string &n, const std::string &id, const std::string &dept, const std::string &adv)
    : Student(n, id, dept), advisor(adv) {}

// Displays student info including advisor
void GraduateStudent::displayInfo() const
{
    Student::displayInfo();
    std::cout << "Advisor: " << advisor << std::endl;
}
// Returns academic level
std::string GraduateStudent::getLevel() const { return "Graduate Student"; }

// Constructor for master's student
MastersStudent::MastersStudent(const std::string &n, const std::string &id, const std::string &dept, const std::string &adv)
    : GraduateStudent(n, id, dept, adv) {}

// Displays master's student info
void MastersStudent::displayInfo() const
{
    GraduateStudent::displayInfo();
}

// Returns academic level
std::string MastersStudent::getLevel() const { return "MastersStudent"; }

// Constructor includes thesis title
ThesisMastersStudent::ThesisMastersStudent(const std::string &n, const std::string &id, const std::string &dept,
                                           const std::string &adv, const std::string &thesis)
    : MastersStudent(n, id, dept, adv), thesisTitle(thesis) {}

// Displays thesis student info including thesis title
void ThesisMastersStudent::displayInfo() const
{
    GraduateStudent::displayInfo();
    std::cout << "Thesis: " << thesisTitle << std::endl;
}

// Returns academic level
std::string ThesisMastersStudent::getLevel() const { return "ThesisMastersStudent"; }

// Constructor of NonThesisMaster Students
NonThesisMastersStudent::NonThesisMastersStudent(const std::string &n, const std::string &id, const std::string &dept,
                                                 const std::string &adv, const std::string &project)
    : MastersStudent(n, id, dept, adv), projectTitle(project) {}

// Displays project student info including project title
void NonThesisMastersStudent::displayInfo() const
{
    GraduateStudent::displayInfo();
    std::cout << "Project: " << projectTitle << std::endl;
}

// Returns academic level
std::string NonThesisMastersStudent::getLevel() const { return "NonThesisMastersStudent"; }

// Constructor of Doctoral Students
DoctoralStudent::DoctoralStudent(const std::string &n, const std::string &id, const std::string &dept,
                                 const std::string &adv, const std::string &dissertation, int years)
    : GraduateStudent(n, id, dept, adv), dissertationTitle(dissertation), yearsInProgram(years) {}

// Display information of student including dissertation
void DoctoralStudent::displayInfo() const
{
    GraduateStudent::displayInfo();
    std::cout << "Dissertation: " << dissertationTitle << ", Years: " << yearsInProgram << std::endl;
}

// return academic level
std::string DoctoralStudent::getLevel() const { return "DoctoralStudent"; }

// Constructor for PhD Students
PhDCandidate::PhDCandidate(const std::string &n, const std::string &id, const std::string &dept,
                           const std::string &adv, const std::string &dissertation, int years)
    : DoctoralStudent(n, id, dept, adv, dissertation, years) {}

// Display information of student including level
void PhDCandidate::displayInfo() const
{
    DoctoralStudent::displayInfo();
    std::cout << "Level: PhDCandidate" << std::endl;
}

// return academic level
std::string PhDCandidate::getLevel() const { return "PhDCandidate"; }

// Constructor for PostDoc Students
PostDocFellow::PostDocFellow(const std::string &n, const std::string &id, const std::string &dept,
                             const std::string &adv, const std::string &grant)
    : GraduateStudent(n, id, dept, adv), researchGrant(grant) {}

// display information of students
void PostDocFellow::displayInfo() const
{
    GraduateStudent::displayInfo();
    std::cout << "Research Grant: " << researchGrant << std::endl;
}

// return academic level
std::string PostDocFellow::getLevel() const { return "PostDocFellow"; }