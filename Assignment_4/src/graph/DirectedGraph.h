// Algorithms ~ A.Labouseur, Assignment 4 - Connor Fleischman
#ifndef H_DIRECTEDGRAPH
#define H_DIRECTEDGRAPH

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

class Vertex // Defines the Vertex class
{
public:
   std::string id;                  // Identifies the id of the vertex
   bool processed;                  // Identifies the processed flag for the vertex
   int distance;                    // Identifies the distance from the source to this vertex
   Vertex *predecessor;             // Identifies the predecessor vertex for Bellman-Ford
   std::vector<Vertex *> neighbors; // Identifies the list of neighbors of the vertex

   Vertex(std::string &idValue) // Vertex constructor
   {
      this->id = idValue;          // Set this vertex's id to some given value
      this->processed = false;     // Set this vertex's processed flag to false
      this->distance = 8675309;    // Jenny don't change your number
      this->predecessor = nullptr; // Set this vertex's predecessor to nullptr
   }
};
class Edge // Defines the Edge class
{
public:
   std::string startID; // Identifies the starting vertex ID of the edge
   std::string endID;   // Identifies the ending vertex ID of the edge
   int weight;          // Identifies the weight of the edge

   Edge(std::string &v1ID, std::string &v2ID, int cost) // Edge constructor
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

   void printPath(std::string &vertexID) // Private function to print the path from some source to some sink
   {
      Vertex *currentVertex = search(vertexID);  // Find the current vertex
      if (currentVertex->predecessor != nullptr) // If the current vertex exists
      {
         printPath(currentVertex->predecessor->id); // Recurse on that vertex's predecessor until no more predecessors are found
         std::cout << " -> ";
      }
      std::cout << currentVertex->id; // Print the vertex
   }

public:
   Graph() {} // Graph constructor
   ~Graph()   // Graph destructor
   {
      std::cout << "-- Destroying Graph --" << std::endl;
      if (!isEmpty())
      {
         clear(); // Clear the graph
      }
      if (isEmpty()) // If the graph was cleared
      {
         std::cout << "-- Graph Destroyed --" << std::endl;
      }
      else // If the graph was not cleared
      {
         std::cout << "<< Graph could not be emptied >>" << std::endl;
      }
   }

   void insertVertex(std::string &vertexID) // Insert a vertex into the graph by some ID
   {
      Vertex *newVertex = new Vertex(vertexID); // create new vertex with some ID
      vertices.push_back(newVertex);            // Add that new vertex to vertices vector
      std::cout << "Vertex #" << vertexID << " created" << std::endl;
   }

