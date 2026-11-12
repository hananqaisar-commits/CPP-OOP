#include <iostream>
using namespace std;

struct patient
{
public:
    string name;
    int time;
    int id;
    int priority;
    patient()
    {
        name = "";
        time = 0;
        id = 0;
        priority = 0;
    }
    patient(string name, int time, int id, int priority)
    {
        this->name = name;
        this->time = time;
        this->id = id;
        this->priority = priority;
    }
};

class Queue
{
public:
    int front;
    int rear;
    int size;
    int capacity;
    patient *array;
    Queue()
    {
        front = 0;
        rear = -1;
        size = 0;
        capacity = 10;
        array = new patient[capacity];
    }
    ~Queue()
    {
        delete[] array;
    }

    bool isEmpty()
    {
        return size == 0;
    }
    bool isFull()
    {
        return size == capacity;
    }
    int nextFront()
    {
        return (front + 1) % capacity;
    }
    int nextRear()
    {
        return (rear + 1) % capacity;
    }
    int nextIndex(int i)
    {
        return (i + 1) % capacity;
    }
    int nextIndexDisplay(int i)
    {
        return (front + i) % capacity; // to print ith index is liya mei front mei i add kr rha hn to print that index array
    }
    void enqeue(patient *p)
    {

        array[nextIndex(rear)] = *p;
        rear = nextRear();
        size++;
    }
    patient dequeue()
    {
        patient p = array[nextIndex(front - 1)];
        front = nextFront();
        size--;
        return p;
    }
    void display()
    {

        cout << "ID\tName\t\tTime\tPriority\n";
        cout << "-----------------------------------\n";
        for (int i = 0; i < size; i++)
        {
            int ind = nextIndexDisplay(i);
            cout << array[ind].id << "\t"
                 << array[ind].name << "\t\t"
                 << array[ind].time << "\t"
                 << array[ind].priority << endl;
        }
        cout << "-----------------------------------\n\n";
    }

    bool roundRobin()
    {
        array[nextIndex(front - 1)].time = array[nextIndex(front - 1)].time - 3;
        bool isExamined = false;
        if (array[nextIndex(front - 1)].time <= 0)
        {
            isExamined = true;
            return isExamined;
        }
        return isExamined;
    }
};
int main()
{
    Queue *cq = new Queue();
    Queue *sq = new Queue();
    patient *newPatient = new patient();

    int choice = -1;
    do
    {
        cout << "Enter choice: " << "\n0.Exit\n"
             << "1.Enter patient\n"
             << "2.Remove Patient\n"
             << "3.Display Patients\n"
             << "4.Rounnd Robbin Processing\n";
        cin >>
            choice;
        switch (choice)
        {
        case 0:
            cout << "Exiting Programme\n";
            return 0;
        case 1:
            cout << "Enter parient ID: ";
            cin >> newPatient->id;
            cout << "Enter parient name: ";
            cin >> newPatient->name;
            cout << "Enter parient urgency: ";
            cin >> newPatient->priority;
            cout << "Enter parient time: ";
            cin >> newPatient->time;

            if (newPatient->priority == 1)
            {
                if (cq->isFull())
                {
                    cout << "Critical queue is full\n";
                    break;
                }
                cq->enqeue(newPatient);
            }
            else
            {
                if (sq->isFull())
                {
                    cout << "Critical queue is full\n";
                    break;
                }
                sq->enqeue(newPatient);
            }
            break;

        case 2:
            int choice = -1;
            cout << "Deqeue?(Choose 1/2)\n"
                 << "1.Critical\n"
                 << "2.Standard\n";
            cin >> choice;

            if (choice == 1 && !cq->isEmpty())
                cq->dequeue();

            else if (choice == 2 && !sq->isEmpty())
                sq->dequeue();
            else
            {
                if (choice != 1 && choice != 2)
                {
                    cout << "Invalid choice\n";
                    break;
                }
                cout << "Empty Queue\n";
            }
            break;
        case 3:
            cout << "Critical Patients:\n";
            if (!cq->isEmpty())
                cq->display();
            else
                cout << "Critical patients Queue is empty\n";

            cout << "Normal Patients:\n";
            if (!sq->isEmpty())
                sq->display();
            else
                cout << "Normal patients Queue is empty\n";

            break;
        case 4:

            cout << "Patient and it's time: \n";
            if (!cq->isEmpty())
                cq->display();
            if (!sq->isEmpty())
                sq->display();

            cout << "Round Robin Start: \n";
            while (!cq->isEmpty()) // if critical is not empty then process critical first
            {
                if (cq->roundRobin())
                { // if examination for 1 patient is complketed then discharge that one
                    patient p = cq->dequeue();
                    cout << p.name << " examined/discharged from critical list\n";
                }
                else
                {
                    cq->display();
                    patient p = cq->dequeue();
                    cout << "Patient dequeud after 3 minutes\n";
                    cq->enqeue(&p);
                    cout << "Patient equeud at last\n";
                }
            }
            while (!sq->isEmpty())
            {
                if (sq->roundRobin())
                { // if examination for 1 patient is complketed then discharge that one
                    patient p = sq->dequeue();
                    cout << p.name << " examined/discharged from normal queue\n";
                }
                else
                {
                    sq->display();
                    patient p = sq->dequeue();
                    cout << "Patient dequeud after 3 minutes\n";
                    sq->enqeue(&p);
                    cout << "Patient equeud at last\n";
                }
            }

            break;
        default:
            cout << "Invalid\n";
        }
    } while (choice != 0);

    return 0;
}