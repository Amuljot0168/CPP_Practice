#include <iostream>

const int SIZE = 5;
int main()
{
    // a)Declare an array of type unsigned int and initialize with even integers
    unsigned int values[SIZE] = {2, 4, 6, 8, 10};

    // b) declaring a pointer
    unsigned int *vPtr;

    // c)using for loop to print the elements
    std::cout << "Printing the elements of array values: \n";
    for (int i = 0; i < SIZE; i++)
    {
        std::cout << values[i] << " ";
    }
    std::cout << std::endl;

    // d)writing two seaprate statements to assign address of array values to pointer
    vPtr = values;
    vPtr = &values[0];
    // e)using for loop to print the elements of array values using pointer notation
    for (int i = 0; i < SIZE; i++)
    {
        std::cout << *(vPtr + i) << " ";
    }
    std::cout << std::endl;

    // f)using for loop to print the elements of array values using pointer notation
    for (int i = 0; i < SIZE; i++)
    {
        std::cout << *(values + i) << " ";
    }
    std::cout << std::endl;

    // g)Use a for statement to print the elements of array values by subscripting the pointer to the array
    for (int i = 0; i < SIZE; i++)
    {
        std::cout << vPtr[i] << " ";
    }
    std::cout << std::endl;

    // h)Referring to 5 th element of array
    std::cout << "\n5th element of array using  array subscript notation: " << values[4] << std::endl;                             // array subscript notation
    std::cout << "5th element of array using  pointer offset notation with array name as pointer: " << *(values + 4) << std::endl; // pointer/offset notation with the array name as the pointer
    std::cout << "5th element of array using  pointer subscript notation: " << vPtr[4] << std::endl;                               // pointer subscript notation
    std::cout << "5th element of array using pointer/offset notation: " << *(vPtr + 4) << std::endl;                               // pointer/offset notation

    // i)Address referenced by vPtr+3 is
    // Address: 1002500 + (3 * 2 bytes) = 1002506
    // Value: values[3] = 8
    std::cout << "Address: " << (vPtr + 3) << ", Value: " << *(vPtr + 3) << std::endl;

    // j)
    vPtr = &values[4]; // Now points to 10
    vPtr -= 4;         // Now points to values[0] = 2
    std::cout << "Address: " << vPtr << ", Value: " << *vPtr << std::endl;
    return 0;
}