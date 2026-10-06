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
    Node<object> *head = nullptr;
    Node<object> *tail = nullptr;
    // constructor
    circularLinkedList()
    {
    }

    void insertAtEnd(object value)
    {
        Node<object> *newNode = new Node<object>();

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
        Node<object> *newNode = new Node<object>();
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
        Node<object> *current = head;
        if (head == nullptr)
            return;
        else
        {
            do
            {
                Node<object> *victim = current;
                current = current->next; // move current one by one and delete that victim untill current is not equal to nullptr
                delete victim;
            } while (current != head);
            // at last it imp to specify head and tail to null
            head = nullptr;
            tail = nullptr;
        }
    }

    void insertAfterValue(object vlaue, object after)
    {
        Node<object> *newNode = new Node<object>();
        Node<object> *current = head;
        newNode->data = vlaue;

        if (head == nullptr)
            return;

        do
        {
            if (current->data == after)
            {
                if (current == tail)
                {
                    newNode->next = head; // circular link
                    tail = newNode;
                    current->next = newNode;
                    return;
                }
                newNode->next = current->next;
                current->next = newNode;
                return;
            }
            current = current->next;
        } while (current != head);
    }
    void insertBeforeValue(object value, object before)
    {
        Node<object> *newNode = new Node<object>();
        Node<object> *current = head;
        Node<object> *previous = nullptr;
        newNode->data = value;

        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
            tail->next = head;
            return;
        }
        do
        {
            if (current->data == before)
            {
                if (current == head)
                {
                    newNode->next = current;
                    head = newNode;
                    tail->next = head;
                    return;
                }
                newNode->next = current;
                previous->next = newNode;
                return;
            }
            previous = current;
            current = current->next;
        } while (current != head);
    }
    void deleteAtLast()
    {

        // 5 10 12 20

        Node<object> *current = head;
        Node<object> *previous = nullptr;
        do
        {
            if (current == tail) // current next will be 2ndd last node
            {
                Node<object> *victim = current;
                if (current == head)
                {
                    delete victim;
                    head = nullptr;
                    tail == nullptr;
                    return;
                }
                previous->next = head;
                delete victim;
                return;
            }
            previous = current;
            current = current->next;
        } while (current != head);
    }

    void deleteAfterValue(object target)
    {
        Node<object> *current = head;
        Node<object> *previous = nullptr;
        do
        {

            if (current->data == target)
            {
                if (current == tail)
                    return;

                Node<object> *victim = current->next;
                current->next = victim->next;
                delete victim;
                return;
            }
            previous = current;
            current = current->next;
        } while (current != head);
    }

    void printList()
    {
        Node<object> *current = head;
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
    list->insertAtStart(2);
    list->deleteAfterValue(20);
    list->printList();

    return 0;
}