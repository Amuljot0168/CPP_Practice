#include <iostream>
#include <vector>
#include <cstdlib> // For rand()
#include <ctime>   // For time()

#include "Amuljot_Sept25_task3_DeckOfCards.h"

// Default Constructor initializing the 52 cards
DeckOfCards::DeckOfCards() : currentCard(0)
{
    for (int suit = 0; suit < 4; suit++)
    {
        for (int face = 0; face < 13; face++)
        {
            deck.push_back(Card(face, suit));
        }
    }
}

// Function to shuffle the card by randomly select the card and swap two cards
void DeckOfCards::shuffle()
{
    for (int i = 0; i < deck.size(); i++)
    {
        int random = std::rand() % deck.size();
        std::swap(deck[i], deck[random]);
    }

    currentCard = 0;
}

// Retunr the next card to deal from deck
Card DeckOfCards::dealCard()
{
    if (moreCards())
    {
        return deck[currentCard++];
    }
    else
    {
        std::cout << "Error! No cards to deal...\n";
        return Card(0, 0); // return default card (Ace of Hearts)
    }
}

// Return a bool value if there are more cards to deal
bool DeckOfCards::moreCards() const
{
    // Check if there are more cards in deck
    if (currentCard < deck.size())
    {
        return true; // if yes return true
    }
    else
    {
        return false; // if not return false
    }
}