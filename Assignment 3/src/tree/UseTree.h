// Algorithms ~ A. Labouseur, Assignment 3 - Connor Fleischman

#include "BinaryTree.h"
#include <vector>

BinaryTree buildTree(vector<string> lines, BinaryTree tree)
{
   for (const string line : lines)
   {
      tree.insert(line);
   }
   return tree;
}

void inOrderTraversal(BinaryTree tree)
{
   tree.traverse();
}

string keyLookUp(string key, BinaryTree tree)
{
   return tree.search(key);
}