#include <iostream>

int main()
{

    //  Declare and initialize variables
    float number1 = 7.3f; // Initialized as per the problem
    float number2;
    char *ptr;
    char s1[100] = "Hello from s1";
    char s2[100] = "Hello from s2";

    // a) Declare variable fPtr
    double *fPtr;

    // b) Assigning the address of variable number1 to fPtr
    fPtr = reinterpret_cast<double *>(&number1);

    // c) Print the value at ptr
    std::cout << "Value pointed to by fPtr : " << *fPtr << std::endl;

    // d) Assigning the value of object to number2
    number2 = static_cast<float>(*fPtr);

    // e)Printing value of number2
    std::cout << "Value of number2: " << number2 << std::endl;

    // f)Printing the address of number1
    std::cout << "Address of number1: " << &number1 << std::endl;

    // g) Print address stored in fPtr
    std::cout << "Address stored in fPtr: " << fPtr << std::endl;

    // Confirm if fPtr and &number1 match
    if (reinterpret_cast<void *>(fPtr) == reinterpret_cast<void *>(&number1))
    {
        std::cout << "Yes, fPtr points to the same address as number1." << std::endl;
    }
    else
    {
        std::cout << "No, fPtr does not point to the same address as number1." << std::endl;
    }

    return 0;
}