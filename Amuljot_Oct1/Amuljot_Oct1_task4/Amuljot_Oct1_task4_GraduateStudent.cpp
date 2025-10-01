#include "Amuljot_Oct1_task4_GraduateStudent.h"

GraduateStudent::GraduateStudent(const std::string &n, const std::string &id, const std::string &dept, const std::string &adv)
    : Student(n, id, dept), advisor(adv) {}
void GraduateStudent::displayInfo() const
{
    Student::displayInfo();
    std::cout << "Advisor: " << advisor << std::endl;
}
std::string GraduateStudent::getLevel() const { return "Graduate Student"; }

MastersStudent::MastersStudent(const std::string &n, const std::string &id, const std::string &dept, const std::string &adv)
    : GraduateStudent(n, id, dept, adv) {}
void MastersStudent::displayInfo() const
{
    GraduateStudent::displayInfo();
}
std::string MastersStudent::getLevel() const { return "MastersStudent"; }

ThesisMastersStudent::ThesisMastersStudent(const std::string &n, const std::string &id, const std::string &dept,
                                           const std::string &adv, const std::string &thesis)
    : MastersStudent(n, id, dept, adv), thesisTitle(thesis) {}
void ThesisMastersStudent::displayInfo() const
{
    GraduateStudent::displayInfo();
    std::cout << "Thesis: " << thesisTitle << std::endl;
}
std::string ThesisMastersStudent::getLevel() const { return "ThesisMastersStudent"; }

NonThesisMastersStudent::NonThesisMastersStudent(const std::string &n, const std::string &id, const std::string &dept,
                                                 const std::string &adv, const std::string &project)
    : MastersStudent(n, id, dept, adv), projectTitle(project) {}
void NonThesisMastersStudent::displayInfo() const
{
    GraduateStudent::displayInfo();
    std::cout << "Project: " << projectTitle << std::endl;
}
std::string NonThesisMastersStudent::getLevel() const { return "NonThesisMastersStudent"; }

DoctoralStudent::DoctoralStudent(const std::string &n, const std::string &id, const std::string &dept,
                                 const std::string &adv, const std::string &dissertation, int years)
    : GraduateStudent(n, id, dept, adv), dissertationTitle(dissertation), yearsInProgram(years) {}
void DoctoralStudent::displayInfo() const
{
    GraduateStudent::displayInfo();
    std::cout << "Dissertation: " << dissertationTitle << ", Years: " << yearsInProgram << std::endl;
}
std::string DoctoralStudent::getLevel() const { return "DoctoralStudent"; }

PhDCandidate::PhDCandidate(const std::string &n, const std::string &id, const std::string &dept,
                           const std::string &adv, const std::string &dissertation, int years)
    : DoctoralStudent(n, id, dept, adv, dissertation, years) {}
void PhDCandidate::displayInfo() const
{
    DoctoralStudent::displayInfo();
    std::cout << "Level: PhDCandidate" << std::endl;
}
std::string PhDCandidate::getLevel() const { return "PhDCandidate"; }

PostDocFellow::PostDocFellow(const std::string &n, const std::string &id, const std::string &dept,
                             const std::string &adv, const std::string &grant)
    : GraduateStudent(n, id, dept, adv), researchGrant(grant) {}

void PostDocFellow::displayInfo() const
{
    GraduateStudent::displayInfo();
    std::cout << "Research Grant: " << researchGrant << std::endl;
}

std::string PostDocFellow::getLevel() const { return "PostDocFellow"; }