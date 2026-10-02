#include <iostream>
using namespace std;

template <typename object>
class LinkedList
{
public:
    struct Node
    {
        object data;
        Node *next;
        Node *previous;
    };
    struct singlyNode
    {
        object data;
        singlyNode *next;
    };

    singlyNode *singlyHead = new singlyNode();

    Node *head = new Node();
    Node *tail = new Node();

    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    void insertNodeAtLast(object data)
    {
        Node *newNode = new Node();
        newNode->data = data;
        newNode->next = nullptr;
        newNode->previous = nullptr;

        Node *current = head;

        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->previous = tail;
        tail = newNode;
    }

    void
    printLinkedlist()
    {
        Node *current = head;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
    }

    void insertBeforeNode(object target, object value)
    {
        Node *current = head;
        Node *newNode = new Node();

        newNode->data = value;
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;

            newNode->next = nullptr;
            newNode->previous = nullptr;

            return;
        }
        while (current != nullptr)
        {
            if (head->data == target)
            {
                newNode->next = current;
                head->previous = newNode;
                head = newNode;
                head->previous = nullptr;
                return;
            }

            if (current->data == target)
            {
                newNode->next = current;
                newNode->previous = current->previous;
                current->previous->next = newNode;
                current->previous = newNode;
                return;
            }
            current = current->next;
        }
    }

    void deleteNode(object target)
    {
        Node *victim = nullptr;
        Node *current = head;

        if (head == nullptr)
        {
            return;
        }

        while (current != nullptr)
        {
            if (current->data == target)
            {
                if (current == head)
                {
                    if (head->next == nullptr)
                    {
                        delete current; // delete current and now list become empty now head and tail will be null
                        head = nullptr;
                        tail = nullptr;

                        return;
                    }

                    victim = current;
                    head = current->next;
                    head->previous = nullptr;

                    delete victim;
                    return;
                }
                if (current == tail)
                {
                    victim = current;

                    tail = current->previous;
                    tail->next = nullptr;

                    delete victim;
                    return;
                }
                victim = current;
                current->next->previous = current->previous;
                current->previous->next = current->next;

                delete victim;
                return;
            }
            current = current->next;
        }
    }
    void clearList()
    {
        Node *current = head;
        Node *temp = nullptr;
        while (current != nullptr)
        {
            if (current->next == nullptr)
            {

                delete current;
                head = nullptr;
                tail = nullptr;

                return;
            }

            temp = current;
            current = current->next;

            delete temp;
        }
    }
    void deleteBeforeValue(object target)
    {
        Node *current = head;
        Node *temp = nullptr;
        while (current != nullptr)
        {
            if (current->data == target)
            {
                if (current->previous == nullptr) // this is first node no need to do something
                {
                    return;
                }

                if (current->previous->previous == nullptr) // it mean it is second node of the list
                {
                    temp = current->previous;
                    head = current;
                    current->previous = nullptr;
                    delete temp;
                    return;
                }

                temp = current->previous;
                current->previous = temp->previous;
                temp->previous->next = current;

                delete temp;
                return;
            }
            current = current->next;
        }
    }

    void deleteAfterValue(object target)
    {
        Node *current = head;
        Node *temp = nullptr;
        while (current != nullptr)
        {
            if (current->data == target)
            {
                if (current->next == nullptr) // this is last node no need to do something
                {
                    return;
                }

                if (current->next->next == nullptr) // it mean it is second last node of the list
                {
                    temp = current->next;
                    temp->previous = nullptr;
                    tail = current;
                    tail->next = nullptr;
                    delete temp;
                    return;
                }

                temp = current->next;
                current->next = temp->next;
                current->next->previous = current;

                delete temp;
                return;
            }
            current = current->next;
        }
    }

    Node *searchNode(object target)
    {
        Node *current = head;

        if (head == nullptr)
        {
            return head;
        }

        while (current != nullptr)
        {
            if (target == current->data)
            {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }

    void displayReverseDoublyLinkedList()
    {
        Node *temp = nullptr;

        temp = head;
        head = tail;
        tail = temp;

        Node *current = head;

        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->previous;
        }
        // now again head and tail to its original node
        temp = head;
        head = tail;
        tail = temp;
    }
    void ReverseDoublyLinkedList()
    {
        Node *temp = nullptr;
        Node *current = head;

        if (head == nullptr)
        {
            return;
        }

        while (current != nullptr)
        {
            temp = current->next;
            current->next = current->previous;
            current->previous = temp;

            current = current->previous;
        }
        Node *helperTail = head;
        head = tail;
        tail = helperTail;
    }

    bool searchTwoNodes(object target1, object target2)
    {
        Node *current = head;
        if (head == nullptr)
        {
            return false;
        }
        int found = 0;
        while (current != nullptr)
        {
            if (target1 == current->data)
            {
                found++;
            }
            else if (target2 == current->data)
            {
                found++;
            }

            if (found == 2)
            {
                return true;
            }
            current = current->next;
        }

        return false;
    }

    void swapValuesOfSearchedNodes(object target1, object target2)
    {
        if (searchTwoNodes(target1, target2))
        {
            Node *temp = nullptr;

            for (Node *current = head; current != nullptr; current = current->next)
            {
                if (current->data == target1)
                {
                    temp = current; // now we find 1st node and in 2nd loop we will find 2nd Node and swap data
                }
            }
            for (Node *current = head; current != nullptr; current = current->next)
            {
                if (current->data == target2 && temp != nullptr)
                {
                    object newdata = temp->data;
                    temp->data = current->data;
                    current->data = newdata;
                    return;
                }
            }
        }
    }

    void swapSearchedNodes(object target1, object target2)
    {
        if (searchTwoNodes(target1, target2))
        {
            Node *temp1 = nullptr;
            Node *temp2 = nullptr;

            // Find target1 node
            for (Node *current = head; current != nullptr; current = current->next)
            {
                if (current->data == target1)
                {
                    temp1 = current;
                }
            }
            // Find target2 node
            for (Node *current = head; current != nullptr; current = current->next)
            {
                if (current->data == target2)
                {
                    temp2 = current;
                }
            }

            if (temp1 == temp2)
            {
                return;
            }

            // save all links of both nodes
            Node *firstNext = temp1->next;
            Node *firstPrevious = temp1->previous;

            Node *secondNext = temp2->next;
            Node *secondPrevious = temp2->previous;

            // now both nodes are adjacent then (temp1 is directly before temp2)
            if (firstNext == temp2)
            {
                temp2->previous = firstPrevious;
                temp2->next = temp1;

                temp1->previous = temp2;
                temp1->next = secondNext;

                if (firstPrevious != nullptr)
                {
                    firstPrevious->next = temp2;
                }
                if (secondNext != nullptr)
                {
                    secondNext->previous = temp1;
                }
            }
            // adjacent but temp2 is directly before temp1
            else if (secondNext == temp1)
            {
                temp1->previous = secondPrevious;
                temp1->next = temp2;

                temp2->previous = temp1;
                temp2->next = firstNext;

                if (secondPrevious != nullptr)
                {
                    secondPrevious->next = temp1;
                }
                if (firstNext != nullptr)
                {
                    firstNext->previous = temp2;
                }
            }
            // nodes are not adjacent
            else
            {
                temp1->next = secondNext;
                temp1->previous = secondPrevious;

                temp2->next = firstNext;
                temp2->previous = firstPrevious;

                if (firstPrevious != nullptr)
                {
                    firstPrevious->next = temp2;
                }
                if (firstNext != nullptr)
                {
                    firstNext->previous = temp2;
                }
                if (secondPrevious != nullptr)
                {
                    secondPrevious->next = temp1;
                }
                if (secondNext != nullptr)
                {
                    secondNext->previous = temp1;
                }
            }

            if (head == temp1)
            {
                head = temp2;
            }
            else if (head == temp2)
            {
                head = temp1;
            }

            if (tail == temp1)
            {
                tail = temp2;
            }
            else if (tail == temp2)
            {
                tail = temp1;
            }
        }
    }

    LinkedList *convertSinglyToDoubly(singlyNode *singlyHead)
    {
        singlyNode *current = singlyHead;
        LinkedList *list = new LinkedList();

        while (current != nullptr)
        {
            list->insertNodeAtLast(current->data);
            current = current->next;
        }
        return list;
    }

    void menu()
    {
        int choice;
        object value, target, target1, target2;

        while (true)
        {
            cout << "\n\n========== LINKED LIST MENU ==========\n";
            cout << "1. Insert Node At Last\n";
            cout << "2. Print Linked List\n";
            cout << "3. Insert Before Node\n";
            cout << "4. Delete Node\n";
            cout << "5. Clear List\n";
            cout << "6. Delete Before Value\n";
            cout << "7. Delete After Value\n";
            cout << "8. Search Node\n";
            cout << "9. Only Display Reverse Doubly Linked List\n";
            cout << "10. Reverse Doubly Linked List\n";
            cout << "11. Search Two Nodes\n";
            cout << "12. Swap Searched Nodes\n";
            cout << "13. Convert Singly To Doubly\n";
            cout << "0. Exit\n";
            cout << "=====================================\n";
            cout << "Enter choice: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                insertNodeAtLast(value);
                break;

            case 2:
                printLinkedlist();
                break;

            case 3:
                cout << "Enter target value: ";
                cin >> target;
                cout << "Enter value: ";
                cin >> value;
                insertBeforeNode(target, value);
                break;

            case 4:
                cout << "Enter target value: ";
                cin >> target;
                deleteNode(target);
                break;

            case 5:
                clearList();
                break;

            case 6:
                cout << "Enter target value: ";
                cin >> target;
                deleteBeforeValue(target);
                break;

            case 7:
                cout << "Enter target value: ";
                cin >> target;
                deleteAfterValue(target);
                break;

            case 8:
            {
                cout << "Enter target value: ";
                cin >> target;

                Node *result = searchNode(target);

                if (result != nullptr)
                {
                    cout << "Node found: " << result->data << endl;
                }
                else
                {
                    cout << "Node not found\n";
                }
                break;
            }

            case 9:
                displayReverseDoublyLinkedList();
                break;

            case 10:
                ReverseDoublyLinkedList();
                break;

            case 11:
            {
                cout << "Enter first target: ";
                cin >> target1;

                cout << "Enter second target: ";
                cin >> target2;

                if (searchTwoNodes(target1, target2))
                {
                    cout << "Both nodes found\n";
                }
                else
                {
                    cout << "Both nodes were not found\n";
                }
                break;
            }
            case 12:
                cout << "Enter first target: ";
                cin >> target1;

                cout << "Enter second target: ";
                cin >> target2;

                swapSearchedNodes(target1, target2);
                break;
            case 13:
            {
                // created 4 sampel SibglyNodes nwo iwill create a singly list from this
                singlyNode *node1 = new singlyNode();
                singlyNode *node2 = new singlyNode();
                singlyNode *node3 = new singlyNode();
                singlyNode *node4 = new singlyNode();
                // data
                node1->data = 10;
                node2->data = 20;
                node3->data = 30;
                node4->data = 40;
                // links
                node1->next = node2;
                node2->next = node3;
                node3->next = node4;

                singlyHead = node1;
                LinkedList *convertedList = convertSinglyToDoubly(singlyHead);

                cout << "Singly Linked List: ";
                singlyNode *current = singlyHead;
                while (current != nullptr)
                {
                    cout << current->data << " ";
                    current = current->next;
                }

                cout << endl;
                cout << "Now converted to Doubly Linked List: ";
                convertedList->printLinkedlist();
                cout << endl;

                break;
            }
            case 0:
                return;

            default:
                cout << "Invalid choice\n";
            }
        }
    }
};
int main()
{
    LinkedList<int> *list = new LinkedList<int>();

    list->menu();
    return 0;
}