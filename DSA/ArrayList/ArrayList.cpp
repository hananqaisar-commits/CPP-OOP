#include <iostream>
using namespace std;

class ArrayList
{
private:
    int *data;
    int capacity;
    int size;

public:
    ArrayList()
    {
        capacity = 2; // give capacity of 2 by default
        size = 0;
        data = new int[capacity]; // allocate space in heap and then pointer will point that memory in heap
    }

    void resize()
    {
        int newcapacity = capacity * 2; // new capcity will 2 times to previous capacity
        int *newdata = new int[newcapacity];
        capacity = newcapacity;

        for (int i = 0; i < size; i++) // copy all values from data to newdata
        {
            newdata[i] = data[i];
        }

        delete[] data; // now delete the memory of old data
        data = newdata;
    }

    void insertAtEnd(int value)
    {
        if (size == capacity)
        {
            resize();
        }

        data[size] = value; // insert value at last of all data
        size++;
    }
    void insertAtStart(int value)
    {
        if (size == capacity)
        {
            resize(); // resize it first then insert at start
        }

        for (int i = size; i > 0; i--)
        {
            data[i] = data[i - 1];
        }

        data[0] = value; // insert index at start of arraylist
        size++;          // now increase the size
    }
    void display(ArrayList &arraylist) // it is referencing to *arraylist mean alias of pointer
    {
        for (int i = 0; i < arraylist.size; i++)
        {
            cout << arraylist.data[i] << endl;
        }
    }
    void deleteAtIndex(int index)
    {
        if (index == capacity) // index-1 bcz the counting start from 0
        {
            cout << "Index is out of range" << endl;
            return;
        }
        else
        {
            for (int i = index; i < size - 1; i++)
            {
                data[i] = i + 1; // move values backward by 1 index after the index given by user
            }
            size--;
        }
    }
    void deleteFromEnd()
    {
        if (size == 0) // if list is empty then
        {
            cout << "ArrayList already empty" << endl;
            return;
        }
        size--; // just decrease the size no further need
    }

