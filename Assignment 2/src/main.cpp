// Algorithms ~ A. Labouseur, Assignment 2 - Connor Fleischman

/*
   buildHashTable.h: createTable()
   sortItems.h: sort().first/.second, KEYS_SIZE
   iostream: std::cout, std::endl
   iomanip: std::setprecision, std::fixed
*/

#include "buildHashTable.h"
#include "sortItems.h"
#include <iostream>
#include <iomanip>

using namespace std; // Globally used namespace

int comparisonCount = 0;          // Declares comparisonCount as 0 to store the total number of comparisons made for a search
vector<string> sorted;            // Declares the global sorted vector of strings
vector<vector<string>> hashTable; // Declares a hash table comprised of a vector of vectors of strings

string linearSearch(const vector<string> &lines, const string &key) // Defines the linear search function
{
   int numComparisons = 0; // Defines the number of comparisons to be 0

   for (int position = 0; position < lines.size(); ++position) // For every element in lines
   {
      numComparisons++; // Increment numComparisons

      if (lines[position] == key) // If the current element is the key
      {
         cout << "Number of comparisons: " << numComparisons << endl; // Print to console the number of comparisons
         comparisonCount += numComparisons;                           // Increment comparison count with the number of comparisons made to find keu
         return lines[position];                                      // Return the found item
      }
   }
   // If element is not found:
   cout << "[NF] Number of comparisons: " << numComparisons << endl; // Print to console the number of comparisons
   comparisonCount += numComparisons;                                // Increment comparison count with the number of comparisons made to find keu
   return "";                                                        // Return nothing
}

string binarySearch(const vector<string> &lines, const string &key) // Defines the binary search function
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
         comparisonCount += numComparisons;                           // Increment comparison count with the number of comparisons made to find keu
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
   cout << "[NF] Number of comparisons: " << numComparisons << endl; // Print to console the number of comparisons
   comparisonCount += numComparisons;                                // Increment comparison count with the number of comparisons made to find keu
   return "";                                                        // Return nothing
}

float averageComparisons() // Defines the method to compute the average number of comparisons
{
   float average = static_cast<float>(comparisonCount) / KEYS_SIZE;                           // Defines the average as a staticly cast float (comparisonCount / # of keys (defined in shuffleItems.h))
   cout << fixed << setprecision(2) << "Average comparisons per search: " << average << endl; // Print to console the average comparisons per search
   comparisonCount = 0;                                                                       // Reset's the comparison count for the next search

   return average; // Returns the average number of comparisons needed to find the elements for a given search
}

string searchItem(const string &item) // Defines the function to search an item in the hash table
{
   int numComparisons = 0; // Defines the number of comparisons to be 0

   int hashCode = makeHashCode(item);                   // Defines the hash code for an item
   for (const string &storedItem : hashTable[hashCode]) // For every item in the hash table with the same hash code value as the item to be found
   {
      numComparisons++;       // Increment numComparisons
      if (storedItem == item) // If the item to be found is equal to the sorted item
      {
         cout << "Number of comparisons: " << numComparisons << endl; // Print to console the number of comparisons
         comparisonCount += numComparisons;                           // Increment comparison count with the number of comparisons made to find keu
         return storedItem;                                           // True = found
      }
   }
   // If element is not found:
   cout << "[NF] Number of comparisons: " << numComparisons << endl; // Print to console the number of comparisons
   comparisonCount += numComparisons;                                // Increment comparison count with the number of comparisons made to find keu
   return "";                                                        // False = not found
}

int main() // Defines the main function
{
   vector<string> keys = sort().first; // Defines the 42 key items being searched for (from shuffleItems.h)
   sorted = sort().second;             // Defines the sorted vector of items (from shuffleItems.h)

   for (const string &key : keys) // For every key
   {
      linearSearch(sorted, key); // Search the sorted vector for that key using a linear search
   }
   averageComparisons(); // Calculate the average number of comparisons made

   for (const string &key : keys) // for every key
   {
      binarySearch(sorted, key); // Search the sorted vector for that key using a binary search
   }
   averageComparisons(); // Calculate the average number of comparisons made

   sorted.clear();            // Empties the sorted vector
   hashTable = createTable(); // Builds a hash table (from buildHashTable.h) to hashTable

   for (const string &key : keys) // For every key
   {
      searchItem(key); // Search the hash table for that key
   }
   averageComparisons(); // Calculate the average number of comparisons made

   comparisonCount = 0; // Reset's the comparison count
   keys.clear();        // Empties the keys
   hashTable.clear();   // Empties the hash table

   return 0; // Return 0
}
