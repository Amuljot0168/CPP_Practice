#ifndef TURTLE_GRAPHICS_H
#define TURTLE_GRAPHICS_H

// Floor array of size 20 X 20
const int size = 20;

// Directions:
// 0->right , 1->down , 2-> Left, 3-> Up
extern int dx[4];
extern int dy[4];

// Declaring Functions
void printFloor(bool floor[size][size]);
void moveTurtle(bool floor[size][size], int &x, int &y, int direction, int steps, bool penDown);

#endif