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
      while (std::getline(file, line))       // For every line in the file
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

// Spices/Knapsack parse functions:
std::vector<std::string> parseInstructions() // Parse the data from spice.txt into a vector of strings
{
   std::vector<std::string> instructions;   // Declare vector of strings to hold instructions
   std::ifstream file("./input/spice.txt"); // Read and open the file

   if (file.is_open()) // If the file is open
   {
      std::string line;                // Placeholder for current line
      while (std::getline(file, line)) // While there is a line in the file
      {
         if (line.empty() || line.front() == '-') // If the line is empty or a comment
         {
            continue; // Skip
         }
         // For remaining lines:
         instructions.push_back(line);
      }
   }
   else // If the file is not open
   {
      std::cout << "Error opening file" << std::endl;
   }
   return instructions;
}

std::vector<std::string> parseLine(std::string &line) // Parse the instruction into its subinstructions
{
   std::vector<std::string> instructions; // List of instructions in this line
   std::string command;                   // Placeholder for current command
   bool equalSign = false;                // Flag to track if passed '='

   for (char c : line) // For every character in the instruction
   {
      if (c == ';') // If the end of the command is reached
      {
         instructions.push_back(command); // Push the command back to the list
         command.clear();                 // Clear the command placeholder
         equalSign = false;               // Reset the flag
      }
      else // If the end of the command has not ended
      {
         if (!equalSign) // If the flag is not set
         {
            if (c == '=') // If the current char is '='
            {
               equalSign = true; // Set the flag
            }
         }
         else // If the flag is set
         {
            if (!isspace(c)) // If the char is not a space
            {
               command += c; // Add it to the command
            }
         }
      }
   }
   // After every command in the instruction has been read
   return instructions;
}

#endif