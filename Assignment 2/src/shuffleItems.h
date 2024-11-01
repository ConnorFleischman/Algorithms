#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> lines;            // Declares the lines a vector of strings
vector<string> keys;             // Declares keys a vector of strings
ifstream file("magicItems.txt"); // Opens and reads the file

vector<string> insertionSort() // Defines the insertionSort method
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

pair<vector<string>, vector<string>> randomize() // Comprised of the function calls to shuffle the items
{
   string line; // Declares line as a string

   while (getline(file, line)) // While there is a new line in the file
   {
      lines.push_back(line); // Add the new line to the vector lines
   }

   file.close(); // Closes the file

   srand(static_cast<unsigned int>(time(0))); // Seeds the random number generator with the time
   int start = rand() % 625;                  // Declares start as a random number between 1-625 (allowing for key space and out of bounds)

   for (int i = 0; i < 42; i++) // For 42 keys
   {
      keys.push_back(lines[i + start]); // Select the keys as 42 consecutive strings at some distance from the beginning of the list
   }

   return make_pair(keys, insertionSort()); // Returns the sorted vector "lines"
}
