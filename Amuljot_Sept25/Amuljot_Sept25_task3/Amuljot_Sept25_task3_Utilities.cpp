
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include "Amuljot_Sept25_task3_Utilities.h"

// helper Function to calculate frequency of each face card
std::map<int, int> Facefrequency(const std::vector<Card> &hand)
{
    std::map<int, int> map_face;
    for (int i = 0; i < hand.size(); i++)
    {
        map_face[hand[i].getFace()]++;
    }
    return map_face;
}

// Check if hand has same face 2 cards
bool hasPair(const std::vector<Card> &hand)
{
    std::map<int, int> frequncies_of_hand = Facefrequency(hand); // Calculate the frequency of card using FaceFrequency method
    for (auto freq : frequncies_of_hand)
    {
        if (freq.second == 2)
        {
            return true; // Return true when there is pair
        }
    }
    return false;
}

// Check if hand has two pairs
bool hasTwoPairs(const std::vector<Card> &hand)
{
    std::map<int, int> frequncies_of_hand = Facefrequency(hand); // Calculate the frequency of card using FaceFrequency method
    int pairCount = 0;
    for (auto freq : frequncies_of_hand)
    {
        if (freq.second == 2)
        {
            pairCount++; // Return true when there is pair
        }
    }
    if (pairCount == 2)
    {
        return true; // return true ,If hand contains two pairs
    }
    else
    {
        return false; // return false , If hand do not contain two pairs
    }
}

// Check hand has 3 same face card
bool hasThreeOfAKind(const std::vector<Card> &hand)
{
    std::map<int, int> frequncies_of_hand = Facefrequency(hand); // Calculate the frequency of card using FaceFrequency method
    for (auto freq : frequncies_of_hand)
    {
        if (freq.second == 3)
        {
            return true; // Return true when there is three of a kind face cards
        }
    }
    return false; // return false when there is not a three of a kind cards
}

// Check hand has four same face cards
bool hasFourOfAKind(const std::vector<Card> &hand)
{
    std::map<int, int> frequncies_of_hand = Facefrequency(hand); // Calculate the frequency of card using FaceFrequency method
    for (auto freq : frequncies_of_hand)
    {
        if (freq.second == 4)
        {
            return true; // Return true when there is four of a kind face cards
        }
    }
    return false; // return false when there is not a four of a kind cards
}

// Check for flush (all card of same suit)
bool isFlush(const std::vector<Card> &hand)
{
    int suit = hand[0].getSuit();
    for (const Card &card : hand)
    {
        if (card.getSuit() != suit)
        {
            return false;
        }
    }
    return true;
}

// Check for staright (with consecutive faces)
// bool isStraight(const std::vector<Card> &hand);

// Function to print the values of card in hand
void printHand(const std::vector<Card> &hand, const std::string &playerName)
{
    std::cout << playerName << "'s hand:\n";
    for (const Card &card : hand)
    {
        std::cout << "  " << card.toString() << "\n";
    }
    std::cout << std::endl;
}