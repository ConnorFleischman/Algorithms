#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>

using namespace std;

std::vector<std::string> lines;       // Declares the lines a vector of strings
std::ifstream file("magicItems.txt"); // Opens and reads the file

void mergePartitions(std::vector<std::string> list, int m) // Merges a vector of strings, list, around a point, m
{
   std::string line; // Declares line as a string

   while (std::getline(file, line)) // While there is a new line in the file
   {
      lines.push_back(line); // Add the new line to the vector lines
   }

   file.close(); // Closes the file

   int i = 1;                        // set i = 1
   int j = m + 1;                    // set j = mergePoint + 1
   int n = list.size() - 1;          // set n = length(list) - 1
   std::vector<std::string> temp(n); // creates a new temporary vector with n elements

   for (int k = 1; k < n; k++) // for every element of list besides list
   {
      if (j > n) // if after the mergePoint > the n
      {
         temp[k].assign(list[i]); // assign the value at temp[k], list[i]
         i++;                     // Increment i
      }
      else if (i > m) // if i > the mergePoint
      {
         temp[k].assign(list[j]); // assign the value at temp[k], list[j]
         j++;                     // Increment j
      }
      else if (list[i] < list[j]) // if the element at i of list < the element at j of list
      {
         temp[k].assign(list[i]); // assign the value at temp[k], list[i]
         i++;                     // Increment i
      }
      else
      {
         temp[k].assign(list[j]); // assign the value at temp[k], list[j]
         j++;                     // Increment j
      }
   }

   for (int k = 1; k < n; k++) // for every element of list besides list
   {
      list[k].assign(temp[k]); // assign the value at list[k], temp[k]
   }

   temp.clear(); // clear temp
}

void mergeSort(std::vector<std::string> list) // Defines the mergeSort method taking a list to be sorted
{
   int n = list.size(); // n = the length of inserted list

   if (n > 1) // if the size of list is 2 or more
   {
      int m = floor(n / 2);                                               // m = floor of (n/2)
      std::vector<std::string> left(list.begin(), list.begin() + m);      // left = new vector<string> consisting of original list to m
      std::vector<std::string> right(list.begin() + (m + 1), list.end()); // right = new vector<string> consisting of list[m] to end of list

      mergeSort(left);  // recurse on left side
      mergeSort(right); // recurse on right side

      list.clear();                                        // clear the unsorted list
      list.reserve(left.size() + right.size());            // reserve space in unsorted list for sorted left and right
      list.insert(list.end(), left.begin(), left.end());   // insert items from left into list
      list.insert(list.end(), right.begin(), right.end()); // insert items from right into list

      mergePartitions(list, m); // merges all sublist around the merge point
   }

   for (int i = 1; i < n; i++)
   {
      std::swap(lines[i], list[i]); // Swap the positions of i and j
   }
}

std::vector<std::string> randomize() // Comprised of the function calls to shuffle the items
{
   mergeSort(lines); // Runs a merge sort over the items in magicItems.txt
   return lines;     // Returns the sorted vector "lines"
}
