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

    singlyNode<object> *reverseLinkedListFirstHalfFromMid()
    {
        if (head == nullptr)
        {
            return head;
        }

        int middle = size / 2;
        int count = 0;
        singlyNode<object> *current = head;
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
                break;
            }
        }
        head->next = current; // it will join the link with second half
        head = previous;      // now uppdate the head

        if (size % 2 != 0) // if it is even the return the middle node otherwise return next node mean 1,2,3,4 return 3 node
        {
            return mid;
        }
        return current;
    }

    bool isPalindrome()
    {
        if (head == nullptr) // empty list
            return true;
        if (head->next == nullptr) // if there is 1 node
            return true;

        singlyNode<object> *mid = reverseLinkedListFirstHalfFromMid();
        singlyNode<object> *current1 = head;
        singlyNode<object> *current2 = mid->next; // if it was odd then it will return middle  node we need middle.next

        bool result = false;
        if (size % 2 != 0) // odd number linkedlist
        {
            while (current2 != nullptr)
            {
                if (current1->data != current2->data)
                {
                    singlyNode<object> *mid = reverseLinkedListFirstHalfFromMid(); // if it is not palindrome then come to normal state and then
                    return result;
                }
                current1 = current1->next;
                current2 = current2->next;
            }
            singlyNode<object> *mid = reverseLinkedListFirstHalfFromMid(); // if it is palindrome then now come into normal state
            result = true;
        }
        else
        {                   // now even node
            current2 = mid; // if list was even the we nedd 3rd node
            while (current2 != nullptr)
            {
                if (current1->data != current2->data)
                {
                    singlyNode<object> *mid = reverseLinkedListFirstHalfFromMid(); // if it is not palindrome then come to normal state and then
                    return result;
                }
                current1 = current1->next;
                current2 = current2->next;
            }
            singlyNode<object> *mid = reverseLinkedListFirstHalfFromMid(); // if it is palindrome then now come into normal state
            result = true;
        }
        return result;
    }
};

int main()
{
    singlyLinkedList<int> *singlyList = new singlyLinkedList<int>();
    singlyList->insertAtEnd(10);
    singlyList->insertAtEnd(20);
    singlyList->insertAtEnd(30);
    singlyList->insertAtEnd(20);
    singlyList->insertAtEnd(10);

    cout << singlyList->isPalindrome() << " ";
    singlyList->printList();

    return 0;
}