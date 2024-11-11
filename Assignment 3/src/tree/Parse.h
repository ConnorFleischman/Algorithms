// Algorithms ~ A. Labouseur, Assignment 3 - Connor Fleischman

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
   return lines;
}

vector<string> parseKeys()
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
   return lines;
}