#include <iostream>
using namespace std;
template <typename Object>
class linkedList
{
    // 1. Create struct Node and then data and *next pointer that  will point to the next nodeaddress
    // 2. now Head and tail pointer will created
    // 3. insertNodeAfterValue simple first check that head==nullptr then it mean no list exist then that newNode will be the head of the linkedList and tail will also point to that newNode
    // 4. now in eelse if it is not first Node then loop will traverse through the list and check target data ehre it wil found targrt data then the next pointer oif newNode will assign the next pointer of current node and after the whole travere then assign the tail to the current
    // 5. Loop will traverse untill current!=nullptr
public:
    struct Node
    {
        Object data;
        Node *next;
    };

    Node *head = nullptr;
    Node *tail = nullptr;
    linkedList()
    {
        head = nullptr;
        tail = nullptr;
    }
    linkedList(Object data)
    {
        head = new Node();
        head->data = data;
        head->next = nullptr;

        tail = head;
    }
    void insertNodeAfterValue(Object data, Object target)
    {
        Node *newNode = new Node(); // insert node method will create new node and then assigng data to that node and assign current next to next

        newNode->data = data;
        newNode->next = nullptr;
        if (head == nullptr) // if list is empty then the first node will be this
        {
            head = newNode; // head will at newnode
            tail = newNode; // tail will also at newNode
        }
        else
        {
            for (Node *current = head; current != nullptr; current = current->next)
            {
                // tail will be at last
                if (current->data == target) // when node will found then take 1 temp node and then assign the next* of newNode to current.next and then current.next= new Node
                {
                    newNode->next = current->next; // first assign newnode to next of current
                    current->next = newNode;
                    if (current == tail)
                    {
                        tail = newNode;
                    }
                    return;
                }
                tail = current;
            }
        }
    }
    void insertBeforeValue(Object value, Object target)
    {
        Node *newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            Node *current = head;
            Node *temp = nullptr;
            while (current != nullptr)
            {
                if (current->data == target)
                {
                    newNode->next = current;
                    if (current == head) // if both head and current is at head then move head to newnode which was places before head node
                    {
                        head = newNode;
                    }
                    else
                    {
                        temp->next = newNode;
                    }
                    return;
                }
                temp = current;
                current = current->next; // when current will move next to the head before that temp store previous node address
            }
        }
    }
    void deleteFromLast()
    {
        Node *current = head;
        Node *temp = nullptr;

        while (current != nullptr)
        {
            if (current->next == nullptr)
            {
                tail = temp;
                tail->next = nullptr;
                return;
            }

            temp = current;
            current = current->next;
        }
    }
    void deleteValue(Object target)
    {
        Node *current = head;
        Node *temp = nullptr;

        while (current != nullptr)
        {
            if (current->data == target)
            {
                if (current == head)
                {
                    head = head->next;
                    delete current; // free the unlink node memory
                    return;
                }
                else if (current == tail)
                {
                    tail = temp; // if deleted node is at tail then we will move tail to temp and then delte that memory of current
                    delete current;
                    return;
                }

                temp->next = current->next;
                delete current;

                return;
            }

            temp = current;
            current = current->next;
        }
    }
    void clear()
    {
        Node *current = head;
        Node *toBeDeleted = nullptr;
        while (current != nullptr) // delete all memory of nodes then assign head and tail to nullptr
        {
            toBeDeleted = current;
            current = current->next;
            delete toBeDeleted;
        }
        head = nullptr;
        tail == nullptr;
    }
    void insertAtEnd(Object value)
    {
        Node *newNode = new Node();

        newNode->data = value;
        newNode->next = nullptr;

        if (tail == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    void deleteFromStart()
    {

        Node *current = head;

        head = head->next;
        if (head == nullptr) // if list is empty then
        {
            return;
        }
        delete current;
    }
    // list node will traverse untill current!=null and updation condition is current=current->next;

    void listNodes()
    {
        Node *current = head;
        while (current != nullptr)
        {
            cout << current->data << endl;
            current = current->next;
        }
    }

    Node *search(Object value)
    {
        Node *found = nullptr;
        for (Node *current = head; current != nullptr; current = current->next)
        {
            if (current->data == value)
            {
                return found;
            }
        }
        return nullptr;
    }

    linkedList<Object> mergeTwoLinkedList(linkedList<Object> *l1, linkedList<Object> *l2)
    {
        linkedList<Object> merged;

        Node *currentl1 = l1->head;
        Node *currentl2 = l2->head;
        while (currentl1 != nullptr)
        {
            merged.insertAtEnd(currentl1->data);
            currentl1 = currentl1->next;
        }
        while (currentl2 != nullptr)
        {
            merged.insertAtEnd(currentl2->data);
            currentl2 = currentl2->next;
        }
        return merged;
    }
    int size()
    {
        int i = 0;
        for (Node *current = head; current != nullptr; current = current->next)
        {
            i++;
        }
        return i;
    }
    void displayreverseLinkedList()
    {
        int i = size();
        Object array[i];

        for (Node *counter = head; counter != nullptr && i > 0; counter = counter->next)
        {
            array[i - 1] = counter->data; // assign all linked list in array from back
            --i;
        }
        int k = size();
        for (int j = 0; j < k; j++)
        {
            cout << array[j] << endl;
            ;
        }
    }
    void displayReverseRecursively(Node *current)
    {
        if (current == nullptr)
        {
            return;
        }
        displayReverseRecursively(current->next); // it will call like 10,20,30,40,50 and when
        cout << current->data << endl;
    }
    void searchMultipleIndexs(Object target)
    {
        int i = 0;
        for (Node *current = head; current != nullptr; current = current->next)
        {
            if (current->data == target)
            {
                cout << target << " found at position " << i << "\n";
            }
            i++;
        }
    }
};
void menu()
{
    linkedList<int> *list1 = new linkedList<int>(10);

    list1->insertNodeAfterValue(20, 10);
    list1->insertNodeAfterValue(30, 20);
    list1->insertNodeAfterValue(40, 30);

    linkedList<int> *list2 = new linkedList<int>(50);

    list2->insertAtEnd(60);
    list2->insertAtEnd(70);
    list2->insertAtEnd(60);

    linkedList<int> merge = list1->mergeTwoLinkedList(list1, list2);

    int choice = 0;

    while (choice != 13)
    {
        cout << "\n========== LINKED LIST MENU ==========\n";
        cout << "1. Display Linked List\n";
        cout << "2. Insert Node After Value\n";
        cout << "3. Insert Node Before Value\n";
        cout << "4. Insert Node At End\n";
        cout << "5. Delete Value\n";
        cout << "6. Delete From Start\n";
        cout << "7. Delete From Last\n";
        cout << "8. Display Reverse Using Array\n";
        cout << "9. Display Reverse Recursively\n";
        cout << "10. Search Multiple Occurrences\n";
        cout << "11. Display Size\n";
        cout << "12. Clear Linked List\n";
        cout << "13. Exit\n";
        cout << "======================================\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "\nLinked List:\n";
            merge.listNodes();
            break;

        case 2:
        {
            int data;
            int target;

            cout << "Enter data: ";
            cin >> data;

            cout << "Enter target: ";
            cin >> target;

            merge.insertNodeAfterValue(data, target);

            cout << "\nUpdated List:\n";
            merge.listNodes();

            break;
        }

        case 3:
        {
            int data;
            int target;

            cout << "Enter data: ";
            cin >> data;

            cout << "Enter target: ";
            cin >> target;

            merge.insertBeforeValue(data, target);

            cout << "\nUpdated List:\n";
            merge.listNodes();

            break;
        }

        case 4:
        {
            int value;

            cout << "Enter value: ";
            cin >> value;

            merge.insertAtEnd(value);

            cout << "\nUpdated List:\n";
            merge.listNodes();

            break;
        }

        case 5:
        {
            int target;

            cout << "Enter value to delete: ";
            cin >> target;

            merge.deleteValue(target);

            cout << "\nUpdated List:\n";
            merge.listNodes();

            break;
        }

        case 6:
            merge.deleteFromStart();

            cout << "\nUpdated List:\n";
            merge.listNodes();

            break;

        case 7:
            merge.deleteFromLast();

            cout << "\nUpdated List:\n";
            merge.listNodes();

            break;

        case 8:
            cout << "\nReverse:\n";
            merge.displayreverseLinkedList();
            break;

        case 9:
            cout << "\nReverse Recursively:\n";
            merge.displayReverseRecursively(merge.head);
            break;

        case 10:
        {
            int target;

            cout << "Enter target: ";
            cin >> target;

            merge.searchMultipleIndexs(target);

            break;
        }

        case 11:
            cout << "\nSize: " << merge.size() << endl;
            break;

        case 12:
            merge.clear();

            cout << "\nLinked List Cleared.\n";
            break;

        case 13:
            cout << "\nExiting...\n";
            break;

        default:
            cout << "\nInvalid choice.\n";
        }
    }
}

int main()
{
    menu();

    return 0;
}