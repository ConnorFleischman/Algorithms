// Algorithms ~ A. Labouseur, Assignment 3 - Connor Fleischman
#ifndef H_USEGRAPH
#define H_USEGRAPH

#include "UndirectedGraph.h"

// Graph mutation:
void insertVertex(string &vertexID, Graph &graph)
{
   graph.insertVertex(vertexID);
}

void insertEdge(string &startID, string &endID, Graph &graph)
{
   graph.insertEdge(startID, endID);
}

void clearGraph(Graph &graph) // Empty the graph
{
   graph.clear(); // Call the empty function from "UndirectedGraph.h"
}

// Graph display:
void depthFirstTraversal(Graph &graph) // Perform a depth-first traversal on the graph starting at some vertex's ID
{
   graph.traverse("depth"); // Call the traverse function starting at vertex ID, from "UndirectedGraph.h"
   cout << endl;
   cout << "---------------------------------------" << endl;
}

void breadthFirstTraversal(Graph &graph) // Perform a breadth-first traversal on the graph
{
   graph.traverse("breadth"); // Call the traverse function from "UndirectedGraph.h"
   cout << endl;
   cout << "---------------------------------------" << endl;
}

void displayMatrix(Graph &graph) // Display the graph as a matrix
{
   graph.displayAsMatrix(); // Call the display function from "UndirectedGraph.h"
}

void displayAdjacencyList(Graph &graph) // Display the graph as an adjacency list
{
   graph.displayAsAdjacencyList(); // Call the display function from "UndirectedGraph.h"
}

#endif