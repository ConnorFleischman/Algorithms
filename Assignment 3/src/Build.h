// Algorithms ~ A. Labouseur, Assignment 3 - Connor Fleischman
#pragma once // This ensures the contents of the file is exported once, stopping any redefinition errors

#include "./tree/BinaryTree.h"
#include "./graph/UndirectedGraph.h"
#include "Parse.h"
#include <sstream>

vector<string> buildLines() // Returns the magic items in a vector of strings
{
   return parseItems(); // Call the parse function from "Parse.h"
}

vector<string> buildKeys() // Returns the keys in a vector of strings
{
   return parseKeys(); // Call the parse function from "Parse.h"
}

vector<vector<string>> buildInstructions() // Returns the instructions to build all graphs in a vector of vectors of strings
{
   return parseGraph(); // Call the parse function from "Parse.h"
}

void buildTree(vector<string> &lines, BinaryTree &tree) // Builds and returns a tree made of lines into the tree
{
   for (string line : lines) // For every line in lines
   {
      tree.insert(line); // Insert each line into the tree
   }
}

void buildGraph(vector<string> &graphInstructions, Graph &graph) // Given the instructions for one graph, build and return that graph
{
   for (string &instruction : graphInstructions) // For every instruction in the vector of instructions
   {
      istringstream inst(instruction);    // Break the instruction into individual words
      string identifier, opcode, operand; // Declare both identifier and opcode as strings and operand as a string
      inst >> identifier >> opcode;       // Read the first two words to these strings
      getline(inst, operand);             // Read the remaining words to the string

      if (opcode == "vertex") // If the opcode is vertex
      {
         graph.insertVertex(operand); // add a vertex with id: operand to the graph
      }
      else if (opcode == "edge") // If the opcode is edge
      {
         istringstream edge(operand); // Break the operand into individual words
         string v1, bridge, v2;       // Declare the vertices being connected and the connection symbol
         edge >> v1 >> bridge >> v2;  // Read the first three words to these strings
         graph.insertEdge(v1, v2);    // add a edge from v1 - v2
      }
   }
}