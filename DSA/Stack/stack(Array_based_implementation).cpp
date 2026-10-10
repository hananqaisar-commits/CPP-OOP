#include <iostream>
using namespace std;

template <typename object>
class Stack
{
public:
    int capacity;
    object *data;
    int top;
    Stack()
    {
        capacity = 2;
        data = new object[capacity]; // this is array creation, now the array 1st index address will store in data and then remaainig will accessed by it
        top = -1;
    }
    ~Stack()
    {
        delete[] data;
    }

    void resize()
    {
        int newCapacity = capacity * 2; // double the capacity
        object *newData = new object[newCapacity];
        for (int i = 0; i < capacity; i++)
        {
            newData[i] = data[i];
        }
        cout << "All data copied" << endl;
        delete[] data;
        capacity = newCapacity;
        data = newData;
    }
    void push(object value)
    {
        if (top == capacity - 1) // mean if stack capacity is full then resize
        {
            cout << "Stack is full, doubling the capacity of stack right now!" << endl;
            resize();
        }
        data[++top] = value;
        cout << data[top] << " is pushed\n";
        cout << "Capacity: " << capacity << endl;
        cout << "Remains: " << capacity - (top + 1) << endl;
    }
    void pop()
    {
        if (top == -1)
        {
            cout << "Stack is empty\n";
            return;
        }
        object value = data[top];
        cout << data[top] << " is poped\n";
        --top;
    }
    void peek()
    {
        if (top == -1)
        {
            cout << "Stack is empty\n";
            return;
        }
        object value = data[top];
        cout << "Peek: " << data[top] << " is at top\n";
    }
    void printStack()
    {
        int size = top;
        if (size == -1)
        {
            cout << "stack is empty\n";
        }
        for (int i = top; i >= 0; i--) // now print stack
        {
            cout << data[size] << endl;
            --size;
            if (size == -1)
            {
                return;
            }
        }
    }
};
int main()
{
    Stack<int> stack;
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

            stack.push(value);
            break;
        }

        case 2:
            stack.pop();
            break;

        case 3:
            stack.peek();
            break;

        case 4:
            stack.printStack();
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