// Algorithms ~ A.Labouseur, Assignment 4 - Connor Fleischman

#include "./graph/UseGraph.h"
#include "./Build.h"

using namespace std; // Globally used namespace, removing use of std::

void interactGraph(Graph &graph)
{
   int numGraphs = 0;                                           // Counter to track the number of graphs being produced
   for (vector<string> graphInstructions : buildInstructions()) // For every graph in the blueprint returned by buildInstructions()
   {
      numGraphs++; // Increment for every graph built
      cout << "Building graph #" << numGraphs << endl;
      buildGraph(graphInstructions, graph);
      // TODO: SSSP Algorithm
      clearGraph(graph);
   }
   numGraphs = 0;
}

int main()
{
   Graph graph;

   interactGraph(graph);

   return 0;
}