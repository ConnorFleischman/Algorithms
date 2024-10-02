// Algorithms ~ A. Labouseur, Assignment 1 - Connor Fleischman

/*
    iostream: std::cout, std::endl
    fstream: std::ifstream, std::getline, file.open, file.close
    vector: std::vector, lines.push_back, lines.size, lines.clear, lines.shrink_to_fit, lines.reserve, lines.insert
    algorithm: std::swap
    random: std::random_device, std::default_random_engine, std::uniform_int_distribution
    string: std::string, std::isalnum, std::tolower, parsedInput.push_back, std::getline
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <random>
#include <string>

using namespace std; // Declaring the name space to use std::_

class Node // Defines the Node class
{
public:
    std::string data; // Identifies the data section of the node
    Node *next;       // Identifies the pointer to the next node

    Node(std::string item) // Creates a node which takes in some item
    {
        this->data = item;    // Sets this node's data point to item
        this->next = nullptr; // Sets this node's next point to null
    }
};

class Stack // Defines the Stack class
{
private:
    Node *top; // Identifies top as a Node

public:
    Stack() // Creates a Stack
    {
        top = nullptr; // Sets top to a null pointer
    }

    void push(std::string item) // Enters an item into the stack
    {
        Node *newNode = new Node(item); // Creates a newNode for the item
        newNode->next = top;            // Sets the newNode's next to previous' top
        top = newNode;                  // Sets the new top to the newNode
    }

    std::string pop() // Removes an item from the top of the stack
    {
        Node *temp = top;                   // Creates a temporary node to store the top
        std::string toBePopped = top->data; // Creates toBePopped which is the data of the top element

        top = top->next; // Sets the new top to what the current top's next pointer is
        delete temp;     // Deletes the old top

        return toBePopped; // Returns the old top's data
    }

    bool isEmpty() // Returns if "the stack is empty" is true
    {
        return top == nullptr; // If the top points to null return True
    }
};

class Queue // Defines the Queue class
{
private:
    Node *head; // Identifies the head as a Node
    Node *tail; // Identifies the tail as a Node

public:
    Queue() // Creates a Queue
    {
        head = nullptr; // Sets head to a null pointer
        tail = nullptr; // Sets tail to a null pointer
    }

    void enqueue(std::string item) // Enters an item to the queue
    {
        Node *newNode = new Node(item); // Creates a new node for the item

        if (isEmpty()) // If the queue is empty
        {
            head = tail = newNode; // Set the head and tail both to be newNodes
        }
        else
        {
            tail->next = newNode; // Set the tail's next pointer to the newNode
            tail = newNode;       // Set the tail to the newNode
        }
    }

    std::string dequeue() // Removes an item from the front of the queue
    {
        Node *temp = head;                   // Creates a temporary node to store the current head
        std::string toBePopped = head->data; // Creates toBePopped which is the data of the current head element

        head = head->next; // Sets the new head to the the next pointer of the current head
        delete temp;       // Deletes the current head

        return toBePopped; // Returns the dequeued data
    }
    bool isEmpty() // Returns if 'queue is empty' is true
    {
        return head == nullptr; // If the head points to null return True
    }
};

bool isPalindrome(const std::string line) // Defines the isPalindrome method
{
    Stack stack; // Implements a stack
    Queue queue; // Implements a queue

    std::string parsedInput; // Creates a variable to hold the parsed input of a line

    for (char n : line) // For n in line
    {
        if (std::isalnum(n)) // Checking if character n is alphanumeric
        {
            char lowerChar = std::tolower(n); // Converts character n to lowercase
            parsedInput.push_back(lowerChar); // Sets parsedInput as alphanumeric lowercase
        }
    }

    for (char n : parsedInput) // For n in parsedInput
    {
        std::string firstChar(1, n); // Let n be the first character
        stack.push(firstChar);       // Push the nth character of the line on the stack
        queue.enqueue(firstChar);    // Queue nth character
    }

    while (!stack.isEmpty() && !queue.isEmpty()) // While the stack and queue are not empty
    {
        if (stack.pop() != queue.dequeue()) // If the word forwards (stack) is not equal to the word backwards (queue)
        {
            return false;
        }
    }

    return true;
}

void calcPalindrome() // Defines the calcPalindrome method
{
    std::ifstream file("magicItems.txt"); // Opens and reads the file
    std::string line;                     // Defines a line
    int palindromeCount = 0;              // Defines a palindrome counter

    while (std::getline(file, line)) // While there is a new line in the file
    {
        if (isPalindrome(line)) // If the new line is a palindrome
        {
            palindromeCount++; // Increment palindromeCount
        }
    }

    file.close(); // Closes the file

    std::cout << "Number of palindromes: " << palindromeCount << std::endl; // Output the number of palindromes
}

std::vector<std::string> lines; // Declares the lines a vector of strings
int numComparisons = 0;         // Declares the number of comparisons made

void shuffleItems() // Defines the shuffleItems method
{
    std::ifstream file("magicItems.txt"); // Opens and reads the file
    std::string line;                     // Declares line as a string

    while (std::getline(file, line)) // While there is a new line in the file
    {
        lines.push_back(line); // Add the new line to the vector lines
    }

    file.close(); // Closes the file

    std::random_device randNum;                   // Creates a random number generator
    std::default_random_engine engine(randNum()); // "Seeds" the random number (essentially starting it)

    for (int i = lines.size() - 1; i > 0; i--) // For every item in the lines vector except the last
    {
        std::uniform_int_distribution<int> distr(0, i); // Take a random number from 0 - i
        int j = distr(engine);                          // Set j as that number

        std::swap(lines[i], lines[j]); // Swap the positions of i and j
    }
}

void selectionSort() // Defines the selectionSort method
{
    int n = lines.size();           // n = the length of the lines vector
    for (int i = 0; i < n - 1; i++) // For every item in the vector
    {
        int toCompare = i;              // Sets the item to be compared to to i
        for (int j = i + 1; j < n; j++) // For every item j in lines after i
        {
            numComparisons++;                // Increment numComparisons
            if (lines[j] < lines[toCompare]) // If the next item in lines is less than the item being compared
            {
                toCompare = j; // Set the new item to be compared to to j
            }
        }

        std::swap(lines[i], lines[toCompare]); // Swap the positions of the previously compared element and the current
    }
    std::cout << "Number of comparisons: " << numComparisons << std::endl; // Output the number of comparisons

    lines.clear();         // Clears the sorted vector
    lines.shrink_to_fit(); // Shrinks the size of the vector to the number of items in it, 0
}

void insertionSort() // Defines the insertionSort method
{
    int n = lines.size();       // n = the length of lines vector
    for (int i = 1; i < n; i++) // For every item i in the vector
    {
        int j = i;                               // Let j = i
        while (j > 0 && lines[j - 1] > lines[j]) // While j > 0 and the previous element is larger than the current
        {
            numComparisons++;                  // Increment numComparisons
            std::swap(lines[j], lines[j - 1]); // Swap the positions of the current and previous elements
            j--;                               // Decrement j
        }
    }
    std::cout << "Number of comparisons: " << numComparisons << std::endl; // Output the number of comparisons

    lines.clear();         // Clears the sorted vector
    lines.shrink_to_fit(); // Shrinks the size of the vector to the number of items in it, 0
}

void mergePartitions(std::vector<std::string> list, int m) // Merges a vector of strings, list, around a point, m
{
    int i = 1;                        // set i = 1
    int j = m + 1;                    // set j = mergePoint + 1
    int n = list.size() - 1;          // set n = length(list) - 1
    std::vector<std::string> temp(n); // creates a new temporary vector with n elements

    for (int k = 1; k < n; k++) // for every element of list besides list
    {
        numComparisons++; // Increment numComparisons
        if (j > n)        // if after the mergePoint > the n
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
}

int quickPartitions(std::vector<std::string> list, int p) // Partitions a vector of strings, list, around a point, p
{
    int n = list.size() - 1;     // sets n to the size of the list - 1
    std::swap(list[p], list[n]); // swaps the position of p and n in list
    int l = 0;                   // sets l = 0

    for (int i = 1; i < (n - 1); i++) // for every element in the list
    {
        numComparisons++;      // Increment numComparisons
        if (list[i] < list[n]) // if the element at list[i] < the element at list[j]
        {
            l++;                         // Increment l
            std::swap(list[l], list[i]); // swaps the position of l and i in the list
        }
    }

    std::swap(list[n], list[l + 1]); // swaps the position of n and l + 1 in the list

    return l + 1; // returns l + 1
}

void quickSort(std::vector<std::string> list) // Defines the quickSort method
{
    int n = list.size(); // n = the length of inserted list

    if (n > 1) // if the size of list is 2 or more
    {
        std::random_device randNum;                         // Creates a random number generator
        std::default_random_engine engine(randNum());       // "Seeds" the random number (essentially starting it)
        std::uniform_int_distribution<int> distr(0, n - 1); // Take a random number from 0 - (n-1)
        int p = distr(engine);                              // Set p as that number

        int r = quickPartitions(list, p);                                    // make r the partitioned element of list at p
        std::vector<std::string> left(list.begin(), list.begin() + (r - 1)); // left = new vector<string> consisting of original list to (r - 1)
        std::vector<std::string> right(list.begin() + (r + 1), list.end());  // right = new vector<string> consisting of original list[(r - 1)] to end of list

        quickSort(left);  // recurse on left side
        quickSort(right); // recurse on right side

        list.clear();                                        // clear the unsorted list
        list.reserve(left.size() + right.size());            // reserve space in unsorted list for sorted left and right
        list.insert(list.end(), left.begin(), left.end());   // insert items from left into list
        list.insert(list.end(), right.begin(), right.end()); // insert items from right into list
    }
}

int main() // Comprised of the function calls for Assignment 1
{
    calcPalindrome(); // Calculates the number of palindromes in magicItems.txt

    numComparisons = 0; // Resets the comparison counter
    shuffleItems();     // Shuffles magicItems.txt using the Knuth Shuffle
    selectionSort();    // Runs a selection sort over the items in magicItems.txt

    numComparisons = 0; // Resets the comparison counter
    shuffleItems();     // Shuffles magicItems.txt using the Knuth Shuffle
    insertionSort();    // Runs an insertion sort over the items in magicItems.txt

    lines.clear();                                                         // Empties the lines vector for the next sort
    numComparisons = 0;                                                    // Resets the comparison counter
    shuffleItems();                                                        // Shuffles magicItems.txt using the Knuth Shuffle
    mergeSort(lines);                                                      // Runs a merge sort over the items in magicItems.txt
    std::cout << "Number of comparisons: " << numComparisons << std::endl; // Outputs the number of comparisons preformed

    lines.clear();                                                         // Empties the lines vector for the next sort
    numComparisons = 0;                                                    // Resets the comparison counter
    shuffleItems();                                                        // Shuffles magicItems.txt using the Knuth Shuffle
    quickSort(lines);                                                      // Runs a quick sort over the items in magicItems.txt
    std::cout << "Number of comparisons: " << numComparisons << std::endl; // Outputs the number of comparisons preformed

    numComparisons = 0; // Resets the comparison counter

    return 0; // Finishes main method
}
