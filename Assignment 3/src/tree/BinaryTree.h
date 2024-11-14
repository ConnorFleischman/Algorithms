// Algorithms ~ A. Labouseur, Assignment 3 - Connor Fleischman
#ifndef H_BINARYTREE
#define H_BINARYTREE

#include <iostream>
#include <fstream>
#include <string>

using namespace std; // Globally used namespace (removes use of std::)

class Node // Defines a Node
{
public:
   string id;   // Identifies the id section of the parent node
   string path; // Identifies the path from root to this node
   Node *left;  // Identifies the pointer to the left child leaf node
   Node *right; // Identifies the pointer to the right child leaf node

   Node(string &nodeID) // When a node is constructed
   {
      this->id = nodeID; // Set this node's id to some nodeID
      this->path = "";   // Set this node's path to an empty string
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

   void insert(string &nodeID) // Inserts a new node
   {
      if (root != nullptr) // If the root is set
      {
         Node *currNode = root;            // Pointer to the current node, set to root first
         Node *newNode = new Node(nodeID); // Create a new node with the given nodeID
         newNode->path += "Root -> ";      // Begin its path
         while (currNode != nullptr)       // Loop created to traverse tree
         {
            if (newNode->id < currNode->id) // If the node to be inserted is less than the current node
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
         // Once the node has found its place
         cout << "Inserted node: " << nodeID << " | Path: " << newNode->path << endl; // Record insertion
      }
      else // If there is no root
      {
         root = new Node(nodeID);                                                    // Set this nodeID as the root
         root->path = "Root";                                                        // Set it's path as root
         cout << "Inserted node: " << root->id << " | Path: " << root->path << endl; // Record insertion
      }
   }

   void deleteTree(Node *node) // Delete the tree using recursion to traverse and delete the whole tree
   {
      if (node != nullptr) // If the node is not null
      {
         deleteTree(node->left);  // Recurse on the left child
         deleteTree(node->right); // Recurse on the right child
         delete node;
      }
      else
      {
         cout << "Binary Tree empty" << endl;
      }
   }

   Node *getRoot() // Returns the pointer to the root node to be used elsewhere
   {
      return root;
   }

   bool isEmpty() // Returns if the tree is empty
   {
      if (root == nullptr) // If the root is not set
      {
         return true; // Return true
      }
      else // If the root is set
      {
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
         cout << currNode->id << ", ";     // Print the node who's left child is null
         recurseTraverse(currNode->right); // Recurse with that nodes right child (until null)
      }
   }

   pair<string, int> search(string &nodeID) // Searches for a nodeID in the binary tree
   {
      int numComparisons = 0;     // Defines and declares numComparisons as 0
      Node *currNode = root;      // Pointer to the current node, set to root first
      while (currNode != nullptr) // While the current node exists
      {
         if (nodeID == currNode->id) // If the nodeID to be found is equal to the current node's id
         {
            numComparisons++;                                 // Increment numComparisons for comparison
            return make_pair(currNode->path, numComparisons); // Return that the node was found at it's path
         }
         else if (nodeID < currNode->id) // If the nodeID is less than the current
         {
            numComparisons++;          // Increment numComparisons for comparison
            currNode = currNode->left; // Set the new current node to the old's left child
         }
         else // If the nodeID is greater than the current
         {
            numComparisons++;           // Increment numComparisons for comparison
            currNode = currNode->right; // Set the new current node to the old's right child
         }
      }
      return make_pair("Node not found", numComparisons); // If the node is not found, return and log not found
   }
};

#endif