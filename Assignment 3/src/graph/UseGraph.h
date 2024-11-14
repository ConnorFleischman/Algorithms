// Algorithms ~ A. Labouseur, Assignment 3 - Connor Fleischman
#ifndef H_USEGRAPH
#define H_USEGRAPH

#include "UndirectedGraph.h"

// Graph mutation:
void insertVertex(string &vertexID, Graph &graph) // Insert a vertex of ID into the graph
{
   graph.insertVertex(vertexID); // Call the insert function from "UndirectedGraph.h"
}

void insertEdge(string &startID, string &endID, Graph &graph) // Insert an edge from vertices startID to endID in the graph
{
   graph.insertEdge(startID, endID); // Call the insert function from "UndirectedGraph.h"
}

void clearGraph(Graph &graph) // Empty the graph
{
   graph.clear(); // Call the empty function from "UndirectedGraph.h"
}

// Graph display:
void depthFirstTraversal(Graph &graph) // Perform a depth-first traversal on the graph
{
   graph.traverse("depth"); // Call the traverse function from "UndirectedGraph.h"
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