// Algorithms ~ A. Labouseur, Assignment 3 - Connor Fleischman

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std; // Globally used namespace (removes use of std::)

// Function to load data from the file into a vector of strings
vector<string> parse()
{
   vector<string> lines;
   ifstream file("./input/graphs1.txt"); // Open the file

   if (file.is_open())
   {
      string line;
      while (getline(file, line))
      { // Read each line
         if (line.empty() || line.front() == '-')
         { // Skip all lines without data
            continue;
         }
         lines.push_back(line); // Add line to vector
      }
      file.close();
   }
   else
   {
      cout << "Error opening file" << endl;
   }

   return lines;
}
