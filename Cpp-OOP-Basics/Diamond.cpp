#include <iostream>
using namespace std;

int main()
{
    int number;

    // Ask user how many rows the diamond should have
    cout << "How many number of rows? ";
    cin >> number;

    for (int i = 1; i <= number; i++) // i = current row
    {
        // Print spaces before stars
        for (int k = number; k > i; k--)
        {
            cout << " ";
        }

        // Print stars for this row
        for (int j = 0; j < 2 * i - 1; j++)
        {
            cout << "*";
        }

        cout << endl; // Move to next row
    }

    for (int i = number - 1; i >= 1; i--) // start from one row below middle
    {
        // Print spaces before stars
        for (int k = number; k > i; k--)
        {
            cout << " ";
        }

        // Print stars for this row
        for (int j = 0; j < 2 * i - 1; j++)
        {
            cout << "*";
        }

        cout <
