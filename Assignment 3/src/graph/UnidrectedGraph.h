// Algorithms ~ A. Labouseur, Assignment 3 - Connor Fleischman

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std; // Globally used namespace (removes use of std::)

class Vertex
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

class Matrix
{
private:
   vector<Vertex *> vertices;

public:
   Matrix() {}

   void insertVertex(string vertexID)
   {
      Vertex *newVertex = new Vertex(vertexID); // create new vertex
      vertices.push_back(newVertex);            // add new vertex to vertices
   }

   bool deleteVertex(Vertex *vertexID)
   {
      if (!isEmpty())
      {
         for (Vertex *vertex : vertices)
         {
            if (vertex->id == vertexID->id)
            {
               delete vertex;
               vertices.erase(vertex);
               return true
            }
         }
         cout << "Vertex not found" << endl;
         return false;
      }
      else
      {
         cout << "Cannot delete from an empty Matrix" << endl;
         return false;
      }
   }

   void insertEdge(Vertex *vertexStart, Vertex *vertexEnd)
   {
      vertexStart->neighbors.push_back(vertexEnd);
      vertexEnd->neighbors.push_back(vertexStart);
   }

   bool isEmpty()
   {
      return vertices.empty();
   }

   bool clear()
   {
      for (Vertex *vertex : vertices)
      {
         delete vertex;
      }
      vertices.clear();
      cout << "Matrix emptied" << endl;
      return isEmpty();
   }

   void display()
   {
      if (isEmpty)
      {
         cout << "Matrix is empty" << endl;
         return;
      }
      else
      {
         for (Vertex *vertex : vertices)
         {
            cout << "[" << vertex->id << "]: ";
            for (Vertex *neighbor : vertex->neighbors)
            {
               cout << neighbor->id << " ";
            }
            cout << endl;
         }
      }
   }
};

class AdjacencyList
{
private:
   vector<Vertex *> vertices;

public:
   AdjacencyList() {}

   bool isEmpty()
   {
      return vertices.empty();
   }

   bool clear()
   {
      for (Vertex *vertex : vertices)
      {
         delete vertex;
      }
      vertices.clear();
      cout << "Adjacency List emptied" << endl;
      return isEmpty();
   }

   void display()
   {
      if (isEmpty)
      {
         cout << "Adjacency List is empty" << endl;
         return;
      }
      else
      {
         for (Vertex *vertex : vertices)
         {
            cout << "[" << vertex->id << "]: ";
            for (Vertex *neighbor : vertex->neighbors)
            {
               cout << neighbor->id << " ";
            }
            cout << endl;
         }
      }
   }
};

class LinkedObjects
{
private:
   vector<Vertex *> vertices;

public:
   LinkedObjects() {}
};
