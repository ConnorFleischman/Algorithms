// Algorithms ~ A. Labouseur, Assignment 3 - Connor Fleischman
#ifndef H_BINARYTREE
#define H_BINARYTREE

#include <iostream>
#include <fstream>
#include <string>
#include <queue>

using namespace std; // Globally used namespace (removes use of std::)

class Node // Node definition
{
public:
   string id;   // Identifies the id section of the parent node
   string path; // Identifies the path from root to this node
   Node *left;  // Identifies the pointer to the left child leaf node
   Node *right; // Identifies the pointer to the right child leaf node

   Node(string &nodeID) // Node constructor
   {
      this->id = nodeID;     // Set this node's id to some nodeID
      this->path = "";       // Set this node's path to an empty string
      this->left = nullptr;  // Set this node's left child to null
      this->right = nullptr; // Set this node's left child to null
   }
};

class BinaryTree // Binary Tree definition
{
private:
   Node *root = nullptr; // Pointer to the root node initalized to null
public:
   BinaryTree() {} // Binary Tree constructor

   ~BinaryTree() // Graph destructor
   {
      deleteTree(); // Delete the tree starting
      cout << "Binary Tree deleted" << endl;
   }

   void insert(string &nodeID) // Insert a new node of with ID
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
                  // Loop
               }
            }
            else // If the new node is greater than or equal to the current node
            {
               newNode->path += "R -> ";       // Add to its path
               if (currNode->right == nullptr) // If the current node's right child is not set
               {
                  currNode->right = newNode; // Set the current's right child as the new node
                  newNode->path += "Node";   // Finish its path
                  break;                     // Break from the loop
               }
               else // If the current node's right child is set
               {
                  currNode = currNode->right; // Set the current node to the right child
                  // Loop
               }
            }
         }
         // Once the node has found its place
         cout << "Inserted node: " << nodeID << " | Path: " << newNode->path << endl; // Record insertion
      }
      else // If there is no root node
      {
         root = new Node(nodeID); // Set this nodeID as the root
         root->path = "Root";     // Set it's path as root
         cout << "Inserted node: " << root->id << " | Path: " << root->path << endl;
      }
   }

   void deleteTree() // Delete the tree using a queue keep track of progression (Breadth First traversal)
   {
      if (root != nullptr) // If the node is not null
      {
         queue<Node *> queue; // Declare queue to maintain sequence order
         queue.push(root);    // Push the root to the queue

         while (!queue.empty()) // While the queue is populated
         {
            Node *currNode = queue.front(); // Declare currNode as the first node in the queue
            queue.pop();                    // Pop the first node off the front of the queue

            if (currNode->left != nullptr) // If a left child exists
            {
               queue.push(currNode->left); // Enqueue that child
            }
            if (currNode->right != nullptr) // If a right child exists
            {
               queue.push(currNode->right); // Enqueue that child
            }

            delete currNode; // Delete the current node
         }
         // After the traversal is complete and the tree is empty
         root = nullptr; // Set the root to null
      }
      else if (isEmpty()) // If the tree is already empty
      {
         cout << "Binary Tree empty" << endl;
      }
      else // If the tree could not be found, or the tree could not be emptied
      {
         cout << "Binary Tree could not be emptied" << endl;
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

   pair<string, int> search(string &nodeID) // Searches for a nodeID in the binary tree returns the node's path and the number of comparisons required to find it
   {
      int numComparisons = 0;     // Defines and declares numComparisons as 0
      Node *currNode = root;      // Pointer to the current node, set to root first
      while (currNode != nullptr) // While the current node exists
      {
         if (nodeID == currNode->id) // If the nodeID to be found is equal to the current node's id
         {
            numComparisons++;                                 // Increment for comparison
            return make_pair(currNode->path, numComparisons); // Return that the node was found at it's path and the number of comparisons made
         }
         else if (nodeID < currNode->id) // If the nodeID is less than the current
         {
            numComparisons++;          // Increment for comparison
            currNode = currNode->left; // Set the new current node to the old's left child
         }
         else // If the nodeID is greater than the current
         {
            numComparisons++;           // Increment for comparison
            currNode = currNode->right; // Set the new current node to the old's right child
         }
      }
      // If the node is not found after traversing the tree
      return make_pair("Node not found", numComparisons); // return not found and the number of comparisons (0)
   }
};

#endif