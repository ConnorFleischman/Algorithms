// Algorithms ~ A.Labouseur, Assignment 4 - Connor Fleischman
#ifndef H_SPICE
#define H_SPICE

#include <vector>
#include <string>
#include <iostream>

class Spice // Defines the Spice class
{
public:
   std::string color; // Identifies the color of the spice
   int totalPrice;    // Identifies the total price of the spice
   int quantity;      // Identifies the quantity of the spice
   int unitPrice;     // Identifies the unit price of the spice

   Spice(std::string &spiceColor, int totalCost, int totalQuantity) // Spice constructor
   {
      this->color = spiceColor;                    // Set this spice's color to some given color
      this->totalPrice = totalCost;                // Set this spice's total price to some given cost
      this->quantity = totalQuantity;              // Set this spice's quantity to some given amount
      this->unitPrice = totalCost / totalQuantity; // Set this spice's unit price to the average cost per amount of spice
      std::cout << "[Constructed] Spice color: " << std::setw(7) << this->color << " | totalPrice: " << std::setw(3) << this->totalPrice << " | quantity: " << std::setw(3) << this->quantity << " | unitPrice: " << std::setw(3) << this->unitPrice << std::endl;
   }
};

class Spices // Defines the Spices class
{
public:
   std::vector<Spice *> spices; // Identifies the total spices in scope
   Spices() {}                  // Spices constructor
   ~Spices()                    // Spices destructor
   {
      for (Spice *spice : spices) // For every spice in spices
      {
         delete spice; // Delete that spices
      }
      spices.clear(); // Clear spices
   }

   void addSpice(std::string &color, int totalPrice, int quantity) // Add a spice with some parameters to spices
   {
      Spice *newSpice = new Spice(color, totalPrice, quantity); // Create the new Spice object with the parameters
      spices.push_back(newSpice);                               // Push it to the vector of spices
   }
   void fillKnapsack(Knapsack *knapsack) // Use a greedy algorithm to fill this knapsack
   {
      // TODO:
   }
};

class Knapsack // Defines the Knapsack Class
{
public:
   int capacity; // Identifies the capacity of the knapsack

   Knapsack(int knapsackSize) // Knapsack constructor
   {
      this->capacity = knapsackSize; // Set this knapsack's capacity to some given size
      std::cout << "[Constructed] Knapsack with capacity: " << std::setw(3) << this->capacity << std::endl;
   }
};

#endif