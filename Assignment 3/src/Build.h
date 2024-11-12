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
   for (string line : lines)
   {
      tree.insert(line);
   }
   return tree;
}

vector<string> buildInstructions()
{
   vector<string> lines = parseGraph(); // Fill the lines with the parsed graph blueprint
   return lines;                        // Return the vector of lines
}

Graph buildGraph(vector<string> lines, Graph graph)
{
   for (string line : lines)
   {
      if (line.front() == 'n' && FLAG)
      {
         // set flag to true
      }
   }
}