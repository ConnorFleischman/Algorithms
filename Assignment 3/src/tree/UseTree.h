// Algorithms ~ A. Labouseur, Assignment 3 - Connor Fleischman

#include "BinaryTree.h"

void inOrderTraversal(BinaryTree tree)
{
   tree.traverse();
}

string keyLookUp(string key, BinaryTree tree)
{
   return tree.search(key);
}