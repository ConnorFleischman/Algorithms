#include "Node.h"

class Stack
{
private:
    Node *top;

public:
    Stack()
    {
        top = nullptr;
    }

    void push(std::string item)
    {
        Node *newNode = new Node(item);
        newNode
    }
}