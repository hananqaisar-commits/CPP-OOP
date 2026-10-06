#include <iostream>
using namespace std;
template <typename object>
struct Node
{
    object data;
    Node<object> *next;
};

template <typename object>
class circularLinkedList
{
public:
    Node<int> *head = nullptr;
    Node<int> *tail = nullptr;
    // constructor
    circularLinkedList()
    {
    }

    void insertAtEnd(object value)
    {
        Node<int> *newNode = new Node<int>();

        newNode->data = value;

        // if circularLinkedList is empty
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
            tail->next = head;
            return;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
            return;
        }
    }

    void insertAtStart(object value)
    {
        Node<int> *newNode = new Node<int>();
        newNode->data = value;

        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
            tail->next = head;
        }
        else
        {
            newNode->next = head;
            head = newNode;    // new head is the newNode
            tail->next = head; // now update the tail->next to the new Updated head
        }
    }
    void doublyClear()
    {
        Node<int> *current = head;
        Node<int> *victim = nullptr;
        if (head == nullptr)
            return;
        else
        {
            do
            {
                victim = current;
                current = current->next; // move current one by one and delete that victim untill current is not equal to nullptr
                delete victim;
            } while (current != head);
        }
    }
    void printList()
    {
        Node<int> *current = head;
        if (current == nullptr) // current is nullptr mean the list is empty so return empty from this point
            return;

        do
        {
            cout << current->data << " ";
            current = current->next;
        } while (current != head); // now check the condition that after printing the foirst node
    }
};
int main()
{
    circularLinkedList<int> *list = new circularLinkedList<int>();

    list->insertAtEnd(10);
    list->insertAtEnd(20);
    list->insertAtStart(5);
    list->doublyClear();
    list->printList();

    return 0;
}