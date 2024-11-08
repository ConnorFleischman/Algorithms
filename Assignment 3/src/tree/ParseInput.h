// Algorithms ~ A. Labouseur, Assignment 3 - Connor Fleischman

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std; // Globally used namespace (removes use of std::)

vector<string> parse()
{
   vector<string> lines;
   ifstream file("./input/magicItems.txt"); // Open the file

   if (file.is_open())
   {
      string line;
      while (getline(file, line)) // Read each line
      {
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