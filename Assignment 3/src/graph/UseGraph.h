// Algorithms ~ A. Labouseur, Assignment 3 - Connor Fleischman

#include "UndirectedGraph.h"

void depthFirstTraversal(Graph &graph, string vertexStartID) // Perform a depth-first traversal on the graph starting at some vertex's ID
{
   graph.traverseDF(graph.search(vertexStartID)); // Call the traverse function starting at vertex ID, from "UndirectedGraph.h"
}

void breadthFirstTraversal(Graph &graph, string vertexStartID) // Perform a breadth-first traversal on the graph
{
   graph.traverseBF(graph.search(vertexStartID)); // Call the traverse function from "UndirectedGraph.h"
}

void displayMatrix(Graph &graph) // Display the graph as a matrix
{
   graph.displayAsMatrix(); // Call the display function from "UndirectedGraph.h"
}

void displayAdjacencyList(Graph &graph) // Display the graph as an adjacency list
{
   graph.displayAsAdjacencyList(); // Call the display function from "UndirectedGraph.h"
}

bool clearGraph(Graph &graph) // Empty the graph
{
   graph.clear();          // Call the empty function from "UndirectedGraph.h"
   return graph.isEmpty(); // Return if the graph is empty or not
}