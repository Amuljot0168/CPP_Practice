#ifndef GRADUATESTUDENT_H
#define GRADUATESTUDENT_H

#include "Amuljot_Oct6_task2_Student.h"

// Base class for all graduate-level students
class GraduateStudent : public Student
{
protected:
    std::string advisor; // Name of academic advisor

public:
    // Constructor to initialize graduate student details
    GraduateStudent(const std::string &n, const std::string &id, const std::string &dept, const std::string &adv);

    // Displays student info including advisor
    void displayInfo() const override;

    // Returns academic level
    std::string getLevel() const override;
};

// Represents a master's level graduate student
class MastersStudent : public GraduateStudent
{
public:
    // Constructor for master's student
    MastersStudent(const std::string &n, const std::string &id, const std::string &dept, const std::string &adv);

    // Displays master's student info
    void displayInfo() const override;

    // Returns academic level
    std::string getLevel() const override;
};

// Represents a master's student pursuing a thesis
class ThesisMastersStudent : public MastersStudent
{
    std::string thesisTitle; // Title of thesis

public:
    // Constructor includes thesis title
    ThesisMastersStudent(const std::string &n, const std::string &id, const std::string &dept,
                         const std::string &adv, const std::string &thesis);

    // Displays thesis student info including thesis title
    void displayInfo() const override;

    // Returns academic level
    std::string getLevel() const override;
};

// Represents a master's student pursuing a project instead of a thesis
class NonThesisMastersStudent : public MastersStudent
{
    std::string projectTitle; // Title of project

public:
    // Constructor includes project title
    NonThesisMastersStudent(const std::string &n, const std::string &id, const std::string &dept,
                            const std::string &adv, const std::string &project);

    // Displays project student info including project title
    void displayInfo() const override;

    // Returns academic level
    std::string getLevel() const override;
};

// Represents a doctoral student (PhD level)
class DoctoralStudent : public GraduateStudent
{
protected:
    std::string dissertationTitle; // Title of dissertation
    int yearsInProgram;            // Number of years in PhD program

public:
    // Constructor includes dissertation and years in program
    DoctoralStudent(const std::string &n, const std::string &id, const std::string &dept,
                    const std::string &adv, const std::string &dissertation, int years);

    // Displays doctoral student info
    void displayInfo() const override;

    // Returns academic level
    std::string getLevel() const override;
};

// Represents a PhD candidate (advanced doctoral student)
class PhDCandidate : public DoctoralStudent
{
public:
    // Constructor for PhD candidate
    PhDCandidate(const std::string &n, const std::string &id, const std::string &dept,
                 const std::string &adv, const std::string &dissertation, int years);

    // Displays PhD candidate info
    void displayInfo() const override;

    // Returns academic level
    std::string getLevel() const override;
};

// Represents a postdoctoral research fellow
class PostDocFellow : public GraduateStudent
{
    std::string researchGrant; // Name of research grant or funding source

public:
    // Constructor includes research grant
    PostDocFellow(const std::string &n, const std::string &id, const std::string &dept,
                  const std::string &adv, const std::string &grant);

    // Displays postdoc info including grant
    void displayInfo() const override;

    // Returns academic level
    std::string getLevel() const override { return "PostDocFellow"; }
};

#endif