#include <iostream>
#include <vector>
#include <typeinfo>
#include "Amuljot_Oct6_task2_Student.h"
#include "Amuljot_Oct6_task2_GraduateStudent.h"
#include "Amuljot_Oct6_task2_UndergraduateStudent.h"

int main()
{
    // Sample data
    Freshman f("Amit", "UG101", "Computer Science", 1, 15);
    HonorsSenior hs("Neha", "UG401", "Physics", 4, 120, "Quantum Entanglement Thesis");
    ExchangeSenior es("Luca", "UG402", "Mechanical", 4, 110, "Politecnico di Milano");
    ThesisMastersStudent tm("Priya", "GR201", "Electrical", "Dr. Rao", "Smart Grid Optimization");
    NonThesisMastersStudent ntm("Raj", "GR202", "Civil", "Dr. Mehta", "Bridge Load Simulation");
    PhDCandidate phd("Sneha", "GR301", "Biotech", "Dr. Kapoor", "Gene Editing Ethics", 3);
    PostDocFellow pdf("Dr. Tanmay", "GR401", "AI Research", "Dr. Bose", "DARPA Grant");

    std::vector<Student *> students = {&f, &hs, &es, &tm, &ntm, &phd, &pdf};

    for (auto s : students)
    {
        std::cout << "---- " << s->getLevel() << " ----" << std::endl;
        s->displayInfo();
        std::cout << std::endl;
    }

    return 0;
}