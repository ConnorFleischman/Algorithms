// Algorithms ~ A. Labouseur, Assignment 3 - Connor Fleischman

#include "./tree/BuildTree.h"
#include "./tree/BuildLines.h"

using namespace std; // Globally used namespace (removes use of std::)

// Globally used variables
BinaryTree tree; // Declare globally used binary tree 'tree'

int main()
{
   vector<string> lines = buildLines(); // Fill lines with the sorted magic items
   buildTree(lines, tree);              // Fill tree with the sorted magic items
   return 0;
}