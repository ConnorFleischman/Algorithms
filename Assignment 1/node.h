class Node
{
public:
    std::string data;
    Node *next;

    Node(std::string item)
    {
        data = item;
        next = nullptr;
    }
};