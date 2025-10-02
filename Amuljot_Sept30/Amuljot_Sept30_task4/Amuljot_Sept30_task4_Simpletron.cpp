#include "Amuljot_Sept30_task4_SimpleTron.h"
#include <iostream>

// Constructor
SimpleTron::SimpleTron() : memory(MEMORY_SIZE, 0), accumulator(0), instructionCounter(0), running(true) {}

// Function to load program
void SimpleTron::loadProgram(const std::vector<int> &program)
{
    for (int i = 0; i < program.size() && i < MEMORY_SIZE; i++)
    {
        memory[i] = program[i];
    }
}

// Function to execute the instructions
void SimpleTron::execute()
{
    while (running && instructionCounter < MEMORY_SIZE)
    {
        processInstruction(memory[instructionCounter]);
        ++instructionCounter;
    }
}

// Function to reset values
void SimpleTron::reset()
{
    memory.assign(MEMORY_SIZE, 0);
    accumulator = 0;
    instructionCounter = 0;
    running = true;
}

// Function which process each instruction
void SimpleTron::processInstruction(int instruction)
{
    int opcode = instruction / 100;
    int operand = instruction % 100;

    switch (opcode)
    {
    case 10: // Read
        read(operand);
        break;
    case 11: // Write
        write(operand);
        break;
    case 20: // LOAD
        load(operand);
        break;
    case 21: // STORE
        store(operand);
        break;
    case 30: // ADD
        add(operand);
        break;
    case 31: // SUBTRACT
        subtract(operand);
        break;
    case 32: // DIVIDE
        divide(operand);
        break;
    case 33: // MULTIPLY
        multiply(operand);
        break;
    case 40: // BRANCH
        branch(operand);
        break;
    case 41: // BRANCHNEG
        branchNeg(operand);
        break;
    case 42: // BRANCHZERO
        branchZero(operand);
        break;
    case 43: // HALT
        running = false;
        break;
    default:
        std::cerr << "Invalid opcode: " << opcode << "\n";
        running = false;
    }
}

// Function to read the address of instruction and input values
void SimpleTron::read(int address)
{
    std::cout << "Enter value for memory[" << address << "]: ";
    std::cin >> memory[address];
}

// Function to write (display the output)
void SimpleTron::write(int address)
{
    std::cout << "Output from memory[" << address << "]: " << memory[address] << "\n";
}

// Function load the value of address in accumulator
void SimpleTron::load(int address)
{
    accumulator = memory[address];
}

// Function to store the value from address to accumulator
void SimpleTron::store(int address)
{
    memory[address] = accumulator;
}

// Function add the value at memory in accumulator value
void SimpleTron::add(int address)
{
    accumulator += memory[address];
}

// Function subtract the value at memory in accumulator value
void SimpleTron::subtract(int address)
{
    accumulator -= memory[address];
}

// Function divide the value at memory in accumulator value
void SimpleTron::divide(int address)
{
    if (memory[address] != 0) // check value at denominator cannot be zero
        accumulator /= memory[address];
    else
    {
        std::cerr << "Division by zero error\n";
        running = false;
    }
}

// Function multiply the value at memory in accumulator value
void SimpleTron::multiply(int address)
{
    accumulator *= memory[address];
}

//// Function to branch to specific location in memory
void SimpleTron::branch(int address)
{
    instructionCounter = address - 1;
}

// Function  Branch to a specific location in memory if the accumulator is negative
void SimpleTron::branchNeg(int address)
{
    if (accumulator < 0)
        instructionCounter = address - 1;
}

// Function Branch to a specific location in memory if the accumulator is zero
void SimpleTron::branchZero(int address)
{
    if (accumulator == 0)
        instructionCounter = address - 1;
}
