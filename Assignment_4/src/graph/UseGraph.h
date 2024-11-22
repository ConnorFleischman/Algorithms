// Algorithms ~ A.Labouseur, Assignment 4 - Connor Fleischman
#ifndef H_USEGRAPH
#define H_USEGRAPH

#include "DirectedGraph.h"

// Graph mutation:
void insertVertex(std::string &vertexID, Graph &graph) // Insert a vertex with some ID into some graph
{
   graph.insertVertex(vertexID);
}

void insertEdge(std::string &startID, std::string &endID, int weight, Graph &graph)
{
   graph.insertEdge(startID, endID, weight);
}

void deleteVertex(std::string &vertexID, Graph &graph)
{
   graph.deleteVertex(vertexID);
}

void deleteEdge(std::string &startID, std::string &endID, Graph &graph)
{
   graph.deleteEdge(startID, endID);
}

void clearGraph(Graph &graph)
{
   graph.clear();
}

// Graph processes:
#endif