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
        Node<object> *previous = tail;
        if (head == nullptr)
            return;
        do
        {
            if (current == tail) // current next will be 2ndd last node
            {
                Node<object> *victim = current;
                if (current == head) // if it is bith head and tail then it mean it ios only one node
                {
                    head = nullptr;
                    tail = nullptr;
                    previous = nullptr;
                    delete victim;
                    return;
                }
                previous->next = head;
                tail = previous; // now this will be bew tail
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
        if (head == nullptr)
        {
            return;
        }
        do
        {
            if (current->data == target)
            {
                if (current == tail)
                    return;
                Node<object> *victim = current->next;
                if (victim == tail)
                {
                    tail = current; // now if the vivtim is tail then update the tail it is importnat
                }
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
        {
            head = victim->next;
        }
        if (victim == tail)
            tail = previous;
        delete victim;
    }

    int countList()
    {
        int size = 0;
        if (head == nullptr)
            return size;
        Node<object> *temp = head;
        do
        {
            size++;
            temp = temp->next;
        } while (temp != head);
        return size;
    }
    void deleteEvenDataNode()
    {
        Node<object> *current = head;
        Node<object> *previous = tail;
        int size = countList();

        for (int i = 0; i < size; i++)
        {
            if (current->data % 2 == 0) // if the current node is even then delete taht node and move current to next
            {                           // otherwise move the current to next and maintain previous node also
                Node<object> *next = current->next;
                deleteNode(current, previous);
                // after deletion if list empty then
                if (head == nullptr)
                {
                    break;
                }
                current = next;
            }
            else
            {
                previous = current;
                current = current->next;
            }
        }
    }
    void deleteOddDataNode()
    {
        Node<object> *current = head;
        Node<object> *previous = tail;

        int size = countList();

        for (int i = 0; i < size; i++)
        {
            if (current->data % 2 != 0)
            {
                Node<object> *next = current->next;
                deleteNode(current, previous);
                if (head == nullptr) // if list is empty then return
                {
                    break;
                }
                current = next;
            }
            else
            {
                previous = current;
                current = current->next;
            }
        }
    }

    int josephus(object k)
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

    void deleteEvenNodes()
    {
        Node<object> *current = head;
        Node<object> *previous = tail;
        int position = 0;
        do
        {
            position++;
            if (head == nullptr)
            {
                break;
            }
            // 1,2,3,4,5,6,7
            if (position % 2 == 0)
            {
                Node<object> *next = current->next;
                deleteNode(current, previous);
                current = next;
            }
            else
            {
                previous = current;
                current = current->next;
            }

        } while (current != head);
    }

    void menu()
    {
        int choice;

        cout << "\n===== Circular Linked List Menu =====\n";
        cout << "1. Insert At End\n";
        cout << "2. Insert At Start\n";
        cout << "3. Insert After Value\n";
        cout << "4. Insert Before Value\n";
        cout << "5. Delete At Last\n";
        cout << "6. Delete After Value\n";
        cout << "7. Delete Even Data Nodes\n";
        cout << "8. Delete Odd Data Nodes\n";
        cout << "9. Delete Even Position Nodes\n";
        cout << "10. Josephus\n";
        cout << "11. Clear List\n";
        cout << "12. Print List\n";
        cout << "13. Count List\n";
        cout << "0. Exit\n";

        cout << "\nEnter your choice: ";
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
        {
            object value;
            cout << "Enter value: ";
            cin >> value;
            insertAtStart(value);
            break;
        }

        case 3:
        {
            object value, after;
            cout << "Enter value: ";
            cin >> value;
            cout << "Enter value after which to insert: ";
            cin >> after;
            insertAfterValue(value, after);
            break;
        }

        case 4:
        {
            object value, before;
            cout << "Enter value: ";
            cin >> value;
            cout << "Enter value before which to insert: ";
            cin >> before;
            insertBeforeValue(value, before);
            break;
        }

        case 5:
            deleteAtLast();
            break;

        case 6:
        {
            object target;
            cout << "Enter target value: ";
            cin >> target;
            deleteAfterValue(target);
            break;
        }

        case 7:
            deleteEvenDataNode();
            break;

        case 8:
            deleteOddDataNode();
            break;

        case 9:
            deleteEvenNodes();
            break;

        case 10:
        {
            object k;
            cout << "Enter k: ";
            cin >> k;
            cout << "Josephus survivor: " << josephus(k) << endl;
            break;
        }

        case 11:
            doublyClear();
            break;

        case 12:
            printList();
            cout << endl;
            break;

        case 13:
            cout << "Total nodes: " << countList() << endl;
            break;

        case 0:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }
    }
};

int main()
{
    circularLinkedList<int> *list = new circularLinkedList<int>();
    list->menu();
    return 0;
}