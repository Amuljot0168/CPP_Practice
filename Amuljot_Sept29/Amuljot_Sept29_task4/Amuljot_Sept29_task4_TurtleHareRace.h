#ifndef TURTLE_HARE_RACE_H
#define TURTLE_HARE_RACE_H

const int RACE_TRACK_LENGTH = 70; // Race Track has 70 squares

const int START_POSITION = 1;

void moveTortoise(int *pos); // Function to move the tortoise

void moveHare(int *pos); // Function to move the hare

void printTrack(int TortoisePosition, int HarePosition); // Print the positions of Tortoise and Hare

#endif