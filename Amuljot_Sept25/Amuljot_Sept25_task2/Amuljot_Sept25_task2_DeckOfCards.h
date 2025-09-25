#ifndef DECKOFCARDS_H
#define DECKOFCARDS_H
#include <vector>
#include "Amuljot_Sept25_task2_Card.h"

class DeckOfCards
{
private:
    std::vector<Card> deck; // contains all 52 cards
    int currentCard;        // Index of next card to deal

public:
    // Default Constructor
    DeckOfCards();

    // Function to shuffle the cards
    void shuffle();

    // Function to return next card object from deck
    Card dealCard();

    // Function to check there are more cards to deal or not
    bool moreCards() const;
};

#endif