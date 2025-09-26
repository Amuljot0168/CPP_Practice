#include <iostream>
#include <string>
#include "Amuljot_Sept26_task3_HugeInt.h"

int main()
{
    // Creating numbers of HugeInt
    HugeInt number1(7654321);
    HugeInt number2(7891234);
    HugeInt number3("99999999999999999999999999999");
    HugeInt number4("1");
    HugeInt number5;

    // Showing numbers as HugeInt
    std::cout << "number1 is " << number1 << "\n number2 is " << number2
              << "\nnumber3 is " << number3 << "\nnumber4 is " << number4
              << "\nnumber5 is " << number5 << "\n\n";

    number5 = number1 + number2; // Triggering + operator that we overload

    std::cout << number1 << " + " << number2 << " = " << number5 << "\n\n"; // output the added values

    std::cout << number3 << " + " << number4 << "\n= " << (number3 + number4) << "\n\n";

    number5 = number1 + 9; // Triggering + operator that we overload

    std::cout << number1 << " + " << 9 << " = " << number5 << "\n\n"; // output the added values

    number5 = number2 + "10000";
    std::cout << number2 << " + " << "10000" << " = " << number5 << "\n\n"; // output the added values

    HugeInt product = number1 * number2; // Triggering * operator that we overlaod
    std::cout << number1 << " * " << number2 << " = " << product << "\n\n";

    // Using COmparison Operators
    if (number1 == number2)
        std::cout << "number1 and number2 are equal\n";
    else
        std::cout << "number1 and number2 are not equal\n";

    if (number3 > number4)
        std::cout << "number3 is greater than number4\n";
    else
        std::cout << "number3 is not greater than number4\n";

    return 0;
}
