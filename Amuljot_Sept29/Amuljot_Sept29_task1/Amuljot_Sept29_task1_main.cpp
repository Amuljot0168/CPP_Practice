#include <iostream>

const int SIZE = 10;
int main()
{
    // a)Declare and initializing the array of size 10
    double numbers[SIZE] = {0.0, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9};

    // b) Declare a pointer nPtr points a variable of type double
    double *nPtr;

    // c)print the elements of array
    std::cout << "Printing the array "
                 " numbers "
                 ": \n";
    for (int i = 0; i < SIZE; i++)
    {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    // d)Assigning address of array numbers to the pointer
    nPtr = numbers;
    nPtr = &numbers[0];

    // e)Printing the elements of array using pointers
    std::cout << "Printing the array elements using pointers: \n";
    for (int i = 0; i < SIZE; i++)
    {
        std::cout << *(nPtr + i) << " ";
    }
    std::cout << std::endl;

    // f)Printing the elements of array using pointers as array name
    std::cout << "Printing the array elements using pointers as array name: \n";
    for (int i = 0; i < SIZE; i++)
    {
        std::cout << *(numbers + i) << " ";
    }
    std::cout << std::endl;

    // g)Use a for statement to print the elements of array numbers using pointer/subscript no- tation with pointer nPtr.
    for (int i = 0; i < SIZE; i++)
    {
        std::cout << nPtr[i] << " ";
    }
    std::cout << std::endl;

    // h)refer to 4th element of array using different approach
    std::cout << "Referring to 4th element using array subscript notation: " << numbers[3] << std::endl;
    std::cout << "Referring to 4th element using pointer subscript notation: " << *(numbers + 3) << std::endl;
    std::cout << "Referring to 4th element using pointer subscript notation: " << nPtr[3] << std::endl;
    std::cout << "Referring to 4th element using pointer offSet notation: " << *(nPtr + 3) << std::endl;
    std::cout << std::endl;

    // i)nPtr +8 refers to 8th element of array to find Value at this location
    std::cout << "Value at (nPtr+8) is : " << *(nPtr + 8) << std::endl;
    std::cout << std::endl;

    // j)Value at numbers[5] - 4
    nPtr = &numbers[5];
    nPtr -= 4;
    std::cout << "Value at location: " << *nPtr << std::endl;

    return 0;
}