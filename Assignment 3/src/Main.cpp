// Algorithms ~ A. Labouseur, Assignment 3 - Connor Fleischman

#include "./tree/UseTree.h"
#include "./graph/UseGraph.h"
#include "./Build.h"

using namespace std; // Globally used namespace (removes use of std::)

// Globally used variables
BinaryTree tree; // Declare globally used binary tree 'tree'
Graph graph;     // Declare globally used undirected graph 'graph'

int main()
{
   for (vector<string> graphInstructions : buildInstructions())
   {
      graph = buildGraph(graphInstructions, graph);
      displayMatrix(graph);
      displayAdjacencyList(graph);
      // perform depth-first and breadth-first traversals printing all vertex IDs in the order traveled
   }
   cout << "---------------------------------------------------------------------------------" << endl;
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