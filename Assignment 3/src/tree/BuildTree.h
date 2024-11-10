// Algorithms ~ A. Labouseur, Assignment 3 - Connor Fleischman

#include <iostream>
#include <fstream>
#include <string>

using namespace std; // Globally used namespace (removes use of std::)

class Node
{
public:
   string data; // Identifies the data section of the parent node
   string path; // Identifies the path from root to this node
   Node *left;  // Identifies the pointer to the left child leaf node
   Node *right; // Identifies the pointer to the right child leaf node

   Node(string value) // When a node is constructed
   {
      this->data = value;    // Set this node's data to some value
      this->path = nullptr;  // Set this node's path to null
      this->left = nullptr;  // Set this node's left child to null
      this->right = nullptr; // Set this node's right child to null
   }
};

class BinaryTree
{
private:
   Node *root; // Pointer to the root node
   int band;   // Variable to store the band (level) of the tree
public:
   BinaryTree() // When a Binary Tree is constructed
   {
      root = nullptr; // Set this tree's root to null
      band = 0;       // Set the height of the empty tree to 0
   }
   void insert(string value) // Inserts a new node
   {
      if (root == nullptr) // If the root is not set
      {
         root = new Node(value);                                                          // Set this value as the root
         root->path += "Root";                                                            // Set it's path as root
         cout << "Inserted node of value: " + value + ", at path: " + root->path << endl; // Record insertion
      }
      else // If there is a root
      {
         Node *currNode = root; // Pointer to the current node, set to root first
         Node *newNode = new Node(value);
         newNode->path += "Root, ";

         while (true) // Loop created to traverse tree
         {
            if (newNode->data < currNode->data) // If the node to be inserted is less than the current node
            {
               newNode->path += "L, ";        // Add to its path
               if (currNode->left == nullptr) // If the current node's left child is not set
               {
                  currNode->left = newNode; // Set the current's left child to the new node
                  newNode->path += "Node";  // Finish its path
                  break;                    // Break from the loop
               }
               else // If the current node's left child is set
               {
                  currNode = currNode->left; // Set the current node to the left child
                  band++;                    // Note that we are going down a level
               }
            }
            else // If the new node is >= to the current
            {
               newNode->path += "R, ";         // Add to its path
               if (currNode->right == nullptr) // If the current node's right child is not set
               {
                  currNode->right = newNode; // Set the current's right child to the new node
                  newNode->path += "Node";   // Finish its path
                  break;                     // Break from the loop
               }
               else // If the current node's right child is set
               {
                  currNode = currNode->right; // Set the current node to the right child
                  band++;                     // Note that we are going down a level
               }
            }
         }

         // Once the value has found its place
         band++;                                                                             // Note that we had gone down a level
         cout << "Inserted node of value: " + value + ", at path: " + newNode->path << endl; // Record that the value was inserted at some path
      }
   }
   string remove(string value) // Remove a specific node
   {
      // --WIP-- //
      Node *currNode = nullptr;
      return currNode->data;
   }
   bool isEmpty(bool debug) // Returns if the tree is empty, with optional debugging logs
   {
      if (root == nullptr) // If the root is not set
      {
         if (debug) // If debugging is on
         {
            cout << "The tree is empty" << endl; // Log the tree is empty
         }
         return true; // Return true
      }
      else // If the root is set
      {
         if (debug) // If debugging is on
         {
            cout << "The tree is NOT empty" << endl; // Log the tree is populated
         }
         return false; // Return false
      }
   }
};