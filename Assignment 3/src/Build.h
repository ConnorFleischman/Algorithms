// Algorithms ~ A. Labouseur, Assignment 3 - Connor Fleischman
#ifndef H_BUILD
#define H_BUILD

#include "./tree/BinaryTree.h"
#include "./graph/UndirectedGraph.h"
#include "Parse.h"
#include <sstream>

using namespace std; // Globally used namespace (removes use of std::)

// Graph build functions:
vector<vector<string>> buildInstructions() // Returns the instructions to build all graphs in a vector of vectors of strings
{
   return parseGraph(); // Call the parse function from "Parse.h"
}

string buildGraph(vector<string> &graphInstructions, Graph &graph) // Given the instructions for one graph, build that graph and return its first vertex's id
{
   bool returnFlag = false;                      // Flag to record if first vertex has been recorded
   string firstVertexID;                         // Variable to hold the first vertex's ID
   for (string &instruction : graphInstructions) // For every instruction in the vector of instructions
   {
      istringstream inst(instruction);    // Break the instruction into individual words
      string identifier, opcode, operand; // Declare both identifier and opcode as strings and operand as a string
      inst >> identifier >> opcode;       // Read the first two words to these strings
      getline(inst, operand);             // Read the remaining words to the string

      if (opcode == "vertex") // If the opcode is vertex
      {
         if (!returnFlag)
         {
            istringstream vID(operand);
            string num;
            vID >> num;
            firstVertexID = num;     // Set the placeholder
            graph.insertVertex(num); // add a vertex with id: operand to the graph
            returnFlag = true;       // Set the flag
         }
         graph.insertVertex(operand); // add a vertex with id: operand to the graph
      }
      if (opcode == "edge") // If the opcode is edge
      {
         istringstream edge(operand); // Break the operand into individual words
         string v1, bridge, v2;       // Declare the vertices being connected and the connection symbol
         edge >> v1 >> bridge >> v2;  // Read the first three words to these strings
         graph.insertEdge(v1, v2);    // add a edge from v1 - v2
      }
   }
   return firstVertexID;
}

// Tree build functions:
vector<string> buildLines() // Returns the magic items in a vector of strings
{
   return parseItems(); // Call the parse function from "Parse.h"
}

vector<string> buildKeys() // Returns the keys in a vector of strings
{
   return parseKeys(); // Call the parse function from "Parse.h"
}

void buildTree(vector<string> &items, BinaryTree &tree) // Builds a tree made of magic items
{
   for (string &item : items) // For every item in items
   {
      tree.insert(item); // Insert each item into the tree
   }
}

#endif