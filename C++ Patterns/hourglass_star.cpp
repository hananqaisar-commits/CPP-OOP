// Pattern 05 - Hourglass Star (Inverted + Normal Triangle)
// Output (n=5):
// *****
// ****
// ***
// **
// *
// *
// **
// ***
// ****
// *****

#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter any number to print pyramid of both: ";
    cin >> n;

    // Inverted triangle (top half)
    for (int i = 0; i < n; i++)
    {
        for (int j = n; j > i; j--)
        {
            cout << "*";
        }
        cout << endl;
    }

    // Normal triangle (bottom half)
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < (i + 1); j++)
        {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}
