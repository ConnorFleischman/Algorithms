// Algorithms ~ A. Labouseur, Assignment 3 - Connor Fleischman

#include "./tree/UseTree.h"
#include "./graph/UseGraph.h"
#include "./Build.h"

using namespace std; // Globally used namespace (removes use of std::)

void interactGraph(Graph *graph)
{
   for (vector<string> graphInstructions : buildInstructions()) // For every graph in the blueprint
   {
      graph = buildGraph(graphInstructions, graph); // Build that graph using the instructions
      displayMatrix(graph);                         // Display that graph as a matrix
      displayAdjacencyList(graph);                  // Display that graph as an adjacency list
      // depthFirstTraversal(graph);                   // Perform a depth-first traversal of the graph
      // breadthFirstTraversal(graph);                 // Perform a breadth-first traversal of the graph
   }
}

void interactTree(BinaryTree *tree)
{
   vector<string> lines = buildLines();
   tree = buildTree(lines, tree); // Fill tree with the magic items
   inOrderTraversal(tree);
   for (const string key : buildKeys())
   {
      cout << "Key: " + key + " | Located: " + keyLookUp(key, tree) << endl;
   }
}

int main() // Declares main running sequence for the program
{
   Graph *graph;     // Declare globally used undirected graph 'graph'
   BinaryTree *tree; // Declare globally used binary tree 'tree'

   // interactGraph(graph);
   interactTree(tree);
   return 0; // Destructors automatically called
}