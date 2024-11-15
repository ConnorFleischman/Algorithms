// Algorithms ~ A. Labouseur, Assignment 3 - Connor Fleischman

#include "./tree/UseTree.h"
#include "./graph/UseGraph.h"
#include "./Build.h"

using namespace std; // Globally used namespace (removes use of std::)

void interactGraph(Graph &graph) // Function to perform graph interactions
{
   int numGraphs = 0; // Counter to track the number of graphs being produced

   for (vector<string> graphInstructions : buildInstructions()) // For every graph in the blueprint returned by buildInstructions()
   {
      numGraphs++; // Increment for every graph built

      cout << "Building graph #" << numGraphs << endl;
      buildGraph(graphInstructions, graph); // Build that graph using the instructions

      displayMatrix(graph);        // Display that graph as a matrix
      displayAdjacencyList(graph); // Display that graph as an adjacency list

      cout << "Running Depth-first traversal..." << endl;
      depthFirstTraversal(graph); // Perform a depth-first traversal of the graph
      cout << "Running Breadth-first traversal..." << endl;
      breadthFirstTraversal(graph); // Perform a breadth-first traversal of the graph

      clearGraph(graph); // Delete graph after use
   }
   numGraphs = 0; // Reset the counter
}

void interactTree(BinaryTree &tree) // Function to perform tree interactions
{
   int avgComparisons = 0;              // Initalized avgComparisons counter as 0
   vector<string> lines = buildLines(); // Declare and fill lines from buildLines
   vector<string> keys = buildKeys();   // Declare and fill keys from buildKeys

   buildTree(lines, tree); // Fill tree with the magic items

   inOrderTraversal(tree); // Perform an in-order traversal of the tree

   for (string &key : keys) // For every key provided
   {
      auto [path, comparisons] = keyLookUp(key, tree); // Look up that key, return its path and the number of comparisons required to find it as a pair
      cout << "Key: " << key << " | Located: " << path << " | Comparisons made: " << comparisons << endl;
      avgComparisons += comparisons; // Increment the avg counter with the number of comparisons made for this key
   }
   cout << "Average comparisons made per key: " << (avgComparisons / keys.size()) << endl;
   cout << "---------------------------------------" << endl;

   clearTree(tree);    // Delete tree after use
   avgComparisons = 0; // Reset the counter
}

int main() // Declares main running sequence for the program
{
   Graph graph;     // Declare undirected graph 'graph'
   BinaryTree tree; // Declare binary tree 'tree'

   interactGraph(graph); // Use graphs
   cout << "---------------------------------------" << endl;
   interactTree(tree); // Use tree

   return 0; // Destructors automatically called
}