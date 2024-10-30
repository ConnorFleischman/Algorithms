#include "shuffleItems.h"
#include <iostream>
#include <utility>
#include <iomanip>

/*
   shuffleItems.h: randomize()
   iostream: std::cout, std::endl
   iomanip: std::setprecision, std::fixed

*/
std::vector<std::string> shuffled = randomize().first; // Defines the shuffled vector of items
std::vector<std::string> keys = randomize().second;    // Defines the 42 key items being searched for
std::vector<int> comparisonCount(keys.size());         // Defines a vector to calculate the average comparisons

// linear search
// binary search
//  count comparisons, compute overall average for each items (2 decimal places)
//  Record your results in a table in a LaTeX document along with your
//     code listings and documentation. Note the asymptotic running time
//     of each search and explain why it is that way.

std::string linearSearch(const std::vector<std::string> lines, const std::string key)
{
   int numComparisons = 0;

   for (int position = 0; position < lines.size(); ++position)
   {
      numComparisons++;

      if (lines[position] == key)
      {
         std::cout << "Number of comparisons: " << numComparisons << std::endl;
         comparisonCount.push_back(numComparisons);
         return lines[position];
      }
   }

   comparisonCount.push_back(numComparisons);
   return "";
}

std::string binarySearch(const std::vector<std::string> &lines, const std::string &key)
{
   int left = 0;
   int right = lines.size() - 1;
   int numComparisons = 0;

   while (left <= right)
   {
      int middle = left + (right - left) / 2;
      numComparisons++;

      if (lines[middle] == key)
      {
         std::cout << "Number of comparisons: " << numComparisons << std::endl; // Output when key is found
         comparisonCount.push_back(numComparisons);
         return lines[middle];
      }
      else if (lines[middle] < key)
      {
         left = middle + 1;
      }
      else
      {
         right = middle - 1;
      }
   }

   comparisonCount.push_back(numComparisons);
   return "";
}

int main()
{
   for (int i = 0; i < keys.size(); i++)
   {
      linearSearch(shuffled, keys[i]);
   }

   int sum = 0;
   for (int comparison : comparisonCount)
   {
      sum += comparison;
   }

   float average = static_cast<float>(sum) / comparisonCount.size();
   std::cout << std::fixed << std::setprecision(2) << "Average comparisons per search: " << average << std::endl;
   comparisonCount.clear();

   //------------------------

   for (int i = 0; i < keys.size(); i++)
   {
      binarySearch(shuffled, keys[i]);
   }

   sum = 0;
   for (int comparison : comparisonCount)
   {
      sum += comparison;
   }

   average = static_cast<float>(sum) / comparisonCount.size();
   std::cout << std::fixed << std::setprecision(2) << "Average comparisons per search: " << average << std::endl;
   comparisonCount.clear();

   return 0;
}
