#include <iostream>
#include "Amuljot_Sept26_task1_DoubleScriptedArray.h"
using namespace std;

int main()
{
     // 1. Constructor: Create a 3x4 array
     DoubleSubscriptedArray array1(3, 4);
     cout << "Enter 12 values for array 'a' (3x4):\n";
     cin >> array1;

     // 2. Output using << operator
     cout << "\nArray 'array1' contents:\n"
          << array1;

     // 3. Modify an element using operator()
     array1(1, 2) = 99;
     cout << "\nAfter modifying array1(1,2) to 99:\n"
          << array1;

     // 4. Access an element using const operator()
     cout << "Value at array1(1,2): " << array1(1, 2) << "\n";

     // 5. Copy constructor
     DoubleSubscriptedArray array2 = array1;
     cout << "\nArray 'array2' (copy of 'array1'):\n"
          << array2;

     // 6. Equality check
     if (array1 == array2)
          cout << "Arrays 'array1' and 'array2' are equal.\n";
     else
          cout << "Arrays 'array1' and 'array2' are not equal.\n";

     // 7. Modify 'b' and check inequality
     array2(0, 0) = -1;
     cout << "\nModified array2(0,0) to -1:\n"
          << array2;

     if (array1 != array2)
          cout << "Arrays 'array1' and 'array2' are now different.\n";

     // 8. Assignment operator
     DoubleSubscriptedArray array3;
     array3 = array2;
     cout << "\nArray 3 after assignment from 'array2':\n"
          << array3;

     // 9. Display dimensions
     cout << "Array 'c' has " << array3.getRows() << " rows and " << array3.getColumns() << " columns.\n";

     return 0;
}