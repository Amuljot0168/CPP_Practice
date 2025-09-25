#include <iostream>
#include <cstdlib> // For rand()
#include <ctime>   // For time()
#include "Amuljot_Sept25_task2_DeckOfCards.h"

int main()
{

    // Seed the random number generator
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Create and shuffle the deck
    DeckOfCards *deck = new DeckOfCards();
    deck->shuffle();

    std::cout << "Shuffled deck — dealing all 52 cards:\n\n";

    // Deal all cards
    int count = 1;
    while (deck->moreCards())
    {
        std::cout << count++ << ". " << deck->dealCard().toString() << "\n";
    }

    std::cout << "\nAll cards dealt.\n";

    // Free Up Memory
    delete deck;

    return 0;
}