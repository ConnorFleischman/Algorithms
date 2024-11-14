// Algorithms ~ A. Labouseur, Assignment 3 - Connor Fleischman
#ifndef H_USETREE
#define H_USETREE

#include "BinaryTree.h"

// Tree mutation:
void insertNode(string &nodeID, BinaryTree &tree) // Insert a node by it's ID into the tree
{
   tree.insert(nodeID); // Call the insert function from "BinaryTree.h"
}

void clearTree(BinaryTree &tree) // Empty the tree
{
   tree.deleteTree(); // Call the recursive deletion function starting from the root from "BinaryTree.h"
}

// Tree display:
void inOrderTraversal(BinaryTree &tree) // Perform an in-order traversal over the tree
{
   tree.traverse(); // Call the traverse function from "BinaryTree.h"
   cout << "---------------------------------------" << endl;
}

pair<string, int> keyLookUp(string &key, BinaryTree &tree) // Look-up a specific keep in the tree
{
   return tree.search(key); // Return the result from the search of some key in the tree from "BinaryTree.h"
}

#endif
