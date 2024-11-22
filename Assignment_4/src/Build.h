// Algorithms ~ A.Labouseur, Assignment 4 - Connor Fleischman
#ifndef H_BUILD
#define H_BUILD

#include "./graph/DirectedGraph.h"
#include "Parse.h"
#include <sstream>

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
         graph.insertVertex(num);         // add a vertex with id: num to the graph
      }
      if (opcode == "edge") // If the opcode is edge
      {
         std::istringstream edge(operand);     // Break the operand into individual words
         std::string v1, bridge, v2, weight;   // Declare the vertices being connected and the connection symbol, and weight
         edge >> v1 >> bridge >> v2 >> weight; // Read the first three words and the weight to these strings
         graph.insertEdge(v1, v2, weight);     // add a edge from v1 - v2 with some weight
      }
   }
}

#endif