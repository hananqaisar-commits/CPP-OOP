#include <iostream>
using namespace std;

int *maxArray(int *arr)
{
    int *maxptr = arr;
    for (int i = 0; i < 4; i++)
    {
        if (*(arr + i) > *maxptr)
            *maxptr = *(arr + i);
    }
    return maxptr;
}
int main()
{
    int array[4];
    for (int i = 0; i < 4; i++)
    {
        cout << "Enter index value: \n";
        cin >> array[i];
    }
    cout << "=====================\n";
    cout << *maxArray(array); // it will receive a address then dereference that
    return 0;
}
