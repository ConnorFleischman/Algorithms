// Algorithms ~ A.Labouseur, Assignment 4 - Connor Fleischman
#ifndef H_USE_SPICE_KNAPSACK
#define H_USE_SPICE_KNAPSACK

#include "./SpiceKnapsack.h"

// ---------------------- SPICES ---------------------- //
void addSpice(std::string &color, int totalPrice, int quantity, Spices &spices)
{
   spices.addSpice(color, totalPrice, quantity);
}

// ---------------------- KNAPSACKS ---------------------- //
void addKnapsack(int capacity, std::vector<Knapsack *> &knapsacks)
{
   knapsacks.push_back(new Knapsack(capacity));
}

void fillKnapsacks(std::vector<Knapsack *> &knapsacks, Spices &spices)
{
   for (Knapsack *knapsack : knapsacks) // For every knapsack stored
   {
      spices.fillKnapsack(knapsack); // Fill the knapsack using a Greedy Algorithm and return its contents
   }
}

#endif
