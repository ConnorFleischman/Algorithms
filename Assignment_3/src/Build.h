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

void buildGraph(vector<string> &graphInstructions, Graph &graph) // Given the instructions for one graph and the graph, build that graph
{
   for (string &instruction : graphInstructions) // For every instruction in the vector of instructions
   {
      istringstream inst(instruction);    // Break the instruction into individual words
      string identifier, opcode, operand; // Declare both identifier, opcode, and operand as strings
      inst >> identifier >> opcode;       // Read the first two words to their strings
      getline(inst, operand);             // Read the remaining words to the string

      if (opcode == "vertex") // If the opcode is named vertex
      {
         istringstream vID(operand); // Break the operand into just the string, no white-space
         string num;                 // Declare num as a string
         vID >> num;                 // Read the vertex ID from the operand into num
         graph.insertVertex(num);    // add a vertex with id: num to the graph
      }
      if (opcode == "edge") // If the opcode is edge
      {
         istringstream edge(operand); // Break the operand into individual words
         string v1, bridge, v2;       // Declare the vertices being connected and the connection symbol
         edge >> v1 >> bridge >> v2;  // Read the first three words to these strings
         graph.insertEdge(v1, v2);    // add a edge from v1 - v2
      }
   }
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

void buildTree(vector<string> items, BinaryTree &tree) // Builds a tree made of magic items
{
   for (string &item : items) // For every item in items
   {
      tree.insert(item); // Insert each item into the tree
   }
   cout << "---------------------------------------" << endl;
}

#endif