#ifndef HEADER_H
#define HEADER_H

// a) Function header for exchange
// b) Function prototype for exchange
void exchange(double *x, double *y);
void exchange(float *x, float *y);

// c) Function header for exchange
// d) Function prototype for exchange
int evaluate(int x, int (*poly)(int));

// Helper Function for d)
int doubleTheValue(int number);
#endif