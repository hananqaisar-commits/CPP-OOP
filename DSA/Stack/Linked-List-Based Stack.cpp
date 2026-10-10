#include <iostream>
using namespace std;

template <typename object>
struct Node
{
    object data;
    Node *next;
};

template <typename object>
class Stack
{
public:
    Node<object> *head = nullptr;
    Node<object> *tail = nullptr;
    int top;

    Stack()
    {
        head = nullptr;
        tail = nullptr;
    }

    void push(object value)
    {
        Node<object> *newNode = new Node<object>();
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr) // mean if stack capacity is full then resize
        {
            head = newNode;
            tail = newNode;
            cout << tail->data << " is pushed\n";
            return;
        }

        tail->next = newNode;
        tail = newNode;

        cout << tail->data << " is pushed\n";
    }
    void pop()
    {
        if (head == nullptr)
        {
            cout << "Stack is empty\n";
            return;
        }

        if (head->next == nullptr) // mean if there is 1 node then
        {
            Node<object> *victim = head;
            cout << victim->data << " is poped\n";
            delete victim;
            head = nullptr;
            tail = nullptr;
            return;
        }

        Node<object> *current = head;
        Node<object> *previous = nullptr;

        while (current != nullptr)
        {
            if (current->next == nullptr)
            {
                Node<object> *victim = current;
                previous->next = nullptr;
                tail = previous;
                cout << victim->data << " is poped\n";
                delete victim;
                return;
            }
            previous = current;
            current = current->next;
        }
    }
    void peek()
    {
        if (head == nullptr)
        {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Peek: " << tail->data << " is at top" << endl;
    }

    void printStack()
    {
        if (head == nullptr)
        {
            cout << "Stack is empty\n";
            return;
        }
        Node<object> *current = head;

        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
    }
};
int main()
{
    Stack<int> *stack = new Stack<int>();

    int choice;

    do
    {
        cout << "\n===== STACK MENU =====\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Print Stack\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int value;
            cout << "Enter value to push: ";
            cin >> value;

            stack->push(value);
            break;
        }

        case 2:
            stack->pop();
            break;

        case 3:
            stack->peek();
            break;

        case 4:
            stack->printStack();
            break;

        case 5:
            cout << "Exiting Stack program...\n";
            break;

        default:
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 5);

    return 0;
}