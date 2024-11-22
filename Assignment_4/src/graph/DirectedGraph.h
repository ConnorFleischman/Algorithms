// Algorithms ~ A.Labouseur, Assignment 4 - Connor Fleischman
#ifndef H_DIRECTEDGRAPH
#define H_DIRECTEDGRAPH

#include <vector>
#include <string>

class Vertex // Defines the Vertex class
{
public:
   std::string id;                  // Identifies the id of the vertex
   bool processed;                  // Identifies the processed flag for the vertex
   std::vector<Vertex *> neighbors; // Identifies the list of neighbors of the vertex

   Vertex(std::string &idValue) // Vertex constructor
   {
      this->id = idValue;      // Set this vertex's id to some given value
      this->processed = false; // Set this vertex's processed flag to false
   }
};
class Edge // Defines the Edge class
{
public:
   Vertex *start; // Identifies the starting vertex of the edge
   Vertex *end;   // Identifies the ending vertex of the edge
   int weight;    // Identifies the weight of the edge

   Edge(Vertex *v1, Vertex *v2, int cost) // Edge constructor
   {
      this->start = v1;    // Set this edge's start to v1
      this->end = v2;      // Set this edge's end to v2
      this->weight = cost; // Set this edge's weight to cost
   }
};

class Graph // Defines Graph class
{
private:
   std::vector<Vertex *> vertices; // Vector to contain all Vertices in the graph
   std::vector<Edge *> edges;      // Vector to contain all Edges in the graph
public:
   Graph() {}             // Graph constructor
   ~Graph() { /*TODO:*/ } // Graph destructor
};

#endif