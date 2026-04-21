// Pattern 03 - Left Aligned Star Triangle
// Output (n=5):
// *
// **
// ***
// ****
// *****

#include <iostream>
using namespace std;

int main()
{
    int nu;
    cout << "Enter number to print pyramid pattern: ";
    cin >> nu;

    for (int i = 0; i < nu; i++)
    {
        for (int j = 0; j < (i + 1); j++)
        {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}