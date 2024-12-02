// Algorithms ~ A.Labouseur, Assignment 4 - Connor Fleischman

#include "./graph/UseGraph.h"
#include "./spice/UseSpiceKnapsack.h"
#include "./Build.h"

using namespace std; // Globally used namespace, removing use of std::

void interactGraph(Graph &graph)
{
   int numGraphs = 0;                                           // Counter to track the number of graphs being produced
   for (vector<string> graphInstructions : buildInstructions()) // For every graph in the blueprint returned by buildInstructions()
   {
      numGraphs++; // Increment for every graph built
      cout << "Building graph #" << numGraphs << endl;
      string v1 = buildGraph(graphInstructions, graph); // Build this graph getting its first vertex
      cout << "Performing a Single Source, Shortest Path algorithm begining at vertex #" << v1 << endl;
      mapPathways(v1, graph); // Map the pathways from v1 to all other vertices
      cout << "All pathways from vertex #" << v1 << " to other vertices traversed" << endl;
      cout << "Destroying graph #" << numGraphs << endl;
      clearGraph(graph); // Destroy the graph
      cout << "--------------------------------------------------" << endl;
   }
   numGraphs = 0;
}

void interactSpices(Spices &spices, std::vector<Knapsack *> &knapsacks)
{
   std::vector<std::string> instructions = parseInstructions();
   cout << "Building Spices and Knapsacks" << endl;
   buildSpices(instructions, spices);       // Build all spices using the parsed instructions
   buildKnapsacks(instructions, knapsacks); // Build all knapsacks using the parsed instructions
   cout << "--------------------------------------------------" << endl;
   cout << "Greedily filling Knapsacks with Spices" << endl;
   fillKnapsacks(knapsacks, spices); // Fill knapsacks using a Greedy Algorithm and return its contents
   cout << "All Knapsacks filled with Spices" << endl;
   knapsacks.clear(); // Empty the list of knapsacks
   cout << "Knapsacks destroyed" << endl;
}

int main()
{
   Graph graph;
   interactGraph(graph);
   cout << "--------------------------------------------------" << endl;
   Spices spices;
   std::vector<Knapsack *> knapsacks;
   interactSpices(spices, knapsacks);
   return 0;
}