// Algorithms ~ A. Labouseur, Assignment 3 - Connor Fleischman

#include "./tree/BinaryTree.h"
#include "./graph/UndirectedGraph.h"
#include "Parse.h"
#include <sstream>

vector<string> buildLines() // Returns the magic items in a vector of strings
{
   vector<string> lines = parseItems(); // Fill lines with the magic items
   return lines;                        // Return the vector lines
}

vector<string> buildKeys() // Returns the keys in a vector of strings
{
   vector<string> keys = parseKeys(); // Fill keys with the magic item keys
   return keys;                       // Return the vector keys
}

BinaryTree buildTree(vector<string> lines, BinaryTree tree) // Builds and returns a tree made of lines into the tree
{
   for (string line : lines) // For every line in lines
   {
      tree.insert(line); // Insert each line into the tree
   }
   return tree; // Return the tree
}

vector<vector<string>> buildInstructions() // Returns the instructions to build all graphs in a vector of vectors of strings
{
   vector<vector<string>> instructions = parseGraph(); // Fill the lines with the parsed graph blueprint
   return instructions;                                // Return the vector of lines
}

Graph buildGraph(vector<string> graphInstructions, Graph graph) // Given the instructions for one graph, build and return that graph
{
   for (string instruction : graphInstructions) // For every instruction in the vector of instructions
   {
      std::istringstream inst(instruction);              // Break the string into individual words
      std::string firstWord, secondWord, remainingWords; // Declare both firstWord and secondWord as strings and remainingWords as a string
      inst >> firstWord >> secondWord;                   // Read the first two words to these strings
      getline(inst, remainingWords);                     // Read the remaining words to the string

      if (secondWord == "vertex") // If the second word in the instruction is vertex
      {
         // add a vertex with id to the graph at remainingWords
      }
      else if (secondWord == "edge") // If the second word in the instruction is edge
      {
         // add a edge from v1 - v2, in remainingWords
      }
      else // If the second word in the instruction does not exist
      {
         // edge case
      }
   }
}