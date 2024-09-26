#include <fstream>
#include <string>

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
