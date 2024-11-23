// Algorithms ~ A.Labouseur, Assignment 4 - Connor Fleischman
#ifndef H_SPICE
#define H_SPICE

#include <vector>
#include <string>

// ---------------------- SPICES ---------------------- //
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
      std::cout << "New Spice Created || Spice color: " << newSpice->color << " | totalPrice: " << newSpice->totalPrice << " | quantity: " << newSpice->quantity << " | unitPrice: " << newSpice->unitPrice << std::endl;
      spices.push_back(newSpice); // Push it to the vector of spices
      std::cout << newSpice->color << " spice added to Spices" << std::endl;
   }
   void displaySpices()
   {
      for (Spice *spice : spices)
      {
         std::cout << "Spice color: " << spice->color << " | totalPrice: " << spice->totalPrice << " | quantity: " << spice->quantity << " | unitPrice: " << spice->unitPrice << std::endl;
      }
   }
};

// ---------------------- KNAPSACKS ---------------------- //
class Knapsack // Defines the Knapsack Class
{
public:
   int capacity; // Identifies the capacity of the knapsack

   Knapsack(int knapsackSize) // Knapsack constructor
   {
      this->capacity = knapsackSize; // Set this knapsack's capacity to some given size
   }
};

class Knapsacks // Defines the Knapsacks class
{
public:
   std::vector<Knapsack *> knapsacks; // Identifies the total knapsacks in scope
   Knapsacks() {}                     // Knapsacks constructor
   ~Knapsacks()                       // Knapsacks destructor
   {
      for (Knapsack *knapsack : knapsacks) // For every knapsack in knapsacks
      {
         delete knapsack; // Delete that knapsack
      }
      knapsacks.clear(); // Clear knapsacks
   }

   void addKnapsack(int capacity) // Add a knapsack of some size to knapsacks
   {
      Knapsack *newKnapsack = new Knapsack(capacity); // Create the new Knapsack object with the parameters
      std::cout << "New Knapsack Created || Knapsack capacity: " << newKnapsack->capacity << std::endl;
      knapsacks.push_back(newKnapsack); // Push it to the vector of Knapsacks
      std::cout << "Knapsack with " << newKnapsack->capacity << " capacity added to Knapsacks" << std::endl;
   }
   void displayKnapsacks()
   {
      for (Knapsack *knapsack : knapsacks)
      {
         std::cout << "Knapsack with capacity: " << knapsack->capacity << std::endl;
      }
   }
};

#endif