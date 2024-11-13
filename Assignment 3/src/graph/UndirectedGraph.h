// Algorithms ~ A. Labouseur, Assignment 3 - Connor Fleischman
#pragma once // This ensures the contents of the file is exported once, stopping any redefinition errors

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std; // Globally used namespace (removes use of std::)

class Vertex // Defines the Vertex class
{
public:
   string id;                  // Identifies the id of this vertex
   bool processed;             // Identifies the processed flag for this vertex
   vector<Vertex *> neighbors; // Identifies the list of neighbors of this vertex

   Vertex(string idValue) // When a vertex is constructed
   {
      this->id = idValue;      // Set this vertex's id to some given value
      this->processed = false; // Set this vertex's processed flag to false
   }
};

class Graph // Defines the Graph class
{
private:
   vector<Vertex *> vertices; // Vertices is a list of the vertices in the graph

public:
   Graph() {} // Graph constructor

   ~Graph() // Graph destructor
   {
      for (Vertex *vertex : vertices) // For every vertex in the graph
      {
         delete vertex; // Delete that vertex
      }
      vertices.clear(); // Clear vertices
      cout << "Graph deleted" << endl;
   }

   void insertVertex(string vertexID) // Insert a vertex into the graph by some ID
   {
      Vertex *newVertex = new Vertex(vertexID); // create new vertex
      vertices.push_back(newVertex);            // add new vertex to vertices
   }

   bool deleteVertex(string vertexID) // Delete a vertex from the graph by some ID
   {
      if (isEmpty()) // If the graph is empty
      {
         cout << "Cannot delete from an empty Graph" << endl;
         return false;
      }
      else // If the graph is not empty
      {
         for (int i = 0; i < vertices.size(); i++) // For every vertex in the graph
         {
            if (vertices[i]->id == vertexID) // If the vertex to be deleted is found in the vertices vector
            {
               for (Vertex *neighbor : vertices[i]->neighbors) // For every vertex neighboring the to be deleted vertex
               {
                  for (int j = 0; j < neighbor->neighbors.size(); j++) // For every one of that vertex's neighbors
                  {
                     if (neighbor->neighbors[j] == vertices[i]) // If that vertex's neighbor is the neighbor to delete
                     {
                        neighbor->neighbors.erase(neighbor->neighbors.begin() + j); // Remove the neighbor from that vertex's list of neighbors
                        break;                                                      // Break out of the loop
                     }
                  }
               }
               delete vertices[i];                   // Delete the actual vertex
               vertices.erase(vertices.begin() + i); // Erase the deleted vertex from the list of vertices
               cout << "Vertex deleted" << endl;
               return true;
            }
         }
         // If the vertex is not found
         cout << "Vertex not found" << endl;
         return false;
      }
   }

   void insertEdge(string vertexStartID, string vertexEndID) // Insert an edge between two vertex IDs
   {
      Vertex *vertexStart = search(vertexStartID); // Search for the starting vertex by its ID
      Vertex *vertexEnd = search(vertexEndID);     // Search for the ending vertex by its ID

      if (vertexStart && vertexEnd) // If both vertices exist
      {
         vertexStart->neighbors.push_back(vertexEnd); // Update the starting vertex's neighbors list so that it has the ending vertex as a neighbor
         vertexEnd->neighbors.push_back(vertexStart); // Update the ending vertex's neighbors list so that it has the starting vertex as a neighbor
      }
      else // If either vertex does not exist
      {
         cout << "Cannot insert edge from Vertex: " + vertexStartID + " to Vertex: " + vertexEndID << endl;
      }
   }

   Vertex *search(string vertexID) // Search for a vertex in the graph by its ID (string), return the Vertex, if found, or null, if not
   {
      for (Vertex *vertex : vertices) // For every vertex in the graph
      {
         if (vertex->id == vertexID) // If their ID is the ID being looked for
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

   bool clear() // Empties the graph
   {
      for (Vertex *vertex : vertices) // For every vertex in the graph
      {
         delete vertex; // Delete that vertex, allocate memory space too
      }
      vertices.clear(); // Clear the vector of vertices, vertices
      cout << "Graph emptied" << endl;
      return isEmpty(); // Return if the graph is empty
   }

   void displayAsAdjacencyList() // Method to display the graph as an Adjacency List
   {
      if (isEmpty()) // If the graph is empty
      {
         cout << "Graph is empty" << endl;
         return;
      }
      else // If the graph is not empty
      {
         cout << "Adjacency List:" << endl;
         cout << "---------------------------------------" << endl;
         for (Vertex *vertex : vertices) // For every vertex in the graph
         {
            cout << "[" << vertex->id << "]: ";        // Display that vertex
            for (Vertex *neighbor : vertex->neighbors) // For every one of that vertex's neighbors
            {
               cout << neighbor->id << " "; // Display that neighbor
            }
            cout << endl; // Once all neighbors are displayed, new line, move to next vertex
         }
      }
   }

   void displayAsMatrix() // Method to display the graph as a Matrix
   {
      if (isEmpty()) // If the graph is empty
      {
         cout << "Graph is empty" << endl;
         return;
      }
      else // If the graph is not empty
      {
         cout << "Matrix:" << endl;
         cout << "---------------------------------------" << endl;
         cout << "";
         // Column display
         for (int i = 0; i < vertices.size(); i++) // For every element in vertices
         {
            cout << "[" << vertices[i]->id << "] "; // Display that vertex (col header)
         }
         cout << endl;
         // Row display
         for (int i = 0; i < vertices.size(); i++)
         {
            cout << "[" << vertices[i]->id << "] |";  // Display that vertex (row header)
            for (int j = 0; j < vertices.size(); j++) // For every element in vertices
            {
               bool isNeighbor = false;                        // Flag to record if a row's vertex has some col as a neighbor
               for (Vertex *neighbor : vertices[i]->neighbors) // For every neighbor in the current vertex(col)'s neighbors
               {
                  if (neighbor->id == vertices[j]->id) // If the neighbor's ID is equal to the current vertex(row)'s ID
                  {
                     isNeighbor = true;
                     break;
                  }
               }
               if (isNeighbor) // If the col/row intersect shows that the vertexes at those positions are neighbors
               {
                  cout << 'X'; // Record that there is an edge between these two vertices
               }
               else // If no neighbor exists at the col/row intersection
               {
                  cout << '-'; // Record that no edge exists between these two vertices
               }
            }
            cout << endl; // End this row, go to the next row
         }
      }
   }

   // string traverseDF() // Traverses over all vertices in depth-first order
   // {
   //    Vertex *currVertex; // Set a pointer to the first vertex

   //    for (Vertex *vertex : vertices) // For every vertex in vertices
   //    {
   //       vertex->processed = false; // Set each vertex's processed flag to false
   //    }
   // }

   // string traverseBF() // Traverses over all vertices in breadth-first order
   // {
   // }
};