// Algorithms ~ A. Labouseur, Assignment 3 - Connor Fleischman
#pragma once // This ensures the contents of the file is exported once, stopping any redefinition errors

#include <iostream>
#include <fstream>
#include <string>

using namespace std; // Globally used namespace (removes use of std::)

class Node // Defines a Node
{
public:
   string data; // Identifies the data section of the parent node
   string path; // Identifies the path from root to this node
   Node *left;  // Identifies the pointer to the left child leaf node
   Node *right; // Identifies the pointer to the right child leaf node

   Node(string value) // When a node is constructed
   {
      this->data = value; // Set this node's data to some value
      this->path = "";    // Set this node's path to an empty string
   }
};

class BinaryTree // Defines a Binary Tree
{
private:
   Node *root; // Pointer to the root node
public:
   BinaryTree() // Binary Tree constructor
   {
      root = nullptr; // Set this tree's root to null
   }

   ~BinaryTree() // Binary Tree destructor
   {
      deleteTree(root); // Delete the tree starting at the root node and recursing through the whole tree
      cout << "Binary Tree deleted" << endl;
   }

   void insert(string value) // Inserts a new node
   {
      if (root == nullptr) // If the root is not set
      {
         root = new Node(value);                                               // Set this value as the root
         root->path = "Root";                                                  // Set it's path as root
         cout << "Inserted node: " + value + " | Path: " + root->path << endl; // Record insertion
      }
      else // If there is a root
      {
         Node *currNode = root;           // Pointer to the current node, set to root first
         Node *newNode = new Node(value); // Create a new node with the given value
         newNode->path += "Root -> ";     // Begin its path
         while (currNode != nullptr)      // Loop created to traverse tree
         {
            if (newNode->data < currNode->data) // If the node to be inserted is less than the current node
            {
               newNode->path += "L -> ";      // Add to its path
               if (currNode->left == nullptr) // If the current node's left child is not set
               {
                  currNode->left = newNode; // Set the current's left child to the new node
                  newNode->path += "Node";  // Finish its path
                  break;                    // Break from the loop
               }
               else // If the current node's left child is set
               {
                  currNode = currNode->left; // Set the current node to the left child
               }
            }
            else // If the new node is >= to the current
            {
               newNode->path += "R -> ";       // Add to its path
               if (currNode->right == nullptr) // If the current node's right child is not set
               {
                  currNode->right = newNode; // Set the current's right child to the new node
                  newNode->path += "Node";   // Finish its path
                  break;                     // Break from the loop
               }
               else // If the current node's right child is set
               {
                  currNode = currNode->right; // Set the current node to the right child
               }
            }
         }
         // Once the value has found its place
         cout << "Inserted node: " + value + " | Path: " + newNode->path << endl; // Record insertion
      }
   }

   string remove(Node *node) // Remove a specific node, return that nodes path
   {
      Node *currNode = root;      // Pointer to the current node, set to root first
      while (currNode != nullptr) // Loop created to traverse tree if tree is not empty
      {
         if (node->data == currNode->data) // If the value is equal to the current node's data
         {
            string path = node->path; // Temp variable for path storage
            delete node;              // Delete the node
            delete currNode;          // Delete the helper node
            return path;              // Return the current node's path and break from the loop
         }
         else if (node->data < currNode->data) // If the value is less than the current's data
         {
            currNode = currNode->left; // Set the current to that nodes left child and loop
         }
         else // If the value is greater than the current's data
         {
            currNode = currNode->right; // Set the current to that nodes right child and loop
         }
      }
   }

   void deleteTree(Node *node) // Delete the tree using recursion to traverse and delete the whole tree
   {
      if (node != nullptr) // If the node is not null
      {
         deleteTree(node->left);  // Recurse on the left child
         deleteTree(node->right); // Recurse on the right child
         remove(node);            // Delete the source node
      }
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

   void traverse() // Performs an in-order traversal on the tree
   {
      cout << "In-order traversal: " << endl;
      recurseTraverse(root); // Begins the recursion on the root
      cout << "-- COMPLETE --" << endl;
   }

   void recurseTraverse(Node *currNode) // print the tree in Left, Root, Right order
   {
      if (currNode != nullptr) // If the current node is not null
      {
         recurseTraverse(currNode->left);  // Recurse with the current node's left child (until null)
         cout << currNode->data << ", ";   // Print the node who's left child is null
         recurseTraverse(currNode->right); // Recurse with that nodes right child (until null)
      }
   }

   string search(string value) // Searches for a value in the binary tree
   {
      Node *currNode = root;      // Pointer to the current node, set to root first
      while (currNode != nullptr) // While the current node exists
      {
         if (value == currNode->data) // If the value to be found is equal to the current node's data
         {
            return currNode->path; // Return that the node was found at it's path
         }
         else if (value < currNode->data) // If the value is less than the current
         {
            currNode = currNode->left; // Set the new current node to the old's left child
         }
         else // If the value is greater than the current
         {
            currNode = currNode->right; // Set the new current node to the old's right child
         }
      }
      return "Node not found"; // If the node is not found, return and log not found
   }
};