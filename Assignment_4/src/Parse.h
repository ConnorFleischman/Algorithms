// Algorithms ~ A.Labouseur, Assignment 4 - Connor Fleischman
#ifndef H_PARSE
#define H_PARSE

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

// Graph parsing
std::vector<std::vector<std::string>> parseGraph() // Returns a vector of graphs, consisting of a vector of strings, where each string is a vertex or edge, from the file: graphs2.txt
{
   std::vector<std::vector<std::string>> graphs; // Declare graphs as a vector of vectors of strings
   std::ifstream file("./input/graphs2.txt");    // Declare file and open file at location

   if (file.is_open()) // If the file is open
   {
      std::vector<std::string> currentGraph; // Declare currentGraph as a vector of strings
      std::string line;                      // Declare line as a string
      while (getline(file, line))            // For every line in the file
      {
         if (line.empty() || line.front() == '-') // If the line is empty or a comment line
         {
            continue; // Skip this line
         }
         if (line == "new graph") // If the line declares a new graph
         {
            if (!currentGraph.empty()) // If the current graph storage is not empty
            {
               graphs.push_back(currentGraph); // Push the current graph back to the graphs vector
               currentGraph.clear();           // Clear the current graph vector for the next graph to be read
            }
            continue; // Skip this line
         }
         // Non-skiped lines:
         currentGraph.push_back(line); // Push the line to the current graph
         // Continue to the next line
      }
      // When all lines in the file are read
      if (!currentGraph.empty()) // If there is still a graph in the current graph vector
      {
         graphs.push_back(currentGraph); // Push this final graph back to the vector of graphs
      }

      file.close(); // Close the file
   }
   else // If the file is not open
   {
      std::cout << "Error opening file" << std::endl;
   }
   return graphs; // Return the vector of vectors of strings
}

// Spices parsing
std::vector<std::string> parseSpices()
{
   std::vector<std::string> spices;         // Declare spices as a vector of strings
   std::ifstream file("./input/spice.txt"); // Declare file and open file at location

   if (file.is_open()) // If the file is open
   {
      std::string line;           // Declare line as a string
      while (getline(file, line)) // For every line in the file
      {
         if (line.empty() || line.front() == '-') // If the line is empty or a comment line
         {
            continue; // Skip this line
         }
         // Non-skiped lines:
         spices.push_back(line); // Push the line to spices
      }
   }
   else // If the file is not open
   {
      std::cout << "Error opening file" << std::endl;
   }
   return spices;
}

#endif