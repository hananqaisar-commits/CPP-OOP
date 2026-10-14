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

    cout << "Case 1: ";
    list1.deleteAllOccurrences(2);
    list1.printList();

    // Case 2: Target middle mein multiple times hai
    singlyLinkedList<int> list2;
    list2.insertAtEnd(1);
    list2.insertAtEnd(2);
    list2.insertAtEnd(3);
    list2.insertAtEnd(2);
    list2.insertAtEnd(4);

    cout << "Case 2: ";
    list2.deleteAllOccurrences(2);
    list2.printList();

    // Case 3: Target tail par hai
    singlyLinkedList<int> list3;
    list3.insertAtEnd(1);
    list3.insertAtEnd(2);
    list3.insertAtEnd(3);
    list3.insertAtEnd(3);

    cout << "Case 3: ";
    list3.deleteAllOccurrences(3);
    list3.printList();

    // Case 4: Saare nodes target ke equal hain
    singlyLinkedList<int> list4;
    list4.insertAtEnd(5);
    list4.insertAtEnd(5);
    list4.insertAtEnd(5);

    cout << "Case 4: ";
    list4.deleteAllOccurrences(5);
    list4.printList();

    return 0;
}