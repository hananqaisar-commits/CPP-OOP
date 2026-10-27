#include <iostream>
using namespace std;

struct Node
{
    int data;
    int priority;
    Node *next;
};
class Qeue
{
public:
    Node *head = nullptr;
    Node *tail = nullptr;

    Qeue()
    {
        head = nullptr;
        tail = nullptr;
    }

    Node *peek()
    {
        return tail;
    }
    void enqeue(int value, int priorityLevel)
    {
        Node *newNode = new Node();
        Node *previous = nullptr;

        newNode->data = value;
        newNode->priority = priorityLevel;

        if (head == nullptr || priorityLevel < head->priority)
        {
            newNode->next = head;
            head = newNode;

            if (tail == nullptr)
                tail = newNode;

            return;
        }
        Node *current = head;
        while (current->next != nullptr && current->next->priority <= priorityLevel) // bcz the first node is pushed automatically so no need to chect that
        {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;

        if (newNode->next == nullptr) // if ther is tailthen assign last node tai;
            tail = newNode;
    }

    void display()
    {
        Node *current = head;
        while (current != nullptr)
        {
            cout << current->data << " " << current->priority << " ";
            current = current->next;
        }
    }
};
int main()
{
    Qeue *q = new Qeue();
    q->enqeue(10, 1);
    q->enqeue(30, 3);
    q->enqeue(20, 2);
    q->enqeue(40, 4);
    q->enqeue(50, 1);

    q->display();

    return 0;
}