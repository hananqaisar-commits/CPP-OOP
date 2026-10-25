#include <iostream>
using namespace std;
template <typename object>
class PriorityQueue
{
public:
    int size;
    int capacity;
    object *data;
    int *priorites;
    int front, rear, helper;

    PriorityQueue()
    {
        data = new object[capacity];
        priorities = new int[capacity];
        front = 0;
        rear = -1;
        helper = -1;
        size = 0;
        capacity = 10;
    }
    ~PriorityQueue()
    {
        delete[] data;
        delete[] priorities;
    }
    int nextIndexFront()
    {
        int index = (front++) % capacity;
        return index;
    }
    bool isFull()
    {
        return size == capacity;
    }
    void resize()
    {
        int newCapacity = capacity * 2;
        object *newData = new object();

        for (int i = 0; i < size; i++)
        {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }
    int nextIndexRear()
    {
        int index = (rear++) % capacity;
        return index;
    }
    void menu()
    {
        int menuChoice = -1;
        cout << "0.Exit \n";
        cout << "1. Enqeue: \n";
        cout << "2. Dqeue: \n";
        cout << "3. Display: \n";
        cout << "Enter choice: \n";
        cin >> menuChoice;
        switch (menuChoice)
        {
        case 0:
            cout << "Terminating Programme\n";
            break;
        case 1:
        {
            cout << "Enter data: " << endl;
            object data;
            cin >> data;
            cout << "Enter priority: " << endl;
            cout << "1. Emergency\n";
            cout << "2. High\n";
            cout << "3. Medium\n";
            cout << "4. Normal\n";
            int level;
            cin >> level;
            enqeue(data, level);
        }

        default:
            break;
        }
    }
    int priority(int level)
    {
        if (level == 1)
            return 1;
        else if (level == 2)
            return 2;
        else if (level == 3)
            return 3;
        else if (level == 4)
            return 4;

        return -1;
    }
    void enqeue(object value, int priorityLevel)
    {
    }
    object deqeue()
    {
        object value = data[front];
        rear = nextIndexFront();
        return value;
    }

    void display()
    {
        for (int i = front; i != rear; i++)
        {
            cout << data[i];
        }
    }
};
int main()
{

    PriorityQueue<int> *pq = new PriorityQueue<int>();

    pq->menu();
    return 0;
}