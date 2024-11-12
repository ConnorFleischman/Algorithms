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

vector<string> parseGraph() // Returns a vector of strings loaded from file: graphs1.txt
{
   vector<string> lines;                 // Declares lines as a vector of strings
   ifstream file("./input/graphs1.txt"); // Open the file

   if (file.is_open()) // If the file is open
   {
      string line;                                // Declares line as a string
      while (getline(file, line))                 // For every line in the file
      {                                           // Read each line
         if (line.empty() || line.front() == '-') // If the line is empty or '-'
         {
            continue; // Skip all lines without data
         }
         // Non-skiped lines:
         lines.push_back(line); // Add line to vector
      }
      file.close(); // Close the file when complete
   }
   else // If the file is not open
   {
      cout << "Error opening file" << endl; // Log that the file did not open
   }
   return lines; // Return the vector of strings
}