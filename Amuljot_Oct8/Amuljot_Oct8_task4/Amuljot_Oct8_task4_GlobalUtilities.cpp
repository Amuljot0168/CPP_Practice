#include <iostream>
#include <map>
#include <fstream>

#include "Amuljot_Oct8_task4_GlobalUtilities.h"

// Method to convert GradeLevel to string
std::string gradeToString(GradeLevel g)
{
    switch (g)
    {
    case GradeLevel::Fail:
        return "Fail";
    case GradeLevel::Pass:
        return "Pass";
    case GradeLevel::Merit:
        return "Merit";
    case GradeLevel::Distinction:
        return "Distinction";
    default:
        return "Unknown";
    }
}

// Summarizes all grades with their counts
void summarizeGrades(Student *students[], int studentCount)
{
    // Initializing each grade to 0
    std::map<GradeLevel, int> grade_map = {
        {GradeLevel::Fail, 0},
        {GradeLevel::Pass, 0},
        {GradeLevel::Merit, 0},
        {GradeLevel::Distinction, 0}};

    // Storing values in map
    for (int i = 0; i < studentCount; i++)
    {
        if (students[i] == nullptr) // if student is nullptr then continue;
            continue;

        for (int j = 0; j < 10; j++)
        {
            SubjectScore subScore = students[i]->getSubjectAt(j);
            if (subScore.getSubjectName() != "")
            {
                grade_map[subScore.getGrade()]++;
            }
        }
    }

    // Displaying summary of grades and their counts
    std::cout << "\nGrade Summary: \n";

    for (const auto &level : grade_map)
    {
        std::cout << gradeToString(level.first) << ": " << level.second << std::endl;
    }
    std::cout << std::endl;
}

// Finds the highest score for a given subject across all students
const SubjectScore *findTopScorer(Student *students[], int studentCount, const std::string &subject)
{
    SubjectScore *max_one = nullptr;
    int maxScore = -1;

    for (int i = 0; i < studentCount; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            SubjectScore subscore = students[i]->getSubjectAt(j);
            if ((subscore.getSubjectName() == subject) && (subscore.getScore() > maxScore))
            {
                maxScore = subscore.getScore();
                max_one = new SubjectScore(subscore);
            }
        }
    }
    return max_one;
}

// Export all distinction students to other file
void exportAllDistinctions(Student *students[], int studentCount, const std::string &filename)
{
    std::ofstream out(filename);

    for (int i = 0; i < studentCount; i++)
    {
        if (students[i] == nullptr)
            continue;
        for (int j = 0; j < 10; ++j)
        {
            SubjectScore s = students[i]->getSubjectAt(j);
            if (s.getGrade() == GradeLevel::Distinction)
            {
                out << s.getSubjectName() << "," << s.getScore() << "," << i << "\n";
            }
        }
    }

    out.close();
    std::cout << "Distinction scores exported to " << filename << " Successfully!!!" << std::endl;
}
