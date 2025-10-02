#ifndef SIMPLETRON_H
#define SIMPLETRON_H

#include <vector>
class SimpleTron
{
private:
    const int MEMORY_SIZE = 100; // memory can store 100 words
    std::vector<int> memory;
    int accumulator;
    int instructionCounter;
    bool running;

public:
    SimpleTron();                                      // Constructor
    void loadProgram(const std::vector<int> &program); // Function load the program in memor
    void execute();                                    // Execute the instructions given
    void reset();                                      // Reset

private:
    void processInstruction(int instruction);
    void read(int address);
    void write(int address);
    void load(int address);
    void store(int address);
    void add(int address);
    void subtract(int address);
    void divide(int address);
    void multiply(int address);
    void branch(int address);
    void branchNeg(int address);
    void branchZero(int address);
};

#endif