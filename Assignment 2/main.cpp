// Algorithms ~ A. Labouseur, Assignment 2 - Connor Fleischman

/*
   shuffleItems.h: randomize()
   iostream: std::cout, std::endl
   iomanip: std::setprecision, std::fixed
*/

#include "shuffleItems.h"
#include <iostream>
#include <iomanip>

using namespace std;

vector<int> comparisonCount; // Declares the global comparisonCount vector of ints
vector<string> shuffled;     // Declares the global shuffled vector of strings

//  Record your results in a table in a LaTeX document along with your
//     code listings and documentation. Note the asymptotic running time
//     of each search and explain why it is that way.

string linearSearch(const vector<string> lines, const string key) // Defines the linear search function
{
   int numComparisons = 0; // Defines the number of comparisons to be 0

   for (int position = 0; position < lines.size(); ++position) // For every element in lines
   {
      numComparisons++; // Increment numComparisons

      if (lines[position] == key) // If the current element is the key
      {
         cout << "Number of comparisons: " << numComparisons << endl; // Print to console the number of comparisons
         comparisonCount.push_back(numComparisons);                   // Push this number to the comparison count vector
         return lines[position];                                      // Return the found item
      }
   }
   // If element is not found:
   comparisonCount.push_back(numComparisons); // Push 0 comparisons to count
   return "";                                 // Return nothing
}

string binarySearch(const vector<string> lines, const string key) // Defines the binary search function
{
   int start = 0;               // Defines the starting value
   int stop = lines.size() - 1; // Defines the stopping value (at end -1)
   int numComparisons = 0;      // Defines the number of comparisons to be 0

   while (start <= stop) // While the start is <= to stop
   {
      int middle = (start + stop) / 2; // The middle is split between the start and stop
      numComparisons++;                // Increment numComparisons

      if (lines[middle] == key) // If the middle element is the key
      {
         cout << "Number of comparisons: " << numComparisons << endl; // Print to console the number of comparisons
         comparisonCount.push_back(numComparisons);                   // Push this number to the comparison count vector
         return lines[middle];                                        // Return the found item
      }
      else if (lines[middle] < key) // If the middle element is less than the key
      {
         start = middle + 1; // Set the new stop to be one less than the middle (since element in bottom half)
      }
      else // If the middle element is greater than the key
      {
         stop = middle - 1; // Set the new start to be one more than the middle (since element in top half)
      }
   }
   // If element is not found:
   cout << "Number of comparisons: " << numComparisons << endl; // Print to console the number of comparisons
   comparisonCount.push_back(numComparisons);                   // Push 0 comparisons to count
   return "";                                                   // Return nothing
}

float averageComparisons() // Defines the method to compute the average number of comparisons
{
   int sum = 0;                           // Defines the sum as 0
   for (int comparison : comparisonCount) // For every comparison in comparisonCount
   {
      sum += comparison; // Set the sum as the sum + the current comparison
   }

   float average = static_cast<float>(sum) / comparisonCount.size();                          // Defines the average as a staticly cast float (sum / size of comparisonCount)
   cout << fixed << setprecision(2) << "Average comparisons per search: " << average << endl; // Print to console the average comparisons per search
   comparisonCount.clear();                                                                   // Clear's the comparison count for the next search

   return average; // Returns the average number of comparisons needed to find the elements for a given search
}

int main() // Defines the main function
{
   vector<string> keys = randomize().first;      // Defines the 42 key items being searched for
   vector<string> shuffled = randomize().second; // Defines the shuffled vector of items
   vector<int> comparisonCount(keys.size());     // Declares the vector's size to be the key's size

   for (int i = 0; i < keys.size(); i++) // For every key
   {
      linearSearch(shuffled, keys[i]); // Search the shuffled vector for that key using a linear search
   }
   averageComparisons(); // Calculate the average number of comparisons made

   for (int i = 0; i < keys.size(); i++) // for every key
   {
      binarySearch(shuffled, keys[i]); // Search the shuffled vector for that key using a binary search
   }
   averageComparisons(); // Calculate the average number of comparisons made

   return 0; // Return 0
}
