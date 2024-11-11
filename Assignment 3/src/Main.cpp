// Algorithms ~ A. Labouseur, Assignment 3 - Connor Fleischman

#include "./tree/UseTree.h"
#include "./tree/BuildLines.h"

using namespace std; // Globally used namespace (removes use of std::)

// Globally used variables
BinaryTree tree; // Declare globally used binary tree 'tree'

int main()
{
   vector<string> lines = buildLines(); // Fill lines with the magic items
   tree = buildTree(lines, tree);       // Fill tree with the magic items
   cout << "---------------------------------------------------------------------------------" << endl;
   inOrderTraversal(tree);
   cout << "---------------------------------------------------------------------------------" << endl;

   return 0;
}