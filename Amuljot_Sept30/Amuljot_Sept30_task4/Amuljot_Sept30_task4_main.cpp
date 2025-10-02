#include <iostream>
#include <vector>

#include "Amuljot_Sept30_task4_Simpletron.h"

int main()
{
    SimpleTron sim;

    std::vector<int> program;

    std::cout << "Enter SML instructions (-99999 to end):\n";
    int instruction;
    while (true)
    {
        std::cout << "> ";
        std::cin >> instruction;
        if (instruction == -99999)
            break;
        program.push_back(instruction);
    }

    sim.loadProgram(program);
    sim.execute();

    return 0;
}
