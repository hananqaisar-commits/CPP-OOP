#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};
class List
{
public:
    Node *head = nullptr;
    Node *tail = nullptr;

    bool search(Node *&n1, Node *&n2)
    {
        Node *current = head;
        int found = 0;
        while (current != nullptr)
        {

            if (current->data == n1->data || current->data == n2->data)
                found++;

            current = current->next;
        }
        return found == 2;
    }
    void push(int value)
    {
        Node *newNode = new Node();
        newNode->data = value;
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
            return;
        }

        tail->next = newNode;
        newNode->next = nullptr;
        tail = newNode;
    }

    void display()
    {
        Node *current = head;

        while (current != nullptr)
        {
            cout << current->data << "->";
            current = current->next;
        }
        cout << "nullptr\n";
    }
    void swapTwoNodes(Node *n1, Node *n2)
    {
        Node *n1Next = n1->next;
        Node *n2Next = n2->next;

        Node *n1Prev = nullptr;
        Node *n2Prev = nullptr;
        if (search(n1, n2))
        {

            Node *current = head;
            while (current != nullptr)
            {
                if (current->next == n1)
                    n1Prev = current;
                else if (current->next == n2)
                    n2Prev = current;

                current = current->next;
            }
            if (n1->next == n2) // if it is adjacent
            {
                if (n1Prev != nullptr)
                    n1Prev->next = n2;
                n1->next = n2Next;
                n2->next = n1;
            }
            else if (n2->next == n1)
            {
                n2->next = n1->next;
                n1->next = n2;
                if (n2Prev != nullptr)
                    n2Prev->next = n1;
            }
            else
            {
                // now change the links
                n1->next = n2Next;
                n2->next = n1Next;
                if (n1Prev != nullptr)
                    n1Prev->next = n2;
                if (n2Prev != nullptr)
                    n2Prev->next = n1;
            }
        }

        if (n1 == head)
            head = n2;
        else if (n2 == head)
            head = n1;
        if (n1 == tail)
            tail = n2;
        else if (n2 == tail)
            tail = n1;
    }
};
int main()
{
    List *list = new List();

    list->push(10);
    list->push(20);
    list->push(30);
    list->push(40);
    list->push(50);

    list->swapTwoNodes(list->head, list->head->next);
    list->display();
}