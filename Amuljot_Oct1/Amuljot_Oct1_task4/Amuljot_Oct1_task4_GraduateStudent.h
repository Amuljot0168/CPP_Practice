#ifndef GRADUATESTUDENT_H
#define GRADUATESTUDENT_H

#include "Amuljot_Oct1_task4_Student.h"

class GraduateStudent : public Student
{
protected:
    std::string advisor;

public:
    GraduateStudent(const std::string &n, const std::string &id, const std::string &dept, const std::string &adv);
    void displayInfo() const override;
    std::string getLevel() const override;
};

class MastersStudent : public GraduateStudent
{
public:
    MastersStudent(const std::string &n, const std::string &id, const std::string &dept, const std::string &adv);
    void displayInfo() const override;
    std::string getLevel() const override;
};

class ThesisMastersStudent : public MastersStudent
{
    std::string thesisTitle;

public:
    ThesisMastersStudent(const std::string &n, const std::string &id, const std::string &dept,
                         const std::string &adv, const std::string &thesis);
    void displayInfo() const override;
    std::string getLevel() const override;
};

class NonThesisMastersStudent : public MastersStudent
{
    std::string projectTitle;

public:
    NonThesisMastersStudent(const std::string &n, const std::string &id, const std::string &dept,
                            const std::string &adv, const std::string &project);
    void displayInfo() const override;
    std::string getLevel() const override;
};

class DoctoralStudent : public GraduateStudent
{
protected:
    std::string dissertationTitle;
    int yearsInProgram;

public:
    DoctoralStudent(const std::string &n, const std::string &id, const std::string &dept,
                    const std::string &adv, const std::string &dissertation, int years);
    void displayInfo() const override;
    std::string getLevel() const override;
};

class PhDCandidate : public DoctoralStudent
{
public:
    PhDCandidate(const std::string &n, const std::string &id, const std::string &dept,
                 const std::string &adv, const std::string &dissertation, int years);
    void displayInfo() const override;
    std::string getLevel() const override;
};

class PostDocFellow : public GraduateStudent
{
    std::string researchGrant;

public:
    PostDocFellow(const std::string &n, const std::string &id, const std::string &dept,
                  const std::string &adv, const std::string &grant);
    void displayInfo() const override;
    std::string getLevel() const override { return "PostDocFellow"; }
};

#endif