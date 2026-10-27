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
    int front, rear;

    PriorityQueue()
    {
        capacity = 4;
        size = 0;
        front = 0;
        rear = -1;

        data = new object[capacity];
        priorites = new int[capacity];
    }
    ~PriorityQueue()
    {
        delete[] data;
        delete[] priorites;
    }
    int nextIndexFront()
    {
        int index = (front++) % capacity;
        return index;
    }
    int nextIndex(int index)
    {
        int n = (front + index) % capacity;
        return n;
    }
    int nextIndexRear()
    {
        int index = (rear++) % capacity;
        return index;
    }
    bool isFull()
    {
        return size == capacity;
    }
    bool isEmpty()
    {
        return size == 0;
    }
    void resize()
    {
        int newCapacity = capacity * 2;
        object *newData = new object[newCapacity];

        for (int i = 0; i < size; i++)
        {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

    void menu()
    {
        int menuChoice = -1;
        do
        {
            cout << "\n0. Exit\n";
            cout << "1. Enqueue\n";
            cout << "2. Dequeue\n";
            cout << "3. Display\n";
            cout << "Enter choice: ";
            cin >> menuChoice;

            switch (menuChoice)
            {
            case 0:
                cout << "Terminating Programme\n";
                break;
            case 1:
            {
                object data;

                cout << "Enter data: ";
                cin >> data;
                cout << "Enter priority:\n";
                cout << "1. Emergency\n";
                cout << "2. High\n";
                cout << "3. Medium\n";
                cout << "4. Normal\n";
                int level;
                cin >> level;
                enqeue(data, level);
                break;
            }
            case 2:
            {
                if (size == 0)
                    cout << "Queue is empty!\n";

                else
                {
                    object dequeuedData = deqeue();
                    if (dequeuedData == -1)
                        break;
                    cout << "Dequeued data: " << dequeuedData << endl;
                }
                break;
            }
            case 3:
                display();
                break;
            default:
                cout << "Invalid choice!\n";
                break;
            }
        } while (menuChoice != 0);
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

    void moveIndexToRight(int n)
    {
        for (int i = size; i > n; i--)
        {
            int next = nextIndex(i);
            int previous = nextIndex(i - 1);
            data[next] = data[previous];           // move all data to right by 1 index
            priorites[next] = priorites[previous]; // move all priorities also to right by 1 index
        }
    }
    void enqeue(object value, int priorityLevel)
    {
        if (isEmpty())
        {
            int indexFirst = 0;
            data[nextIndex(indexFirst)] = value;
            priorites[nextIndex(indexFirst)] = priorityLevel;
            size++;
            return;
        }
        else if (isFull())
            resize();

        int position = 0;
        while (position < size && priorites[nextIndex(position)] <= priorityLevel)
        {
            position++;
        }
        // npw we got insetrion position first move the data to right to create gap

        moveIndexToRight(position);
        // now insert the data in the created gap
        int index = nextIndex(position);
        data[index] = value;
        priorites[index] = priorityLevel;

        size++;
        rear = nextIndex(size - 1);
    }
    object deqeue()
    {
        if (isEmpty())
        {
            cout << "Already Empty\n";
            object data = -1;
            return data;
        }
        object value = data[front];
        front = nextIndexFront();
        size--;
        front++;
        return value;
    }
    void display()
    {
        for (int i = 0; i < size; i++)
        {
            int index = nextIndex(i);
            cout << data[index] << " ";
        }
        cout << endl;
    }
};
int main()
{
    PriorityQueue<int> *pq = new PriorityQueue<int>();

    pq->menu();

    delete pq;
    return 0;
}