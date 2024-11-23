// Algorithms ~ A.Labouseur, Assignment 4 - Connor Fleischman
#ifndef H_BUILD
#define H_BUILD

#include "./graph/UseGraph.h"
#include "./spice/UseSpice.h"
#include "Parse.h"
#include <sstream>

// Graph build functions:
std::vector<std::vector<std::string>> buildInstructions() // Returns the instructions to build all graphs in a vector of vectors of strings
{
   return parseGraph(); // Call the parse function from "Parse.h"
}

std::string buildGraph(std::vector<std::string> &graphInstructions, Graph &graph) // Given the instructions for one graph and the graph, build that graph
{
   bool foundFirstVertex = false;                     // Flag to track if first vertex is found
   std::string firstVertexID;                         // Variable to hold first vertex ID
   for (std::string &instruction : graphInstructions) // For every instruction in the vector of instructions
   {
      std::istringstream inst(instruction);    // Break the instruction into individual words
      std::string identifier, opcode, operand; // Declare both identifier, opcode, and operand as strings
      inst >> identifier >> opcode;            // Read the first two words to their strings
      std::getline(inst, operand);             // Read the remaining words to the string

      if (opcode == "vertex") // If the opcode is named vertex
      {
         if (!foundFirstVertex) // If the first vertex is not recorded
         {
            std::istringstream vID(operand); // Break the operand into just the string, no white-space
            std::string num;                 // Declare num as a string
            vID >> num;                      // Read the vertex ID from the operand into num
            firstVertexID = num;             // Record the first vertex
            foundFirstVertex = true;         // Set the flag
            insertVertex(num, graph);        // Add a vertex with id: num to the graph
         }
         else
         {
            std::istringstream vID(operand); // Break the operand into just the string, no white-space
            std::string num;                 // Declare num as a string
            vID >> num;                      // Read the vertex ID from the operand into num
            insertVertex(num, graph);        // Add a vertex with id: num to the graph
         }
      }
      else if (opcode == "edge") // If the opcode is edge
      {
         std::istringstream edge(operand);     // Break the operand into individual words
         std::string v1, bridge, v2;           // Declare the vertices being connected and the connection symbol
         int weight;                           // Delcare the weight of the connection
         edge >> v1 >> bridge >> v2 >> weight; // Read the first three words and the weight to these strings and int
         insertEdge(v1, v2, weight, graph);    // Add a edge from v1 - v2 with some weight
      }
   }
   foundFirstVertex = false; // Reset the flag
   return firstVertexID;
}

// Spices & Knapsack build functions:
void buildSpicesKnapsacks(std::vector<std::string> &instructions, Spices &spices, Knapsacks &knapsacks)
{
   for (std::string &instruction : instructions) // For every instruction in the list
   {
      std::istringstream inst(instruction); // Break this instruction into words
      std::string identifier, item;         // Declares the identifier and item as strings
      inst >> identifier;                   // Read the first word to the identifier

      if (identifier == "spice") // If the item is spice
      {
         std::string color;                // Declare color a string
         int totalPrice = 0, quantity = 0; // Declare totalPrice and quantity as integers = 0

         std::getline(inst, color, ';'); // Break the instruction off after ';', put it in color
         std::getline(inst, item, ';');  // Break the instruction off after ';', put it in item
         totalPrice = std::stoi(item);   // Convert the item to an integer, save it as totalPrice
         std::getline(inst, item, ';');  // Break the instruction off after ';', put it in item
         quantity = std::stoi(item);     // Convert the item to an integer, save it as quantity

         spices.addSpice(color, totalPrice, quantity); // Add this spice to the list of spices given its color, totalPrice, and quantity
      }
      else if (identifier == "knapsack") // If the item is knapsack
      {
         int capacity; // Delcare capacity a string

         std::getline(inst, item, ';'); // Break the instruction off after ';', put it in item
         capacity = std::stoi(item);    // Convert the item to an integer, save it as capacity

         knapsacks.addKnapsack(capacity); // Add this knapsack to the list of knapsacks given its capacity
      }
   }
}

#endif