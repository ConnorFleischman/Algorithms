// Algorithms ~ A. Labouseur, Assignment 3 - Connor Fleischman
#ifndef H_UNDIRECTEDGRAPH
#define H_UNDIRECTEDGRAPH

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <queue>

using namespace std; // Globally used namespace (removes use of std::)

class Vertex // Defines the Vertex class
{
public:
   string id;                  // Identifies the id of this vertex
   bool processed;             // Identifies the processed flag for this vertex
   vector<Vertex *> neighbors; // Identifies the list of neighbors of this vertex

   Vertex(string &idValue) // Vertex constructor
   {
      this->id = idValue;      // Set this vertex's id to some given value
      this->processed = false; // Set this vertex's processed flag to false
   }
};

class Graph // Defines the Graph class
{
private:
   vector<Vertex *> vertices; // Vertices is a list of the vertices in the graph

   // Traversal functions are private and only accessible through the traverse() method
   void traverseDF(Vertex *vertex) // Recursively traverses over all vertices in depth-first order
   {
      if (!vertex->processed) // If the vertex is not processed
      {
         cout << vertex->id << " "; // print vertex id
         vertex->processed = true;  // Set the processed flag true
      }
      for (Vertex *neighbor : vertex->neighbors) // For each neighbor of this vertex
      {
         if (!neighbor->processed) // If the neighbor is unprocessed
         {
            traverseDF(neighbor); // Recurs on the unprocessed neighbor
         }
      }
   }

   void traverseBF(Vertex *vertex) // Traverses over all vertices in breadth-first order using a queue
   {
      queue<Vertex *> queue;    // Declare queue to maintain sequence order
      queue.push(vertex);       // Push the current vertex to the queue
      vertex->processed = true; // Set this vertex's processed flag to true
      while (!queue.empty())    // While the queue is not empty
      {
         Vertex *currVertex = queue.front(); // Declare currVertex as the first vertex in the queue
         queue.pop();                        // Pop the first vertex off the front of the queue
         cout << currVertex->id << " ";      // print the current vertex's id

         for (Vertex *neighbor : currVertex->neighbors) // For every of the popped vertex's neighboring vertices
         {
            if (!neighbor->processed) // If the neighbor is not processed
            {
               queue.push(neighbor);       // Enqueue that neighbor
               neighbor->processed = true; // Set that neighbors processed flag to true
            }
         }
      }
   }

public:
   Graph() {} // Graph constructor

   ~Graph() // Graph destructor
   {
      for (Vertex *vertex : vertices) // For every vertex in the graph
      {
         deleteVertex(vertex->id); // Delete that vertex
      }
      vertices.clear(); // Clear vertices
      cout << "Graph deleted" << endl;
   }

   void insertVertex(string &vertexID) // Insert a vertex into the graph by some ID
   {
      Vertex *newVertex = new Vertex(vertexID); // create new vertex with some ID
      vertices.push_back(newVertex);            // add that new vertex to vertices vector
      cout << "Vertex #" << vertexID << " created" << endl;
   }

   bool deleteVertex(string &vertexID) // Delete a vertex from the graph by some ID
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

   void insertEdge(string &vertexStartID, string &vertexEndID) // Insert an edge between two vertex IDs
   {
      Vertex *vertexStart = search(vertexStartID); // Search for the starting vertex by its ID
      Vertex *vertexEnd = search(vertexEndID);     // Search for the ending vertex by its ID

      if (vertexStart && vertexEnd) // If both vertices exist
      {
         vertexStart->neighbors.push_back(vertexEnd); // Update the starting vertex's neighbors list so that it has the ending vertex as a neighbor
         vertexEnd->neighbors.push_back(vertexStart); // Update the ending vertex's neighbors list so that it has the starting vertex as a neighbor
         cout << "Edge created from vertex #" << vertexStartID << " to #" << vertexEndID << endl;
      }
      else // If either vertex does not exist
      {
         if (vertexStart == nullptr) // If the start vertex does not exist
         {
            cout << "Error: Vertex #" << vertexStartID << " does not exist" << endl;
         }
         if (vertexEnd == nullptr) // If the end vertex does not exist
         {
            cout << "Error: Vertex #" << vertexEndID << " does not exist" << endl;
         }
         // Regardless:
         cout << "Cannot insert edge from Vertex: " << vertexStartID << " to Vertex: " << vertexEndID << endl;
      }
   }

