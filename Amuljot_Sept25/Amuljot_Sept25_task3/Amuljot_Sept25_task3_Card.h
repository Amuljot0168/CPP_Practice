#include <string>
#ifndef CARD_H
#define CARD_H

class Card
{
private:
    int face; // Face of card
    int suit; // Suit of card

public:
    // Parameterised Constructor
    Card(const int face_of_Card, const int suit_of_card);

    // Two static arrays
    static const std::string faces[13];
    static const std::string suits[4];

    // Get Function
    int getFace() const;
    int getSuit() const;

    // Function return the card as string
    std::string toString() const;
};
#endif