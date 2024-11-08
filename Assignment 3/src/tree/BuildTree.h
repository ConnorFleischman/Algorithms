// Algorithms ~ A. Labouseur, Assignment 3 - Connor Fleischman

#include "ParseInput.h"

using namespace std; // Globally used namespace (removes use of std::)

class Node
{
public:
   std::string data; // Identifies the data section of the parent node
   Node *left;       // Identifies the pointer to the left child leaf node
   Node *right;      // Identifies the pointer to the right child leaf node

   Node(string value) // When a node is constructed
   {
      this->data = value;    // Set this node's data to some value
      this->left = nullptr;  // Set this node's left child to null
      this->right = nullptr; // Set this node's right child to null
   }
};

class BinaryTree
{
private:
   Node *root; // Pointer to the root node

public:
   void insert() // Inserts a new node
   {
   }
};