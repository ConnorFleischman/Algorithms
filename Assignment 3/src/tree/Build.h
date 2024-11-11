// Algorithms ~ A. Labouseur, Assignment 3 - Connor Fleischman

#include "Parse.h"

vector<string> buildLines()
{
   vector<string> lines = parseItems(); // Fill lines with the magic items
   return lines;                        // Return the vector lines
}

vector<string> buildKeys()
{
   vector<string> keys = parseKeys(); // Fill keys with the magic item keys
   return keys;                       // Return the vector keys
}
