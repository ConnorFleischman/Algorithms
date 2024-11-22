// Algorithms ~ A.Labouseur, Assignment 4 - Connor Fleischman
#ifndef H_DIRECTEDGRAPH
#define H_DIRECTEDGRAPH

#include <iostream>
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
   std::string startID; // Identifies the starting vertex ID of the edge
   std::string endID;   // Identifies the ending vertex ID of the edge
   int weight;          // Identifies the weight of the edge

   Edge(std::string v1ID, std::string v2ID, int cost) // Edge constructor
   {
      this->startID = v1ID; // Set this edge's start to v1
      this->endID = v2ID;   // Set this edge's end to v2
      this->weight = cost;  // Set this edge's weight to cost
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

   void insertVertex(std::string &vertexID) // Insert a vertex into the graph by some ID
   {
      Vertex *newVertex = new Vertex(vertexID); // create new vertex with some ID
      vertices.push_back(newVertex);            // add that new vertex to vertices vector
      std::cout << "Vertex #" << vertexID << " created" << std::endl;
   }

   void insertEdge(std::string &vertexStartID, std::string &vertexEndID, int edgeWeight) // Insert an edge between two vertex IDs
   {
      Vertex *vertexStart = search(vertexStartID); // Search for the starting vertex by its ID
      Vertex *vertexEnd = search(vertexEndID);     // Search for the ending vertex by its ID

      if (vertexStart && vertexEnd) // If both vertices exist
      {
         Edge *newEdge = new Edge(vertexStart->id, vertexEnd->id, edgeWeight); // create a new edge between two vertices's ID's with some weight
         edges.push_back(newEdge);                                             // add that new edge to the edges vector
         vertexStart->neighbors.push_back(vertexEnd);                          // Update the starting vertex's neighbors list so that it has the ending vertex as a neighbor
         std::cout << "Edge created from vertex #" << vertexStartID << " to #" << vertexEndID << " with weight: " << edgeWeight << std::endl;
      }
      else // If either vertex does not exist
      {
         if (vertexStart == nullptr) // If the start vertex does not exist
         {
            std::cout << "Error: Vertex #" << vertexStartID << " does not exist" << std::endl;
         }
         if (vertexEnd == nullptr) // If the end vertex does not exist
         {
            std::cout << "Error: Vertex #" << vertexEndID << " does not exist" << std::endl;
         }
         // Regardless:
         std::cout << "Cannot insert edge from Vertex: " << vertexStartID << " to Vertex: " << vertexEndID << std::endl;
      }
   }

   void deleteVertex(std::string &vertexID) // Deletes a vertex by its ID string
   {
      // TODO: Delete Vertex Implementation
   }

   void deleteEdge(std::string v1ID, std::string v2ID) // Deletes an edge between two vertices's ID's
   {
      // TODO: Delete Edge Implementation
   }

   Vertex *search(std::string &vertexID) // Search for a vertex in the graph by its ID, return the Vertex or null
   {
      for (Vertex *vertex : vertices) // For every vertex in the graph
      {
         if (vertex->id == vertexID) // If their ID is the ID being searched
         {
            return vertex; // Return that vertex
         }
      }
      // If the vertex is not found
      return nullptr;
   }

   bool isEmpty() // Returns true/false depending on if the graph is empty
   {
      return vertices.empty();
   }

   void clear() // Empties the graph
   {
      for (Vertex *vertex : vertices) // For every vertex in the graph
      {
         deleteVertex(vertex->id); // Delete that vertex, allocate memory space
      }
      vertices.clear(); // Clear vertices

      for (Edge *edge : edges) // For every edge in the graph
      {
         Vertex *startVertex = search(edge->startID);
         Vertex *endVertex = search(edge->endID);
         deleteEdge(startVertex->id, endVertex->id); // Delete that edge,  between two vertices's ID's, allocate memory space
      }
      edges.clear(); // Clear edges

      std::cout << "Graph emptied" << std::endl;
   }

   // TODO: Single Source Shortest Path Algorithm Implementation
};

#endif