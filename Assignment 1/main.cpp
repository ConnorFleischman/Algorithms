#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <random>
#include <string>

std::vector<std::string> lines; // Declares lines a vector of strings

class Node // Defines the Node class
{
public:
    std::string data; // Identifying the data section of the node
    Node *next;       // and the pointer to the next node

    Node(std::string item) // Creates a node which takes in some item
    {
        this->data = item;    // Makes the item this nodes data
        this->next = nullptr; // Makes this nodes next point to null
    }
};

class Stack // Defines the Stack class
{
private:
    Node *top; // Identifying top as a Node

public:
    Stack() // Creates a Stack
    {
        top = nullptr; // with a pointer to the top
    }

    void push(std::string item) // Pushes an item into the stack
    {
        Node *newNode = new Node(item); // Creates a newNode of item
        newNode->next = top;            // Sets the item's next to previous's top
        top = newNode;                  // Sets the top to the new item
    }

    std::string pop() // Removes an item from top of stack
    {
        Node *temp = top;                   // Makes a temporary node to store top
        std::string toBePopped = top->data; // Creates toBePopped which is the data of the top element
        top = top->next;                    // Sets the new top to be the current top's next
        delete temp;                        // Deletes the old top
        return toBePopped;                  // Returns the old top's data
    }

    bool isEmpty() // Returns if the stack is empty
    {
        return top == nullptr; // if the top is empty, True
    }
};

class Queue // Defines the Queue class
{
private:
    Node *head; // Identifying the head as a Node
    Node *tail; // and the tail

public:
    Queue() // Creates a Queue
    {
        head = nullptr; // with a pointer to the head
        tail = nullptr; // and the tail
    }

    void enqueue(std::string item) // Queues an item to the queue
    {
        Node *newNode = new Node(item); // Creates a new node for the item
        if (isEmpty())                  // If the queue is empty
        {
            head = tail = newNode; // Let the head and tail both be a new node
        }
        else
        {
            tail->next = newNode; // Makes the next pointer of the current tail point to the item we are enqueueing
            tail = newNode;       // Sets the tail to the new node
        }
    }

    std::string dequeue()
    {
        Node *temp = head;                   // Creates a temporary node to store the current head
        std::string toBePopped = head->data; // Creates toBePopped which is the data of the current head element
        head = head->next;                   // Sets the new head to the the next pointer of the current head
        delete temp;                         // Deletes the current head
        return toBePopped;                   // Returns the dequeued data
    }
    bool isEmpty() // Returns if the queue is empty
    {
        return head == nullptr; // if the head is empty, True
    }
};

bool isPalindrome(const std::string line) // Defines the isPalindrome method
{
    Stack stack; // Implementing a stack
    Queue queue; // and a queue

    std::string parsedInput;
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
    int palindromeCount = 0;              // and a palindrome counter

    while (std::getline(file, line)) // While there is a new line in the file
    {
        if (isPalindrome(line)) // If the new line is a palindrome
        {
            palindromeCount++; // +1 palindrome
        }
    }

    file.close(); // Closes the file

    std::cout << "Number of palindromes: " << palindromeCount << std::endl; // Output the number of palindromes
}

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
        std::uniform_int_distribution<> distr(0, i); // Take a random number from 0 - i
        int j = distr(engine);                       // Set j as that number

        std::swap(lines[i], lines[j]); // Swap the positions of i and j
    }
}

void selectionSort() // Defines the selectionSort method
{
    int numComparisons = 0;         // The number of comparisons made
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
}

void insertionSort() // Defines the insertionSort method
{
    int numComparisons = 0;     // The number of comparisons made
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
}

void mergeSort() {} // Defines the mergeSort method

void quickSort() {} // Defines the quickSort method

void main() // // Defines the Main function
{
    calcPalindrome(); // Calling method to calculate # of palindromes in magicItems.txt
    shuffleItems();   // Shuffles the magic items
    selectionSort();  // Runs a selection sort over the randomized magic items vector
    shuffleItems();   // Shuffles the magic items
    insertionSort();  // Runs an insertion sort over the randomized magic items vector
}
