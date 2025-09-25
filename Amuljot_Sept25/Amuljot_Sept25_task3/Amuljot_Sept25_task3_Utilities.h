#ifndef UTILITIES_H
#define UTILITIES_H

#include <vector>
#include <string>
#include "Amuljot_Sept25_task3_Card.h"

// Global Function Declaration
bool hasPair(const std::vector<Card> &hand);
bool hasTwoPairs(const std::vector<Card> &hand);
bool hasThreeOfAKind(const std::vector<Card> &hand);
bool hasFourOfAKind(const std::vector<Card> &hand);
bool isFlush(const std::vector<Card> &hand);
bool isStraight(const std::vector<Card> &hand);
void printHand(const std::vector<Card> &hand, const std::string &playeName);

#endif