#include <iostream>
using namespace std;
template <typename object>
struct singlyNode
{
    object data;
    singlyNode<object> *next;
};
template <typename object>
class singlyLinkedList
{
public:
    singlyNode<object> *head = nullptr;
    singlyNode<object> *tail = nullptr;
    int size;
    singlyLinkedList()
    {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    void printList()
    {
        singlyNode<object> *current = head;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
    }
    void insertAtEnd(object vlaue)
    {
        singlyNode<object> *newNode = new singlyNode<object>();
        newNode->data = vlaue;

        if (head == nullptr)
        {
            newNode->next = nullptr;
            head = newNode;
            tail = newNode;
            ++size;
            return;
        }
        else
        {
            tail->next = newNode;
            newNode->next = nullptr;
            tail = newNode;
            ++size;
        }
    }

    void reverseLinkedListFromMid() // 1,2,3,4,5,6,7,8 become 4,3,2,1,8,7,6,5
    {
        if (head == nullptr) // if empty then return head
            return;
        if (head->next == nullptr) // if there is 1 node then also return
            return;

        int middle = size / 2;
        int count = 0;
        singlyNode<object> *current = head;
        singlyNode<object> *firstHalfHead = head;

        singlyNode<object> *previous = nullptr;
        singlyNode<object> *mid = nullptr;
        singlyNode<object> *next = nullptr;
        while (current != nullptr)
        {
            next = current->next;
            current->next = previous;
            ++count;
            previous = current;
            current = next;
            if (count == middle)
            {
                mid = current;
                head = previous;
                break;
            }
        }
        singlyNode<object> *secondHalfHead = mid;
        current = mid;
        while (current != nullptr)
        {
            next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }
        // previous is now 8 so i can use that current to link with 1 remeber 1 is the firsthalfhead and our new head is 4
        firstHalfHead->next = previous; // 1,2,3,4,5,6,7,8 become 4,3,2,1,8,7,6,5
        tail = secondHalfHead;          // secondHalfHead it is 5
        tail->next = nullptr;
    }
    void displaySinglyLinkedListReverseRecursively(singlyNode<object> *currentNode)
    {
        if (currentNode == nullptr)
            return;

        displaySinglyLinkedListReverseRecursively(currentNode->next); // noe move current 1 by 1 node
        cout << currentNode->data << " ";
    }

    void reverseRecursively(singlyNode<object> *previous, singlyNode<object> *current)
    {
        if (current == nullptr) // update the head
        {
            head = previous;
            return;
        }
        reverseRecursively(current, current->next);
        // now change the links
        current->next = previous;
        if (current->next == nullptr) // now uodate the tail
        {
            tail = current;
        }
    }
    void removeDuplicates()
    {
        singlyNode<object> *current = head;
        while (current != nullptr)
        {
            singlyNode<object> *previousRunner = current;
            singlyNode<object> *runner = current->next;
            while (runner != nullptr)
            {
                if (current->data == runner->data) // if we found that node then dlt that other wise move the runner to next node
                {
                    singlyNode<object> *victim = runner;
                    if (runner == tail)
                    {
                        tail = previousRunner;
                        previousRunner->next = nullptr;
                        delete victim;
                        break; // noe break the runner and update the counter
                    }
                    else
                    {
                        previousRunner->next = runner->next; // updating the link
                        runner = previousRunner->next;
                        delete victim;
                    }
                }
                else
                {
                    previousRunner = runner;
                    runner = runner->next;
                }
            }
            current = current->next;
        }
    }
    bool cycleDetection()
    {
        singlyNode<object> *slow = head;
        singlyNode<object> *fast = head;

        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                return true;
            }
        }
        return false;
    }
    singlyNode<object> *middle()
    {
        singlyNode<object> *slow = head;
        singlyNode<object> *fast = head->next;

        if (head == nullptr) // if list in empty then return
            return head;

        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    void separateEvenOdd()
    {
        singlyLinkedList<object> *evenList = new singlyLinkedList<object>();
        singlyLinkedList<object> *oddList = new singlyLinkedList<object>();

        singlyNode<object> *current = head;
        if (head == nullptr)
            return;
        while (current != nullptr)
        {
            if (current->data % 2 == 0) // even
                evenList->insertAtEnd(current->data);
            else
                oddList->insertAtEnd(current->data);
            current = current->next;
        }
        cout << "Even list: ";
        evenList->printList();
        cout << endl;
        cout << "Oddlist: ";
        oddList->printList();
    }
    void deleteAllOccurrences(object target)
    {
        singlyNode<object> *current = head;
        singlyNode<object> *previous = nullptr;
        if (head == nullptr)
            return;

        while (current != nullptr)
        {
            singlyNode<object> *nextNode = current->next;
            bool currentDeleted = false;
            if (current->data == target)
            {
                if (current->data == head->data) // if it is the head
                {
                    singlyNode<object> *victim = current;
                    head = head->next;
                    currentDeleted = true;
                    delete victim;
                }
                else if (current->data == tail->data) // if it is the tail
                {
                    singlyNode<object> *victim = current;
                    tail = previous;
                    currentDeleted = true;
                    delete victim;
                }
                else // or it is in the middle
                {
                    singlyNode<object> *victim = current;

                    previous->next = current->next;
                    currentDeleted = true;
                    delete victim;
                }
            }
            if (!currentDeleted)    // current is not deleted then update the previous
                previous = current; // if current is not deleted then update the previous
            current = nextNode;
        }
    }
    void swapAdjacentNodes()
    {
        if (head == nullptr || head->next == nullptr) // if empty or only 1 node then return
            return;

        singlyNode<object> *current = head;
        singlyNode<object> *previous = nullptr;

        while (current != nullptr && current->next != nullptr)
        {
            singlyNode<object> *nextNode = current->next;
            singlyNode<object> *nextPair = nextNode->next;

            nextNode->next = current; // mean next of 2nd node points to first
            current->next = nextPair; // now ponints the current to next pair

            if (previous == nullptr) // now set the head, after swapping first node just update the head that time
                head = nextNode;
            else
                previous->next = nextNode; // otherwise points that previous's next to the nextNode bcz previous was the first node of pair

            if (nextPair == nullptr)
                tail = current;

            previous = current;
            current = nextPair;
        }
    }
    void mainMenu()
    {
        int choice;

        do
        {
            cout << "\n========== SINGLY LINKED LIST MENU ==========\n";
            cout << "1.  Insert At End\n";
            cout << "2.  Print List\n";
            cout << "3.  Reverse Linked List From Middle\n";
            cout << "4.  Display Reverse Recursively\n";
            cout << "5.  Reverse Recursively\n";
            cout << "6.  Remove Duplicates\n";
            cout << "7.  Cycle Detection\n";
            cout << "8.  Find Middle Node\n";
            cout << "9.  Separate Even and Odd\n";
            cout << "10. Delete All Occurrences\n";
            cout << "11. Swap Adjacent Nodes\n";
            cout << "12. Exit\n";
            cout << "Enter your choice: ";
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
                printList();
                cout << '\n';
                break;

            case 3:
                reverseLinkedListFromMid();
                printList();
                cout << '\n';
                break;

            case 4:
                displaySinglyLinkedListReverseRecursively(head);
                cout << '\n';
                break;

            case 5:
                reverseRecursively(nullptr, head);
                printList();
                cout << '\n';
                break;

            case 6:
                removeDuplicates();
                printList();
                cout << '\n';
                break;

            case 7:
                if (cycleDetection())
                    cout << "Cycle detected!\n";
                else
                    cout << "No cycle detected.\n";
                break;

            case 8:
                if (head == nullptr)
                    cout << "List is empty.\n";
                else
                    cout << "Middle node: " << middle()->data << '\n';
                break;

            case 9:
                separateEvenOdd();
                cout << '\n';
                break;

            case 10:
            {
                object target;
                cout << "Enter value to delete: ";
                cin >> target;

                deleteAllOccurrences(target);
                printList();
                cout << '\n';
                break;
            }

            case 11:
                swapAdjacentNodes();
                printList();
                cout << '\n';
                break;

            case 12:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
            }

        } while (choice != 12);
    }
};
int main()
{
    // Case 1: Target head par bhi hai aur multiple times bhi
    singlyLinkedList<int> list1;
    list1.insertAtEnd(2);
    list1.insertAtEnd(2);
    list1.insertAtEnd(1);
    list1.insertAtEnd(2);
    list1.insertAtEnd(3);
    list1.insertAtEnd(8);
    list1.insertAtEnd(2);

    list1.mainMenu();

    return 0;
}