   Vertex *search(string &vertexID) // Search for a vertex in the graph by its ID, return the Vertex or null
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
         delete vertex; // Delete that vertex, allocate memory space
      }
      vertices.clear(); // Clear vertices
      cout << "Graph emptied" << endl;
   }

   void displayAsAdjacencyList() // Method to display the graph as an Adjacency List
   {
      if (isEmpty()) // If the graph is empty
      {
         cout << "Cannot display Adj List: Graph is empty" << endl;
         return;
      }
      else // If the graph is not empty
      {
         cout << "Adjacency List:" << endl;
         for (Vertex *vertex : vertices) // For every vertex in the graph
         {
            cout << "[" << vertex->id << "]: ";        // Display that vertex
            for (Vertex *neighbor : vertex->neighbors) // For every one of that vertex's neighbors
            {
               cout << neighbor->id << " "; // Display that neighbor
            }
            cout << endl; // Once all neighbors are displayed, new line, move to next vertex
         }
         cout << "---------------------------------------" << endl;
      }
   }

   void displayAsMatrix() // Method to display the graph as a Matrix
   {
      if (isEmpty()) // If the graph is empty
      {
         cout << "Cannot display Matrix: Graph is empty" << endl;
         return;
      }
      else // If the graph is not empty
      {
         cout << "Matrix:" << endl;
         cout << setw(4) << ""; // Adjust spacing

         // Column display
         for (int i = 0; i < vertices.size(); i++) // For every element in vertices
         {
            cout << setw(3) << vertices[i]->id; // Display that vertex (col header), adjust spacing
         }
         cout << endl;
         cout << string(((vertices.size() + 2) * 3), '_') << endl; // Display '_' as long as the number of nodes

         // Row display
         for (int i = 0; i < vertices.size(); i++)
         {
            cout << setw(3) << vertices[i]->id << "|"; // Display that vertex (row header), adjust spacing
            for (int j = 0; j < vertices.size(); j++)  // For every element in vertices
            {
               bool isNeighbor = false;                        // Flag to record if a vertex has col as a neighbor
               for (Vertex *neighbor : vertices[i]->neighbors) // For every neighbor in the vertex(col)'s neighbors
               {
                  if (neighbor->id == vertices[j]->id) // If the neighbor's ID is the current vertex(row)'s ID
                  {
                     isNeighbor = true; // Set flag
                     break;
                  }
               }
               if (isNeighbor) // If the col/row intersect shows that the vertices at those positions are neighbors
               {
                  cout << setw(3) << 'X'; // Record that there is an edge between these two vertices
               }
               else // If no neighbor exists at the col/row intersection
               {
                  cout << setw(3) << '-'; // Record that no edge exists between these two vertices
               }
            }
            cout << endl; // End this row, go to the next row
         }
         cout << "---------------------------------------" << endl;
      }
   }

   void traverse(string type) // Traverse, using some method
   {
      // Before every traversal:
      for (Vertex *vertex : vertices) // For every vertex in vertices
      {
         vertex->processed = false; // Set that vertex's processed flag to false
      }

      for (Vertex *vertex : vertices) // For every vertex in vertices
      {
         if (!vertex->processed) // If the vertex is unprocessed
         {
            if (type == "depth") // If the type specified is depth
            {
               traverseDF(vertex); // Perform a depth-first search
               cout << endl;
            }
            if (type == "breadth") // If the type specified is breadth
            {
               traverseBF(vertex); // Perform a breadth-first search
               cout << endl;
            }
         }
      }
   }
};

#endif