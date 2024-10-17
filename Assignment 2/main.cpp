#include "shuffleItems.h"

std::vector<std::string> shuffled = randomize();                        // Defines the shuffled vector of items
std::vector<std::string> keys(shuffled.begin(), shuffled.begin() + 42); // Defines the 42 key items being searched for

// linear search
// binary search
//  count comparisons, compute overall average for each items (2 decimal places)
//  Record your results in a table in a LaTeX document along with your
//     code listings and documentation. Note the asymptotic running time
//     of each search and explain why it is that way.

std::string linearSearch(std::vector<std::string> lines, std::string key, )
{
   std::string x = lines.front();
   while (x != nullptr && x[item] != key)
   {
      x = x.next;
   }
   return x;
}

int main()
{
   return 0;
}