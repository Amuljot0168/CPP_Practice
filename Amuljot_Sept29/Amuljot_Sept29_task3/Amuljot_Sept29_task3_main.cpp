#include <iostream>
#include <string>
#include "Amuljot_Sept29_task3_Header.h"

int main()
{
    // Test for exchange
    double number1 = 78.1;
    double number2 = 54.2;

    std::cout << "Before exchange:\n";
    std::cout << "number1 = " << number1 << ", number2 = " << number2 << std::endl;

    exchange(&number1, &number2);

    std::cout << "After exchange:\n";
    std::cout << "number1 = " << number1 << ", number2 = " << number2 << std::endl;

    // Test for exhchange function which takes float number
    // Test for exchange
    float number3 = 10.0f;
    float number4 = 20.0f;

    std::cout << "Before exchange:\n";
    std::cout << "number3 = " << number3 << ", number4 = " << number4 << std::endl;

    exchange(&number3, &number4);

    std::cout << "After exchange:\n";
    std::cout << "number3 = " << number3 << ", number4 = " << number4 << std::endl;

    // Test for evaluate
    int result = evaluate(500, doubleTheValue);
    std::cout << "Result of evaluate(500, doubleTheValue): " << result << std::endl;

    // e) Two ways to initialize character array vowel with "AEIOU"
    char vowel1[] = "AEIOU";
    char vowel2[] = {'A', 'E', 'I', 'O', 'U', '\0'};

    std::cout << "vowel1 = " << vowel1 << std::endl;
    std::cout << "vowel2 = " << vowel2 << std::endl;

    return 0;
}
