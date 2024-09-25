#include <fstream>
#include <string>

class Node
{
public:
    std::string data;
    Node *next;

    Node(std::string item)
    {
        this->data = item;
        this->next = nullptr;
    }
};

class Stack
{
private:
    Node *top;

public:
    Stack()
    {
        top = nullptr;
    }

    void push(std::string item) // Pushes an item into the stack
    {
        Node *newNode = new Node(item); // Creates a newNode of an item
        newNode->next = top;            // Sets the item's 'next' to prev.'s 'top'
        top = newNode;                  // Sets the top to the new item
    }

    std::string pop() // Removes an item from top of stack
    {
        Node *temp = top;                   // Makes a temporary value to store top
        std::string toBePopped = top->item; // Creates toBePopped which is the 'data' of the top element
        top = top->next;                    // Sets the new top to be the current top's 'next'
        delete temp;                        // Deletes the "old" top
        return toBePopped;                  // Returns the old top's 'data'
    }

    bool isEmpty() // Returns if the stack is empty
    {
        return top == nullptr;
    }
};

class Queue
{
private:
    Node *head;
    Node *tail;

public:
    Queue()
    {
        head = nullptr;
        tail = nullptr;
    }

    void enqueue(std::string item)
    {
        Node *newNode = new Node(item);
    }
};

void sort()
{
    std::ifstream file("magicItems.txt")
}

void main() {}