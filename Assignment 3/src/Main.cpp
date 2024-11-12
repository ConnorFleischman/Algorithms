// Algorithms ~ A. Labouseur, Assignment 3 - Connor Fleischman

#include "./tree/UseTree.h"
#include "./graph/UseGraph.h"
#include "./Build.h"

using namespace std; // Globally used namespace (removes use of std::)

// Globally used variables
BinaryTree tree; // Declare globally used binary tree 'tree'

int main()
{
   tree = buildTree(buildLines(), tree); // Fill tree with the magic items
   cout << "---------------------------------------------------------------------------------" << endl;
   inOrderTraversal(tree);
   cout << "---------------------------------------------------------------------------------" << endl;
   for (const string key : buildKeys())
   {
      cout << "Key: " + key + " | Located: " + keyLookUp(key, tree) << endl;
   }
   cout << "---------------------------------------------------------------------------------" << endl;
   return 0;
}