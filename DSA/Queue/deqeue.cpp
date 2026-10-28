#include <iostream>
using namespace std;

class Deque
{
public:
    int *data;
    int capacity;
    int size;
    int front;

    Deque()
    {
        capacity = 2;
        data = new int[capacity];
        size = 0;
        front = 0;
    }

    int nextIndex(int i)
    {
        return (front + i) % capacity;
    }
    void resize()
    {
        int newCapacity = capacity * 2;
        int *newData = new int[newCapacity];

        for (int i = 0; i < size; i++)
        {
            newData[i] = data[nextIndex(i)];
        }
        delete[] data;
        data = newData;
        capacity = newCapacity;
        front = 0;
    }
    bool isFull()
    {
        return size == capacity;
    }
    bool isEmpty()
    {
        return size == 0;
    }
    void insertAtFront(int value)
    {
        if (isFull())
            resize();

        front = (front - 1 + capacity) % capacity;
        data[front] = value;
        size++;
    }
    int deleteFromRear()
    {
        if (isEmpty())
            return -1;
        int deletedData = data[(front + size - 1) % capacity];
        size--;
        return deletedData;
    }

    void insertAtRear(int value)
    {
        if (isFull())
            resize();

        data[(front + size) % capacity] = value;
        size++;
    }

    int deleteFromFront()
    {

        int deletedData = data[front];
        front = (front + 1) % capacity;
        size--;
        return deletedData;
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

    Deque *list = new Deque();
    list->insertAtFront(20);
    list->insertAtFront(10);
    list->insertAtRear(30);
    list->insertAtRear(40);

    list->deleteFromRear();
    list->deleteFromRear();

    list->display();
    return 0;
}