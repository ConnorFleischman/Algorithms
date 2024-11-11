// Algorithms ~ A. Labouseur, Assignment 3 - Connor Fleischman

#include "BinaryTree.h"
#include <vector>

void buildTree(vector<string> lines, BinaryTree tree)
{
   for (const string line : lines)
   {
      tree.insert(line);
   }
   tree.isEmpty(true);
}