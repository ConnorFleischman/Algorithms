// Algorithms ~ A. Labouseur, Assignment 3 - Connor Fleischman

#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <algorithm>

using namespace std; // Globally used namespace (removes use of std::)

vector<string> sort(vector<string> lines) // Defines the insertionSort method
{
   int n = lines.size();       // n = the length of lines vector
   for (int i = 1; i < n; i++) // For every item i in the vector other than the first
   {
      int j = i;                      // Let j = i
      while (lines[j - 1] > lines[j]) // While the previous element is larger than the current
      {
         swap(lines[j], lines[j - 1]); // Swap the positions of the current and previous elements
         j--;                          // Decrement j
      }
   }
   return lines; // Returns the sorted array
}