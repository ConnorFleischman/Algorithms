// Algorithms ~ A.Labouseur, Assignment 4 - Connor Fleischman
#ifndef H_SPICE
#define H_SPICE

#include <vector>
#include <string>

class Spice // Defines the Spice class
{
public:
   std::string color; // Identifies the color of the spice
   int totalPrice;    // Identifies the total price of the spice
   int quantity;      // Identifies the quantity of the spice
   int unitPrice;     // Identifies the unit price of the spice

   Spice(std::string spiceColor, int totalCost, int totalQuantity) // Spice constructor
   {
      this->color = spiceColor;                    // Set this spice's color to some given color
      this->totalPrice = totalCost;                // Set this spice's total price to some given cost
      this->quantity = totalQuantity;              // Set this spice's quantity to some given amount
      this->unitPrice = totalCost / totalQuantity; // Set this spice's unit price to the average cost per amount of spice
   }
};

#endif