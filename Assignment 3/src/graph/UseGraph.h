// Algorithms ~ A. Labouseur, Assignment 3 - Connor Fleischman
#pragma once // This ensures the contents of the file is exported once, stopping any redefinition errors

#include "UndirectedGraph.h"

// string depthFirstTraversal(Graph *graph) // Perform a depth-first traversal on the graph
// {
//    return graph->traverseDF(); // Returns the traverse function from "UndirectedGraph.h"
// }

// string breadthFirstTraversal(Graph *graph) // Perform a breadth-first traversal on the graph
// {
//    return graph->traverseBF(); // Returns the traverse function from "UndirectedGraph.h"
// }

void displayMatrix(Graph *graph) // Display the graph as a matrix
{
   graph->displayAsMatrix(); // Call the display function from "UndirectedGraph.h"
}

void displayAdjacencyList(Graph *graph) // Display the graph as an adjacency list
{
   graph->displayAsAdjacencyList(); // Call the display function from "UndirectedGraph.h"
}
