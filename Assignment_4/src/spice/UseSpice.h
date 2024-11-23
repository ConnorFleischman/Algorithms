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
void addKnapsack(int capacity, Knapsacks &knapsacks)
{
   knapsacks.addKnapsack(capacity);
}

#endif
