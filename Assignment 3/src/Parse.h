// Algorithms ~ A. Labouseur, Assignment 3 - Connor Fleischman
#pragma once // This ensures the contents of the file is exported once, stopping any redefinition errors

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std; // Globally used namespace (removes use of std::)

vector<string> parseItems() // Fills lines with the items in file: magicItems.txt
{
   vector<string> lines;                         // Declare vector of strings 'lines'
   ifstream file("./tree/input/magicItems.txt"); // Open the file

   if (file.is_open()) // If the file is open
   {
      string line;                // Declares a line as a string
      while (getline(file, line)) // Read each line in the file
      {
         lines.push_back(line); // Add each line to the vector lines
      }
      file.close(); // Close the file
   }
   else // If the file is not open
   {
      cout << "Error opening file" << endl; // Log that the file did not open
   }
   return lines; // Return the vector of strings
}

vector<string> parseKeys() // Fill keys with the items in file: magicitems-find-in-bst.txt
{
   vector<string> lines;                                     // Declare vector of strings 'lines'
   ifstream file("./tree/input/magicitems-find-in-bst.txt"); // Open the file

   if (file.is_open()) // If the file is open
   {
      string line;                // Declares a line as a string
      while (getline(file, line)) // Read each line in the file
      {
         lines.push_back(line); // Add each line to the vector lines
      }
      file.close(); // Close the file
   }
   else // If the file is not open
   {
      cout << "Error opening file" << endl; // Log that the file did not open
   }
   return lines; // Return the vector of strings
}

vector<vector<string>> parseGraph() // Returns a vector of graphs, consisting of a vector of strings, where each string is a vertex or edge, from the file: graphs1.txt
{
   vector<vector<string>> graphs;              // Declare graphs as a vector of vectors of strings
   ifstream file("./graph/input/graphs1.txt"); // Declare file and open file at location

   if (file.is_open()) // If the file is open
   {
      vector<string> currentGraph; // Declare currentGraph as a vector of strings
      string line;                 // Declare line as a string
      while (getline(file, line))  // For every line in the file
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
      cout << "Error opening file" << endl;
   }
   return graphs; // Return the vector of vectors of strings
}