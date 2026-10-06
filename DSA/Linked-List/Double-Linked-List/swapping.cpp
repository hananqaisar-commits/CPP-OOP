#include <iostream>
using namespace std;

// Struct
template <typename object>
struct Node
{
    object data;
    Node *next;
    Node *previous;
};
// class
template <typename object>
class doubleLinkedList
{
public:
    Node<object> *head = nullptr;
    Node<object> *tail = nullptr;
    void insertAtLast(object data)
    {
        Node<object> *newNode = new Node<object>();
        newNode->data = data;
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;

            head->next = nullptr;
            head->previous = nullptr;
            tail->next = nullptr;
            tail->previous = nullptr;

            return;
        }

        tail->next = newNode;
        newNode->next = nullptr;
        newNode->previous = tail;

        tail = newNode;
        return;
    }

    void display()
    {
        Node<object> *current = head;

        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
    }

    bool searchNodes(object t1, object t2, Node<object> *&found1, Node<object> *&found2) // retrurn address for both address from this it is more efficient way
    {
        Node<object> *current = head;

        int found = 0;
        while (current != nullptr)
        {
            if (found == 2)
                return true;
            if (current->data == t1)
            {
                found1 = current;
                found++;
            }
            else if (current->data == t2)
            {
                found2 = current;
                found++;
            }
            current = current->next;
        }
        return false;
    }

    void swapTwoNodes(object t1, object t2)
    {
        Node<object> *found1 = nullptr;
        Node<object> *found2 = nullptr;

        Node<object> *found1Next = nullptr;
        Node<object> *found1Previous = nullptr;
        Node<object> *found2Next = nullptr;
        Node<object> *found2Previous = nullptr;

        if (searchNodes(t1, t2, found1, found2))
        {
            // now save all links of found1 and found2
            found1Next = found1->next;
            found1Previous = found1->previous;

            found2Next = found2->next;
            found2Previous = found2->previous;
        }
        else
            return;

        // if both are adjacents
        if (found1->next == found2)
        {
            // firsst chnge the swapping node link which will 4 (1.found1.next, 2.found2.previous,3.found1.previous, 4.found2.next)
            found2->previous = found1Previous;
            found2->next = found1;

            found1->previous = found2;
            found1->next = found2Next;

            // now after those 4 links now remain firstprevious.next and also secondnext.previous
            if (found2Next != nullptr)
                found2Next->previous = found1;

            if (found2Previous != nullptr)
                found1Previous->next = found2;

            if (found1 == head && found2 == tail)
            {
                head = found2;
                tail = found1;
            }
        }
        else if (found2->next == found1)
        {
            found2->next = found1Next;
            found2->previous = found1;

            found1->next = found2;
            found1->previous = found2Previous;

            if (found2Previous != nullptr)
                found2Previous->next = found1;
            if (found1Next != nullptr)
                found1Next->previous = found2;

            // if only there is two nodes which is head and tail
            if (found2 == head && found1 == tail)
            {
                head = found1;
                tail = found2;
            }
        }
        // now case 3: non-adjacent nodes of linkedlist
        else
        {
            // 10 20 30 40

            found1->next = found2Next;
            found1->previous = found2Previous;

            if (found2Next != nullptr)
                found2Next->previous = found1;

            if (found2Previous != nullptr)
                found2Previous->next = found1;

            found2->next = found1Next;
            found2->previous = found1Previous;

            if (found1Next != nullptr)
                found1Next->previous = found2;
            if (found1Previous != nullptr)
                found1Previous->next = found2;
            // now chcking head and tail
            // after swapping i am checking wheather found1 wa head or not and same for found2 node

            if (found1 == head)
                head = found2;
            else if (found2 == head)
                head = found1;
            if (found1 == tail)
                tail = found2;
            else if (found2 == tail)
                tail = found1;
        }
    }
};
int main()
{

    doubleLinkedList<int> *list = new doubleLinkedList<int>();

    list->insertAtLast(10);
    list->insertAtLast(20);
    list->insertAtLast(30);
    list->insertAtLast(40);
    list->insertAtLast(50);

    list->display();

    cout << "\n===================\n";

    list->swapTwoNodes(10, 40);
    list->display();

    return 0;
}