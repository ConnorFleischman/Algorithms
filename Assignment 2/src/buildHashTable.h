#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std; // Declaring the name space to use std::_

const int HASH_TABLE_SIZE = 250; // Declares the hash table's size

void readFileIntoVector(vector<string> &vector) // Function to read the file to a vector of strings
{
   string line;                           // Defines a line
   ifstream fileStream("magicItems.txt"); // Reads and opens the file
   while (getline(fileStream, line))      // While there is a new line in the file
   {
      vector.push_back(line); // Push the string on that line into the vector of strings
   }
   fileStream.close(); // Close the file
}

int makeHashCode(const string &item) // Function to take an item and turn it into it's ASCII value
{
   int letterTotal = 0;        // Defines the letter total as 0
   for (const char &ch : item) // For every character in the item
   {
      letterTotal += toupper(ch); // Add its uppercase ASCII value to the total
   }
   return letterTotal % HASH_TABLE_SIZE; // Return the letter total `mod` hash table size to get its bucket
}

void buildTable(const vector<string> &items, vector<vector<string>> &hashTable) // Function to build the hash table
{
   for (const string &item : items) // For each item in the vector of strings
   {
      int hashCode = makeHashCode(item);   // Find the hash code for that item
      hashTable[hashCode].push_back(item); // Insert item into correct bucket based on the hash code ASCII value
   }
}

vector<vector<string>> createTable() // Function to create the table (used by main.cpp)
{
   vector<string> magicItems;                         // Declares the vector of strings to store the magic items
   readFileIntoVector(magicItems);                    // Populates the vector
   vector<vector<string>> hashTable(HASH_TABLE_SIZE); // Declares a hash table comprised of a vector of vectors of strings with fixed size of 250
   buildTable(magicItems, hashTable);                 // Build hash table with the table and the vector of strings for buckets
   magicItems.clear();                                // Empties the magic items

   return hashTable; // Returns the hash table
}
