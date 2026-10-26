#include <iostream>
using namespace std;
template <typename object>
struct Node
{
    object data;
    Node *next;

    Node()
    {
    }
};
class Task
{
public:
    string priority;
    string name;
    string status;

    Task() : priority(""), name(""), status("Pending") {}
    Task(string p, string n, string s) : priority(p), name(n), status(s) {};

    void display(Node<Task> *current)
    {

        cout << "Name     : " << current->data.name << '\n';
        cout << "Priority : " << current->data.priority << '\n';
        cout << "Status   : " << current->data.status << '\n';
    }
};

template <typename object>
class CircularLinkedList
{
public:
    Node<object> *head = nullptr;
    Node<object> *tail = nullptr;

    CircularLinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }
    void insertAtEnd(object value)
    {
        Node<object> *newNode = new Node<object>();

        newNode->data = value;

        // if circularLinkedList is empty
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
            tail->next = head;
            return;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
            return;
        }
    }

    void display()
    {
        Node<object> *current = head;
        if (head == nullptr)
            return;
        do
        {
            cout << current->data << "->";
            current = current->next;
        } while (current != head);
        cout << "nullptr\n";
    }
    void deleteNode(Node<object> *&found, Node<object> *&previous)
    {
        Node<object> *victim = found;
        // if there is one node and that node is the victiim
        if (victim == head && victim == tail)
        {
            head = nullptr;
            tail = nullptr;
            delete victim;
            return;
        }
        previous->next = found->next;
        // now handle head and tail
        if (victim == head)
            head = victim->next;

        if (victim == tail)
            tail = previous;
        delete victim;
    }

    object josephus(object k)
    {
        object count = 0;
        Node<object> *current = head;
        Node<object> *previous = tail;
        while (true)
        {
            if (head == nullptr)
            {
                return 0;
            }
            if (current->next == current) // if cycle is detected then return that data node
            {
                return current->data;
            }
            // 1,2,3,4,5,6,7
            count++;
            if (count == k)
            {
                Node<object> *victim = current;
                current = victim->next; // now the current starts from kth+1 node
                count = 0;              // reset the count to 0
                deleteNode(victim, previous);
            }
            else
            {
                previous = current;
                current = current->next;
            }
        }
    }
    void mainMenuTask()
    {
        int choice;
        do
        {
            cout << "\n===== CIRCULAR TASK MANAGER =====\n";
            cout << "1. Add Task\n";
            cout << "2. Display All Tasks\n";
            cout << "3. Get Next Pending Task\n";
            cout << "4. Update Task Status\n";
            cout << "5. Delete Task By Name\n";
            cout << "6. Exit\n";
            cout << "Enter choice: ";
            cin >> choice;
            switch (choice)
            {
            case 1:
            {
                string prior, name, status;

                cout << "Enter priority: ";
                getline(cin >> ws, prior);

                cout << "Enter task name: ";
                getline(cin, name);

                cout << "Enter status (Pending/Completed): ";
                getline(cin, status);

                object newTask(prior, name, status);
                insertAtEnd(newTask);

                cout << "Task added successfully!\n";
                break;
            }

            case 2:
                displayAllTasks();
                break;

            case 3:
            {
                Node<object> *pending = getpendingTask();

                if (pending != nullptr)
                {
                    cout << "\nNext Pending Task\n";
                    cout << "Name: " << pending->data.name << '\n';
                    cout << "Priority: " << pending->data.priority << '\n';
                    cout << "Status: " << pending->data.status << '\n';
                }
                else
                {
                    cout << "No pending tasks found.\n";
                }

                break;
            }

            case 4:
            {
                string name, newStatus;

                cout << "Enter task name: ";
                getline(cin >> ws, name);

                cout << "Enter new status: ";
                getline(cin, newStatus);

                updateTaskStatus(name, newStatus);
                break;
            }

            case 5:
            {
                string name;

                cout << "Enter task name to delete: ";
                getline(cin >> ws, name);

                deleteByName(name);
                break;
            }

            case 6:
                cout << "Exiting Task Manager...\n";
                break;

            default:
                cout << "Invalid choice!\n";
            }

        } while (choice != 6);
    }
    void mainMenu()
    {
        int choice;
        do
        {
            cout << "\n===== CIRCULAR LINKED LIST MENU =====\n";
            cout << "1. Insert At End\n";
            cout << "2. Display List\n";
            cout << "3. Josephus Problem\n";
            cout << "4. Exit\n";
            cout << "Enter choice: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
            {
                object value;
                cout << "Enter value: ";
                cin >> value;

                insertAtEnd(value);
                break;
            }

            case 2:
                display();
                break;

            case 3:
            {
                if (head == nullptr)
                {
                    cout << "List is empty!\n";
                    break;
                }

                int k;
                cout << "Enter counting value (k): ";
                cin >> k;

                if (k <= 0)
                {
                    cout << "k must be greater than zero!\n";
                    break;
                }

                object survivor = josephus(k);
                cout << "Survivor: " << survivor << '\n';
                break;
            }

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
            }

        } while (choice != 4);
    }
    void deleteByName(string target)
    {
        if (head == nullptr)
            return;

        Node<object> *current = head;
        Node<object> *previous = tail;

        do
        {
            if (current->data.name == target)
            {
                if (head == tail)
                {
                    delete current;
                    head = nullptr;
                    tail = nullptr;
                    return;
                }
                previous->next = current->next;

                if (current == head)
                    head = current->next;

                if (current == tail)
                    tail = previous;

                delete current;
                return;
            }
            previous = current;
            current = current->next;
        } while (current != head);
    }
    Node<object> *getpendingTask()
    {
        if (head == nullptr)
            return head;
        Node<object> *current = head;
        do
        {
            if (current->data.status == "Pending" || current->data.status == "pending")
            {
                return current;
            }
            current = current->next;
        } while (current != head);
        return nullptr;
    }

    void displayAllTasks()
    {
        if (head == nullptr)
        {
            cout << "No tasks available.\n";
            return;
        }

        Node<object> *current = head;
        do
        {
            current->data.display(current);
            current = current->next;
        } while (current != head);
    }

    void updateTaskStatus(string target, string newStatus)
    {
        if (head == nullptr)
        {
            cout << "Task list is empty.\n";
            return;
        }
        Node<object> *current = head;
        do
        {
            if (current->data.name == target)
            {
                current->data.status = newStatus;

                cout << "Task '" << target
                     << "' status updated to "
                     << newStatus << ".\n";
                return;
            }
            current = current->next;
        } while (current != head);
        cout << "Task not found.\n";
    }
};
int main()
{
    CircularLinkedList<int> *list = new CircularLinkedList<int>();

    list->insertAtEnd(10);
    list->insertAtEnd(20);
    list->insertAtEnd(30);
    list->insertAtEnd(40);
    list->insertAtEnd(50);
    list->insertAtEnd(60);
    list->insertAtEnd(70);

    list->mainMenu();

    CircularLinkedList<Task> *tasks = new CircularLinkedList<Task>();

    tasks->insertAtEnd(Task("High", "Complete DSA", "Pending"));
    tasks->insertAtEnd(Task("Medium", "Revise SQL", "Pending"));
    tasks->insertAtEnd(Task("Low", "Complete Lab", "Completed"));

    tasks->mainMenuTask();

    delete list;

    return 0;
}