#include "Amuljot_Sept29_task3_Header.h"

// Helper Function for evaluate function implementation
int doubleTheValue(int number)
{
    return 2 * number;
}

// Exchange function to exchange the values of double type numbers
void exchange(double *x, double *y)
{
    double temp = *x;
    *x = *y;
    *y = temp;
}

// Exchange function to exchange the values of float type numbers
void exchange(float *x, float *y)
{
    float temp = *x;
    *x = *y;
    *y = temp;
}

// Function which takes function pointer as parameter
int evaluate(int number, int (*poly)(int))
{
    return poly(number);
}