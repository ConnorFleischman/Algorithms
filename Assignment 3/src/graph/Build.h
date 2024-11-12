// Algorithms ~ A. Labouseur, Assignment 3 - Connor Fleischman

#include <vector>
#include <string>
#include <sstream>

using namespace std; // Globally used namespace (removes use of std::)

void decode(const vector<string> &lines)
{
   for (const auto &line : lines)
   {
      istringstream stream(line);
      string firstWord, secondWord;
      stream >> firstWord;

      if (firstWord == "new")
      {
         // add new graph
      }

      if (firstWord == "add")
      {
         stream >> secondWord;
         if (secondWord == "vertex")
         {
            // add vertex #
         }
         if (secondWord == "edge")
         {
            // add edge from x-y
         }
      }
   }
}

// class Vertex
// {
//    private:
//    int id;
//    Vertex(int id)
//    {
//       this->id = id;
//    }
// }
// class Edge
// {
//    private:
//    vector<*Vertex>
// }
// class Graph
// {
// public:
//    int vertex;

// }
// class Vertex // Defines the Node class
// {
// public:
//    int data;           // Identifies the data section of the node
//    vector<Node> *next; // Identifies the pointers to the next node

//    Node(std::string &item) // Creates a node which takes in some item
//    {
//       this->data = item;    // Sets this node's data point to item
//       this->next = nullptr; // Sets this node's next point to null
//    }
// };