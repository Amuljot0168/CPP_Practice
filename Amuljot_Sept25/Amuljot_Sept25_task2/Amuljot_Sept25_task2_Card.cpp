#include <iostream>
#include <string>
#include "Amuljot_Sept25_task2_Card.h"

// Define static arrays
const std::string Card::faces[13] = {
    "Ace", "Two", "Three", "Four", "Five", "Six", "Seven",
    "Eight", "Nine", "Ten", "Jack", "Queen", "King"};

const std::string Card::suits[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};

// Constructor
Card::Card(const int face_of_card, const int suit_of_card) : face(face_of_card), suit(suit_of_card) {}

std::string Card::toString() const
{
    std::string cardString = faces[face] + " of " + suits[suit];

    return cardString;
}