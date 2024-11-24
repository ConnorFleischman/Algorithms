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

void buildSpices(std::vector<std::string> &instructions, Spices &spices)
{
   for (std::string &instruction : instructions) // For every instruction in the list
   {
      std::istringstream inst(instruction); // Break that instruction into words
      std::string identifier, excess;       // Declare identifier and excess as strings
      inst >> identifier;                   // Take the identifier off the instruction
      std::getline(inst, excess);           // Read the remaining words to excess

      if (identifier == "spice") // If the identifier is spice
      {
         std::vector<std::string> commands = parseLine(excess);                         // Break the excess into its commands
         addSpice(commands[0], std::stoi(commands[1]), std::stoi(commands[2]), spices); // Build the spice using each command, parsed to an int if necessary
      }
   }
   std::cout << "Spices built" << std::endl;
}

void buildKnapsacks(std::vector<std::string> &instructions, std::vector<Knapsack *> knapsacks)
{
   for (std::string &instruction : instructions) // For every instruction in the list
   {
      std::istringstream inst(instruction); // Break that instruction into words
      std::string identifier, excess;       // Declare identifier and excess as strings
      inst >> identifier;                   // Take the identifier off the instruction
      std::getline(inst, excess);           // Read the remaining words to excess

      if (identifier == "knapsack") // If the identifier is knapsack
      {
         std::vector<std::string> commands = parseLine(excess); // Break the excess into its commands
         addKnapsack(std::stoi(commands[0]), knapsacks);        // Build the knapsack using the command parsed to an int
      }
   }
   std::cout << "Knapsacks built" << std::endl;
}

#endif