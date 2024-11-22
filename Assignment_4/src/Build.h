// Algorithms ~ A.Labouseur, Assignment 4 - Connor Fleischman
#ifndef H_BUILD
#define H_BUILD

#include "./graph/UseGraph.h"
#include "Parse.h"
#include <sstream>

// Graph build functions:
std::vector<std::vector<std::string>> buildInstructions() // Returns the instructions to build all graphs in a vector of vectors of strings
{
   return parseGraph(); // Call the parse function from "Parse.h"
}

void buildGraph(std::vector<std::string> &graphInstructions, Graph &graph) // Given the instructions for one graph and the graph, build that graph
{
   for (std::string &instruction : graphInstructions) // For every instruction in the vector of instructions
   {
      std::istringstream inst(instruction);    // Break the instruction into individual words
      std::string identifier, opcode, operand; // Declare both identifier, opcode, and operand as strings
      inst >> identifier >> opcode;            // Read the first two words to their strings
      getline(inst, operand);                  // Read the remaining words to the string

      if (opcode == "vertex") // If the opcode is named vertex
      {
         std::istringstream vID(operand); // Break the operand into just the string, no white-space
         std::string num;                 // Declare num as a string
         vID >> num;                      // Read the vertex ID from the operand into num
         insertVertex(num, graph);        // Add a vertex with id: num to the graph
      }
      if (opcode == "edge") // If the opcode is edge
      {
         std::istringstream edge(operand);     // Break the operand into individual words
         std::string v1, bridge, v2;           // Declare the vertices being connected and the connection symbol
         int weight;                           // Delcare the weight of the connection
         edge >> v1 >> bridge >> v2 >> weight; // Read the first three words and the weight to these strings and int
         insertEdge(v1, v2, weight, graph);    // Add a edge from v1 - v2 with some weight
      }
   }
}

#endif