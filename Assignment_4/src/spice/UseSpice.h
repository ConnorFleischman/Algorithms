// Algorithms ~ A.Labouseur, Assignment 4 - Connor Fleischman
#ifndef H_USESPICE
#define H_USESPICE

#include "./SpiceKnapsack.h"

// ---------------------- SPICES ---------------------- //
void addSpice(std::string &color, int totalPrice, int quantity, Spices &spices)
{
   spices.addSpice(color, totalPrice, quantity);
}
// ---------------------- KNAPSACKS ---------------------- //
void addKnapsack(int capacity, std::vector<Knapsack *> knapsacks)
{
   knapsacks.push_back(new Knapsack(capacity));
}
void fillKnapsack(Knapsack *knapsack, Spices &spices)
{
   spices.fillKnapsack(knapsack);
}

#endif
