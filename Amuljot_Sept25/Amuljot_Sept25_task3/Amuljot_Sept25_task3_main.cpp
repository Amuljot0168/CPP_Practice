#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Amuljot_Sept25_task3_DeckOfCards.h"
#include "Amuljot_Sept25_task3_Utilities.h"

int main()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Creating deck
    DeckOfCards deck;
    // Shuffle the deck
    deck.shuffle();

    // Creating two 5 card poker players
    std::vector<Card> player1Hand;
    std::vector<Card> player2Hand;

    // Deal 5 cards to each player
    for (int i = 0; i < 5; ++i)
    {
        player1Hand.push_back(deck.dealCard());
        player2Hand.push_back(deck.dealCard());
    }

    // Print hands
    printHand(player1Hand, "Player 1");
    printHand(player2Hand, "Player 2");

    // Evaluate hands
    int score1 = 1;
    if (hasFourOfAKind(player1Hand))
        score1 = 7;
    else if (isFlush(player1Hand))
        score1 = 6;
    else if (hasThreeOfAKind(player1Hand))
        score1 = 4;
    else if (hasTwoPairs(player1Hand))
        score1 = 3;
    else if (hasPair(player1Hand))
        score1 = 2;

    int score2 = 1;
    if (hasFourOfAKind(player2Hand))
        score2 = 7;
    else if (isFlush(player2Hand))
        score2 = 6;
    else if (hasThreeOfAKind(player2Hand))
        score2 = 4;
    else if (hasTwoPairs(player2Hand))
        score2 = 3;
    else if (hasPair(player2Hand))
        score2 = 2;

    // Decide winner
    std::cout << "Result: ";
    if (score1 > score2)
        std::cout << "Player 1 wins!\n";
    else if (score2 > score1)
        std::cout << "Player 2 wins!\n";
    else
        std::cout << "It's a tie!\n";

    return 0;
}