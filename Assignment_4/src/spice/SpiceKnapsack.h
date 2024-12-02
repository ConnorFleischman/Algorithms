// Algorithms ~ A.Labouseur, Assignment 4 - Connor Fleischman
#ifndef H_SPICE_KNAPSACK
#define H_SPICE_KNAPSACK

#include <vector>
#include <string>
#include <iostream>
#include <iomanip>

class Spice // Defines the Spice class
{
public:
   std::string color; // Identifies the color of the spice
   int totalPrice;    // Identifies the total price of the spice
   int quantity;      // Identifies the quantity of the spice
   double unitPrice;  // Identifies the unit price of the spice

   Spice(std::string &spiceColor, int totalCost, int totalQuantity) // Spice constructor
   {
      this->color = spiceColor;                                         // Set this spice's color to some given color
      this->totalPrice = totalCost;                                     // Set this spice's total price to some given cost
      this->quantity = totalQuantity;                                   // Set this spice's quantity to some given amount
      this->unitPrice = static_cast<double>(totalCost) / totalQuantity; // Set this spice's unit price to the average cost per amount of spice
      std::cout << "[Constructed] Spice color: " << std::setw(7) << this->color << " | totalPrice: " << std::setw(3) << this->totalPrice << " | quantity: " << std::setw(3) << this->quantity << " | unitPrice: " << std::setw(3) << this->unitPrice << std::endl;
   }
};

std::vector<Spice *> selectionSort(std::vector<Spice *> &lines) // Sorts a list of Spices by unit prices and returns it
{
   int n = lines.size();           // n = the length of the lines vector
   for (int i = 0; i < n - 1; i++) // For every item in the vector
   {
      int toCompare = i;              // Sets the item to be compared to to i
      for (int j = i + 1; j < n; j++) // For every item j in lines after i
      {
         if (lines[j]->unitPrice > lines[toCompare]->unitPrice) // If the next item[j]'s unit price in lines is greater than the item[i]'s unit price being compared
         {
            toCompare = j; // Set the new item to be compared to to j
         }
      }
      std::swap(lines[i], lines[toCompare]); // Swap the positions of the previously compared item and the current item
   }
   return lines;
}

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
      std::cout << "Spices destroyed" << std::endl;
   }

   void addSpice(std::string &color, int totalPrice, int quantity) // Add a spice with some parameters to spices
   {
      Spice *newSpice = new Spice(color, totalPrice, quantity); // Create the new Spice object with the parameters
      spices.push_back(newSpice);                               // Push it to the vector of spices
   }

   void fillKnapsack(Knapsack *knapsack) // Use a greedy algorithm to fill this knapsack
   {
      spices = selectionSort(spices);      // Sort the spices's by their unit prices
      double sum = 0.0;                    // Placeholder for total value of current knapsack
      int emptySpace = knapsack->capacity; // Placeholder to calculate the remaining space in the knapsack
      std::cout << "Filling knapsack with capacity: " << knapsack->capacity << std::endl;

      for (Spice *spice : spices) // For each spice
      {
         if (emptySpace == 0) // If there is no space left in the knapsack
         {
            break;
         }
         if (spice->quantity <= emptySpace) // If the this spice can fit in the knapsack
         {
            sum += spice->totalPrice;      // Add the price per quantity to the sum
            emptySpace -= spice->quantity; // Update the remaining space in the knapsack
            std::cout << "Took all of the " << spice->color << " spice." << std::endl;
         }
         else // If the spice cannot fit in the knapsack
         {
            double proportion = static_cast<double>(emptySpace) / spice->quantity; // Calculate the percentage of the spice to be took
            sum += spice->totalPrice * proportion;                                 // Add the price per quantity, based on this fractional quantity
            std::cout << "Took " << proportion * 100 << "% of the " << spice->color << " spice." << std::endl;
            emptySpace = 0; // Since were taking a fractional size, we will always be full after
         }
      }
      // Formatting output to only display if the knapsack is not full, how much space remains
      emptySpace == 0 ? std::cout << "Knapsack filled to capacity." << std::endl : std::cout << "Knapsack cannot be filled anymore, remaining space: " << emptySpace << std::endl;
      std::cout << "Knapsack total value: " << sum << std::endl;
      std::cout << "--------------------------------------------------" << std::endl;
   }
};

#endif