#include <iostream>
#include <string>
using namespace std;

template <typename object>
struct Node
{
    object data;
    Node *next;
};
template <typename object>
class StackLinkedList
{
public:
    Node<object> *head = nullptr;
    Node<object> *tail = nullptr;
    int top;
    StackLinkedList()
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

    void clear()
    {
        top = -1;
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
    bool isEmpty()
    {
        return top == -1;
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
    }
    object pop()
    {
        if (top == -1)
        {
            cout << "Stack is empty\n";
            return -1;
        }
        object value = data[top];
        cout << data[top] << " is poped\n";
        --top;
        return value;
    }
    object peek()
    {
        if (isEmpty())
            return -1;
        return data[top];
    }
    void printStack()
    {

        if (isEmpty())
            cout << "stack is empty\n";

        for (int i = top; i >= 0; i--) // now print stack
        {
            cout << data[size] << endl;
            if (isEmpty())
                return;
        }
    }
    bool balancedPranthesis(string array)
    {
        Stack<char> *stackCreated = new Stack<char>();
        for (int i = 0; i < array.size(); i++)
        { // push in the stack while considering the precedence
            if (array[i] == '[' || array[i] == '{' || array[i] == '(')
            {
                if (stackCreated->isEmpty())
                {
                    stackCreated->push(array[i]);
                }
                else
                {
                    char currentTop = stackCreated->data[stackCreated->top];
                    if (array[i] == '[')
                    {
                        if (currentTop == '[')
                            stackCreated->push(array[i]);
                        else
                            return false;
                    }
                    else if (array[i] == '{')
                    {
                        if (currentTop == '[' || currentTop == '{')
                            stackCreated->push(array[i]);
                        else
                            return false;
                    }
                    else
                        stackCreated->push(array[i]);
                }
            }
            else if (array[i] == ']' || array[i] == '}' || array[i] == ')') // if it is closing brackets
            {
                if (stackCreated->isEmpty())
                    return false;

                char currentTop = stackCreated->data[stackCreated->top];

                // now match pairs
                if ( // it becomes pairs
                    array[i] == ')' && currentTop == '(' ||
                    array[i] == ']' && currentTop == '[' ||
                    array[i] == '}' && currentTop == '{')
                {
                    object val = stackCreated->pop();
                }
                else // if stact still contail unmatched then return false
                {
                    return false;
                }
            }
            else
                return false;
        }
        return stackCreated->peek(); // return the stack is empty or not
    }

    bool isOperator(char ch)
    {
        if (!(ch == '*' || // if ch is in these operators(i used ! in this to return the ture )
              ch == '+' ||
              ch == '/' ||
              ch == '-'))
        {
            return false;
        }
        return true;
    }

    void postFixEvaluation(string question)
    {

        Stack<int> *stackCreated = new Stack();
        object leftOperand = 0;
        object rightOperand = 0;
        for (int i = 0; i < question.size(); i++)
        {
            char ch = question[i];
            if (isOperator(ch))
            {
                rightOperand = stackCreated->pop();
                leftOperand = stackCreated->pop();

                object result;
                if (ch == '*')
                {
                    result = leftOperand * rightOperand;
                }
                else if (ch == '+')
                {
                    result = leftOperand + rightOperand;
                }
                else if (ch == '/')
                {
                    result = leftOperand / rightOperand;
                }
                else if (ch == '-')
                {
                    result = leftOperand - rightOperand;
                }
                else
                {
                    cout << "Invalid Operator" << endl;
                    return;
                }
                stackCreated->push(result);
            }
            else
            {
                stackCreated->push(ch - '0');
            }
        }
        cout << stackCreated->data[stackCreated->top] << endl;
    }
    int precedence(char ch)
    {
        if (ch == '*' && ch == '/')
            return 1;

        return 2;
    }
    string convertPostfix(string question)
    {
        Stack<char> *stackChar = new Stack<char>();
        string postfix = "";
        for (int i = 0; i <= question.size(); i++)
        {
            char ch = question[i];
            if (isOperator(ch)) // if it is operator then check the precedence and if precedence is sam rhtne check the associativity
            {
                while ((!stackChar->isEmpty()) && stackChar->peek() != '(' && precedence(ch) <= precedence(stackChar->peek()))
                {
                    postfix += stackChar->pop();
                }
                stackChar->push(ch);
            }
            else if (ch == '(')
            {
                stackChar->push(ch);
            }
            else if (ch == ')')
            {
                while (!stackChar->isEmpty() && stackChar->peek() != '(')
                {
                    postfix += stackChar->pop();
                }
                stackChar->pop(); // discard this bracket (
            }
            else // now it is operand
            {
                postfix += ch;
            }
        }
        do
        {
            postfix += stackChar->pop();
        } while (!isEmpty());

        return postfix;
    }
};
int main()
{
    // Stack<int> *stackList = new Stack<int>();
    Stack<char> *stackList2 = new Stack<char>();

    string array = "A*B/C";

    // stackList->postFixEvaluation(array);
    cout << stackList2->convertPostfix(array);
    return 0;
}