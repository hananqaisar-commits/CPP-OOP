#include <iostream>
using namespace std;
template <typename Object>
class linkedList
{
public:
    struct Node
    {
        Object data;
        Node *next;
    };

    Node *head = new Node(); // this is head node it will created
    Node *tail = new Node(); // this is head node it will created

    linkedList()
    {
        head->data = nullptr;
        head->next = nullptr;
    }
    linkedList(Object data)
    {
        head->data = data;
        head->next = nullptr;
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
                if (current->data == target) // when node will found then take 1 temp node and then assign the next* of newNode to current.next and then current.next= new Node
                {
                    newNode->next = current->next; // first assign newnode to next of current
                    current->next = newNode;
                }
                tail = current; // tail will be at last
            }
        }
    }
    void listNodes()
    {
        Node *current = head;
        while (current != nullptr)
        {
            cout << current->data << endl;
            current = current->next;
        }
    }
};

int main()
{
    linkedList<int> *list = new linkedList<int>(10);
    list->insertNodeAfterValue(20, 10);
    list->insertNodeAfterValue(30, 20);
    list->insertNodeAfterValue(40, 30);

    list->listNodes();

    return 0;
}