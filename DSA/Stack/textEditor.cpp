#include <iostream>
using namespace std;
class Stack
{
public:
    string *data;
    int capacity;
    int size;
    int top;
    Stack()
    {
        capacity = 4;
        top = -1;
        size = 0;
        data = new string[capacity];
    }
    void resize()
    {
        int newCapacity = capacity * 2;
        string *newData = new string[newCapacity];
        // copy data to newdata array
        for (int i = 0; i < capacity; i++)
        {
            newData[i] = data[i];
        }
        capacity = newCapacity;
        delete[] data;
        data = newData;
    }
    bool isFull()
    {
        return top == capacity - 1;
    }
    bool isEmpty()
    {
        return top == -1;
    }
    string push(string value)
    {
        if (isFull())
            resize();

        data[++top] = value;
        return value;
    }
    string pop()
    {
        if (isEmpty())
            return "Stack Failed";

        string popedData = data[top];
        top--;
        return popedData;
    }

    void State()
    {
        cout << "Stack: \n";
        for (int i = 0; i <= top; i++)
        {
            cout << data[i] << "\n";
        }
        cout << endl;
    }
    void print()
    {
        cout << "Stack print in lifo Order: \n";
        for (int i = top; i >= 0; i--)
        {
            cout << data[i] << "\n";
        }
        cout << endl;
    }
    string peek()
    {
        return data[top];
    }
};
int main()
{

    Stack *stack = new Stack();
    Stack *stackUndo = new Stack();

    stack->push("hello");
    stack->State();
    stack->push("world");
    stack->State();
    stack->print();
    stack->push("delete hello");
    stack->print();

    stackUndo->push(stack->pop());
    stack->print();

    cout << "\nUndo operation is performed:\n\n";
    stack->push(stackUndo->pop());
    stack->print();

    delete stack;
    delete stackUndo;
    return 0;
}