// Algorithms ~ A. Labouseur, Assignment 3 - Connor Fleischman

#include "./tree/BinaryTree.h"
#include "./graph/UndirectedGraph.h"
#include "Parse.h"

vector<string> buildLines()
{
   vector<string> lines = parseItems(); // Fill lines with the magic items
   return lines;                        // Return the vector lines
}

vector<string> buildKeys()
{
   vector<string> keys = parseKeys(); // Fill keys with the magic item keys
   return keys;                       // Return the vector keys
}

BinaryTree buildTree(vector<string> lines, BinaryTree tree)
{
   for (string line : lines) // For every line in lines
   {
      tree.insert(line); // Insert each line into the tree
   }
   return tree; // Return the tree
}

vector<vector<string>> buildInstructions()
{
   vector<vector<string>> instructions = parseGraph(); // Fill the lines with the parsed graph blueprint
   return instructions;                                // Return the vector of lines
}

Graph buildGraph(vector<vector<string>> instructions, Graph graph)
{
   for (vector<string> graph : instructions)
   {
   }
}