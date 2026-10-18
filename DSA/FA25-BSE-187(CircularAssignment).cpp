#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};
class CircularLinkedList
{
public:
    Node *head = nullptr;
    Node *tail = nullptr;

    CircularLinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }
    void insertAtEnd(int value)
    {
        Node *current = head;
        Node *newNode = new Node();
        newNode->data = value;

        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
            tail->next = head;
            return;
        }
        tail->next = newNode;
        tail = newNode;
        tail->next = head;
    }

    void display()
    {
        Node *current = head;
        if (head == nullptr)
            return;
        do
        {
            cout << current->data << "->";
            current = current->next;
        } while (current != head);
        cout << "nullptr\n";
    }
    void deleteNode(Node *&found, Node *&previous)
    {
        Node *victim = found;
        // if there is one node and that node is the victiim
        if (victim == head && victim == tail)
        {
            head = nullptr;
            tail = nullptr;
            delete victim;
            return;
        }
        previous->next = found->next;
        // now handle head and tail
        if (victim == head)
            head = victim->next;

        if (victim == tail)
            tail = previous;
        delete victim;
    }

    int josephus(int k)
    {
        int count = 0;
        Node *current = head;
        Node *previous = tail;
        while (true)
        {
            if (head == nullptr)
            {
                return 0;
            }
            if (current->next == current) // if cycle is detected then return that data node
            {
                return current->data;
            }
            // 1,2,3,4,5,6,7
            count++;
            if (count == k)
            {
                Node *victim = current;
                current = victim->next; // now the current starts from kth+1 node
                count = 0;              // reset the count to 0
                deleteNode(victim, previous);
            }
            else
            {
                previous = current;
                current = current->next;
            }
        }
    }
};
int main()
{

    CircularLinkedList *list = new CircularLinkedList();

    list->insertAtEnd(10);
    list->insertAtEnd(20);
    list->insertAtEnd(30);

    list->josephus(2);
    list->display();

    return 0;
}