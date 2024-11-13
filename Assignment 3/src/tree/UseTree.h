// Algorithms ~ A. Labouseur, Assignment 3 - Connor Fleischman
#pragma once // This ensures the contents of the file is exported once, stopping any redefinition errors

#include "BinaryTree.h"

void inOrderTraversal(BinaryTree *tree) // Perform an in-order traversal over the tree
{
   tree->traverse(); // Call the traverse function from "BinaryTree.h"
}

string keyLookUp(string key, BinaryTree *tree) // Look-up a specific keep in the tree
{
   return tree->search(key); // Return the result from the search of some key in the tree from "BinaryTree.h"
}