   void insertEdge(std::string &vertexStartID, std::string &vertexEndID, int edgeWeight) // Insert an edge between two vertex IDs
   {
      Vertex *vertexStart = search(vertexStartID); // Search for the starting vertex by its ID
      Vertex *vertexEnd = search(vertexEndID);     // Search for the ending vertex by its ID

      if (vertexStart && vertexEnd) // If both vertices exist
      {
         Edge *newEdge = new Edge(vertexStart->id, vertexEnd->id, edgeWeight); // Create a new edge between two vertices's ID's with some weight
         edges.push_back(newEdge);                                             // Add that new edge to the edges vector
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

   void deleteVertex(std::string &vertexID) // Deletes a vertex by its ID
   {
      if (isEmpty()) // If the graph is empty
      {
         std::cout << "Cannot delete a vertex from an empty Graph" << std::endl;
         return;
      }

      for (Vertex *vertex : vertices) // For every vertex in the graph
      {
         for (int i = 0; i < vertex->neighbors.size(); i++) // For every one of the vertex's neighbors
         {
            if (vertex->neighbors[i]->id == vertexID) // If that neighbors ID is equal to the vertex to be deleted's ID
            {
               vertex->neighbors.erase(vertex->neighbors.begin() + i); // Erase that neighbor from the list of neighbors
               i--;                                                    // Decrement the search index to recheck the modified list
            }
         }
      }

      for (int i = 0; i < vertices.size(); i++) // For every vertex stored in vertices
      {
         if (vertices[i]->id == vertexID) // If that vertex's ID is the ID to be deleted
         {
            delete vertices[i];                   // Deleted that vertex
            vertices.erase(vertices.begin() + i); // Remove the vertex from the list of vertices
            std::cout << "Vertex #" << vertexID << " deleted" << std::endl;
            return;
         }
      }
      // If the vertex is not found
      std::cout << "Vertex #" << vertexID << " not found" << std::endl;
   }

   void deleteEdge(std::string &v1ID, std::string &v2ID) // Deletes an edge between two vertices's ID's
   {
      if (isEmpty()) // If the graph is empty
      {
         std::cout << "Cannot delete an edge from an empty Graph" << std::endl;
         return;
      }

      Vertex *startVertex = search(v1ID); // Search for the starting vertex using it's ID
      if (!startVertex)                   // If the starting vertex is not found
      {
         std::cout << "Vertex #" << v1ID << " not found" << std::endl;
         return;
      }
      // If the starting vertex is found
      for (int i = 0; i < startVertex->neighbors.size(); i++) // For every position in the starting vertex's neighbors list
      {
         if (startVertex->neighbors[i]->id == v2ID) // If that position's ID is equal to the end vertex's ID
         {
            startVertex->neighbors.erase(startVertex->neighbors.begin() + i); // Remove the end from the starts's list of neighbors
            break;
         }
      }

      for (int i = 0; i < edges.size(); i++) // For every edge stored in edges
      {
         if (edges[i]->startID == v1ID && edges[i]->endID == v2ID) // If that edges's start and end ID are the ones to be deleted
         {
            delete edges[i];                // Delete that edge
            edges.erase(edges.begin() + i); // Remove that edge from the list of edges
            std::cout << "Edge from vertices #" << v1ID << " to #" << v2ID << " deleted" << std::endl;
            return;
         }
      }
      // If the edge is not found
      std::cout << "Edge from vertices #" << v1ID << " to #" << v2ID << " not found" << std::endl;
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
      for (Edge *edge : edges) // Delete all edges safely
      {
         delete edge;
      }
      edges.clear();

      std::cout << "-- Edges Deleted --" << std::endl;

      for (Vertex *vertex : vertices) // Delete all vertices safely
      {
         delete vertex;
      }
      vertices.clear();

      std::cout << "-- Vertices Deleted --" << std::endl;
   }

   bool mapPathways(std::string &startID) // Constructs the pathways between vertices from a starting vertex
   {
      Vertex *startVertex = search(startID); // Search for the starting vertex using it's ID
      if (!startVertex)                      // If the starting vertex is not found
      {
         std::cout << "Vertex #" << startID << " not found" << std::endl;
         return false;
      }
      // If the starting vertex is found
      startVertex->distance = 0;                    // Set the starting vertex's distance to 0
      for (int i = 0; i < vertices.size() - 1; i++) // For every item in the list of vertices - 1
      {
         for (Edge *edge : edges) // For every edge in edges
         {
            Vertex *startEdgeVertex = search(edge->startID); // Set the starting edge vertex to that edge's start vertex
            Vertex *endEdgeVertex = search(edge->endID);     // Set the ending edge vertex to that edge's end vertex

            if (endEdgeVertex->distance > startEdgeVertex->distance + edge->weight) // Relax function to check if a shorter path exists
            {
               endEdgeVertex->distance = startEdgeVertex->distance + edge->weight; // Setting the shortest path
               endEdgeVertex->predecessor = startEdgeVertex;                       // Setting the predecessor vertex
            }
         }
      }
      // After all vertices have been mapped out
      for (Edge *edge : edges) // For every edge in edges
      {
         Vertex *startEdgeVertex = search(edge->startID);                        // Set the starting edge vertex to that edge's start vertex
         Vertex *endEdgeVertex = search(edge->endID);                            // Set the ending edge vertex to that edge's end vertex
         if (endEdgeVertex->distance > startEdgeVertex->distance + edge->weight) // If a shorter path is found after, then there is a negative weight cycle
         {
            std::cout << "<< Graph contains a negative-weight cycle >>" << std::endl;
            return false;
         }
      }
      // If no shorter paths exist
      for (Vertex *vertex : vertices)
      {
         if (vertex->id != startID) // For all vertices not the start
         {
            std::cout << "#" << startID << std::setw(3) << " -> #" << vertex->id << " | Cost: " << std::setw(3) << vertex->distance << " | Path: ";
            printPath(vertex->id); // Prints the path from the source to this vertex
            std::cout << std::endl;
         }
      }
      return true;
   }
};

#endif