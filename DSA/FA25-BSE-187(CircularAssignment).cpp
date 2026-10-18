#include <iostream>
using namespace std;

template <typename object>
struct Node
{
    object data;
    Node *next;
};
template <typename object>
class CircularLinkedList
{
public:
    Node<object> *head = nullptr;
    Node<object> *tail = nullptr;

    CircularLinkedList()
    {
        head = nullptr;
        tail = nullptr;
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

    void display()
    {
        Node<object> *current = head;
        if (head == nullptr)
            return;
        do
        {
            cout << current->data << "->";
            current = current->next;
        } while (current != head);
        cout << "nullptr\n";
    }
    void deleteNode(Node<object> *&found, Node<object> *&previous)
    {
        Node<object> *victim = found;
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

    object josephus(object k)
    {
        object count = 0;
        Node<object> *current = head;
        Node<object> *previous = tail;
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
                Node<object> *victim = current;
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

    void mainMenu()
    {
        int choice;

        do
        {
            cout << "\n===== CIRCULAR LINKED LIST MENU =====\n";
            cout << "1. Insert At End\n";
            cout << "2. Display List\n";
            cout << "3. Josephus Problem\n";
            cout << "4. Exit\n";
            cout << "Enter choice: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
            {
                object value;
                cout << "Enter value: ";
                cin >> value;

                insertAtEnd(value);
                break;
            }

            case 2:
                display();
                break;

            case 3:
            {
                if (head == nullptr)
                {
                    cout << "List is empty!\n";
                    break;
                }

                int k;
                cout << "Enter counting value (k): ";
                cin >> k;

                if (k <= 0)
                {
                    cout << "k must be greater than zero!\n";
                    break;
                }

                object survivor = josephus(k);
                cout << "Survivor: " << survivor << '\n';
                break;
            }

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
            }

        } while (choice != 4);
    }
};
int main()
{
    CircularLinkedList<int> *list = new CircularLinkedList<int>();

    list->insertAtEnd(10);
    list->insertAtEnd(20);
    list->insertAtEnd(30);
    list->insertAtEnd(40);
    list->insertAtEnd(50);
    list->insertAtEnd(60);
    list->insertAtEnd(70);

    list->mainMenu();

    delete list;
    return 0;
}