    void deleteFromStart()
    {
        for (int i = 0; i < size - 1; i++)
        {
            data[i] = data[i + 1];
        }
        size--;
    }
    void insertBefore(int value, int beforeValue)
    {
        for (int i = 0; i < size; i++)
        {
            if (data[i] == beforeValue && i != 0) // check whole arraylist and after matching the value move whole indexes forward 1 by 1
            {
                if (size == capacity)
                {
                    resize();
                }
                for (int j = size; j > i; j--)
                {
                    data[j] = data[j - 1]; // now shift all vlaues 1 by 1 to right side
                }
                data[i] = value; // now assign a value to that index
                size++;          // increase the counter size

                return; // IMPORTANT
            }
        }
    }
    void insertAfter(int value, int afterValue)
    {
        for (int i = 0; i < size; i++)
        {
            if (data[i] == afterValue)
            {
                if (size == capacity)
                {
                    resize();
                }

                for (int j = size; j > i; j--)
                {
                    data[j] = data[j - 1];
                }

                data[i + 1] = value;
                size++;

                return;
            }
        }
    }
    void deleteValue(int value)
    {
        for (int i = 0; i < size; i++)
        {
            if (data[i] == value)
            {
                if (i == (size - 1)) // if it will be last index then just decrease the size counter by 1
                {
                    size--;
                    return;
                }

                for (int j = i; j < size - 1; j++) // otehrwise move all right values to lleft 1 by 1 index and then decrease the size
                {
                    data[j] = data[j + 1];
                }
                size--;
                return;
            }
        }
    }
    int linearSearch(int value)
    {
        int i = 0;
        while (i < size)
        {
            if (data[i] == value)
            {
                return i;
            }

            i++;
        }

        return -1;
    }
};
int summation(int start, int end)
{
    int sum = 0;

    for (int i = start; i <= end; i++)
    {
        sum += i * i;
    }

    return sum;
}
void menu(ArrayList &arraylist)
{
    int choice;

    while (true)
    {
        cout << "\n========== ARRAY LIST MENU ==========\n";
        cout << "1. Insert at End\n";
        cout << "2. Insert at Start\n";
        cout << "3. Insert After Specific Value\n";
        cout << "4. Insert Before Specific Value\n";
        cout << "5. Display Array List\n";
        cout << "6. Delete from End\n";
        cout << "7. Delete from Start\n";
        cout << "8. Delete Specific Value\n";
        cout << "9. Linear Search\n";
        cout << "0. Exit\n";
        cout << "====================================\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int value;

            cout << "Enter value: ";
            cin >> value;

            arraylist.insertAtEnd(value);

            cout << "Value inserted at end.\n";
            break;
        }

        case 2:
        {
            int value;

            cout << "Enter value: ";
            cin >> value;

            arraylist.insertAtStart(value);

            cout << "Value inserted at start.\n";
            break;
        }

        case 3:
        {
            int value, afterValue;

            cout << "Enter value to insert: ";
            cin >> value;

            cout << "Enter value after which to insert: ";
            cin >> afterValue;

            arraylist.insertAfter(value, afterValue);

            break;
        }

        case 4:
        {
            int value, beforeValue;

            cout << "Enter value to insert: ";
            cin >> value;

            cout << "Enter value before which to insert: ";
            cin >> beforeValue;

            arraylist.insertBefore(value, beforeValue);

            break;
        }

        case 5:
        {
            arraylist.display(arraylist);
            break;
        }

        case 6:
        {
            arraylist.deleteFromEnd();

            cout << "Deleted from end.\n";
            break;
        }

        case 7:
        {
            arraylist.deleteFromStart();

            cout << "Deleted from start.\n";
            break;
        }

        case 8:
        {
            int value;

            cout << "Enter value to delete: ";
            cin >> value;

            arraylist.deleteValue(value);

            break;
        }

        case 9:
        {
            int value;

            cout << "Enter value to search: ";
            cin >> value;

            int index = arraylist.linearSearch(value);

            if (index != -1)
            {
                cout << "Value found at index: " << index << endl;
            }
            else
            {
                cout << "Value not found.\n";
            }

            break;
        }

        case 0:
        {
            cout << "Program ended.\n";
            return;
        }

        default:
        {
            cout << "Invalid choice. Try again.\n";
        }
        }
    }
}
void activities()
{
    cout << "=====Activity 1=====" << endl;
    cout << "Hello World!" << endl;

    cout << endl;
    cout << "=====Activity 2=====" << endl;
    float a = 5.5;
    int b(3);
    int c(2);
    float result;
    a = a + b;
    result = a - c;
    cout << result;
    cout << endl;
    cout << "=====Activity 3=====" << endl;
    int x;
    cout << "Type a number: ";
    cin >> x;
    cout << "Your number is: " << x;
    cout << endl;
    cout << "=====Activity 4=====" << endl;
    string mystring;
    mystring = "This is the initial string content";
    cout << mystring << endl;
    mystring = "This is a different string content";
    cout << mystring << endl;
    cout << "=====Activity 5=====" << endl;
    int a2;
    int b2 = 3;
    a2 = b2;
    a += 2;
    cout << a << endl;
    cout << "=====Activity 6=====" << endl;
    int a3, b3, c3;
    a3 = 2;
    b3 = 7;
    c3 = (a3 > b3) ? a3 : b3;
    cout << c3 << endl;
    cout << "=====Activity 7=====" << endl;
    int x1;
    cout << "Enter the number x:";
    cin >> x1;
    if (x1 > 0)
        cout << "x is positive" << endl;
    else if (x1 < 0)
        cout << "x is negative" << endl;
    else
        cout << "x is 0" << endl;

    cout << "=====Activity 8=====" << endl;
    int n = 10;
    while (n > 0)
    {
        cout << n << ",";
        --n;
    }
    cout << "liftoff!" << endl;
    cout << "=====Activity 9=====" << endl;
    string str;
    cin >> ws;
    do
    {
        cout << "Enter text(by to exit): ";
        getline(cin, str);
        cout << "You Entered: " << str << endl;
    } while (str != "by");

    cout << "=====Activity 10=====" << endl;
    int day = 4;
    switch (day)
    {
    case 1:
        cout << "Monday";
        break;
    case 2:
        cout << "Tuesday";
        break;
    case 3:
        cout << "Wednesday";
        break;
    case 4:
        cout << "Thursday";
        break;
    case 5:
        cout << "Friday";
        break;
    case 6:
        cout << "Saturday";
        break;
    case 7:
        cout << "Sunday";
        break;
    default:
        cout << "Enter valid day";
    }

    cout << "=====Activity 12=====" << endl;
    int foo[] = {16, 2, 77, 40, 12071};
    int n1, result1 = 0;
    for (n1 = 0; n1 < 5; ++n1)
    {
        result1 += foo[n1];
    }

    cout << result1;
}
int main()
{

    int start, end;
    ArrayList *arraylist = new ArrayList();

    menu(*arraylist);
    // SUMMATION

    cout << "SUMMATION PROGRAMME(Task 1): " << endl;
    cout << "\nEnter starting value: ";
    cin >> start;

    cout << "Enter ending value: ";
    cin >> end;

    cout << "Normal Summation: " << summation(start, end) << endl;

    cout << "Activities (Task 3): " << endl;
    activities();
}