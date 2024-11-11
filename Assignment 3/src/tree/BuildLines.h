// Algorithms ~ A. Labouseur, Assignment 3 - Connor Fleischman

#include "SortItems.h"
#include "Parse.h"

vector<string> buildLines()
{
   vector<string> lines = parse(); // Fill lines with the magic items
   return sort(lines);             // Return the sorted vector lines
}
