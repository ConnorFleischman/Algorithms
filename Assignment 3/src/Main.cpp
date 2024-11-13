// Algorithms ~ A. Labouseur, Assignment 3 - Connor Fleischman

#include "./tree/UseTree.h"
#include "./graph/UseGraph.h"
#include "./Build.h"

using namespace std; // Globally used namespace (removes use of std::)

void interactGraph(Graph &graph)
{
   for (vector<string> graphInstructions : buildInstructions()) // For every graph in the blueprint
   {
      buildGraph(graphInstructions, graph); // Build that graph using the instructions
      displayMatrix(graph);                 // Display that graph as a matrix
      displayAdjacencyList(graph);          // Display that graph as an adjacency list
      cout << "Running Depth-first traversal..." << endl;
      depthFirstTraversal(graph, "1"); // Perform a depth-first traversal of the graph
      cout << "Running Breadth-first traversal..." << endl;
      breadthFirstTraversal(graph, "1"); // Perform a breadth-first traversal of the graph
      clearGraph(graph);                 // Delete graph after use
   }
}

void interactTree(BinaryTree &tree)
{
   vector<string> lines = buildLines();
   buildTree(lines, tree);         // Fill tree with the magic items
   inOrderTraversal(tree);         // Perform an in-order traversal of the tree
   for (string &key : buildKeys()) // For every key provided
   {
      cout << "Key: " + key + " | Located: " + keyLookUp(key, tree) << endl; // Report the look-up of that key
   }
   clearTree(tree); // Delete tree after use
}

int main() // Declares main running sequence for the program
{
   Graph graph;     // Declare undirected graph 'graph'
   BinaryTree tree; // Declare binary tree 'tree'

   interactGraph(graph); // Use graphs
   interactTree(tree);   // Use tree

   return 0; // Destructors automatically called
}