// Pattern 07 - Right Aligned Shrinking Triangle
// Output (n=5):
// *****
//  ****
//   ***
//    **
//     *

#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter any number to print pattern: ";
    cin >> n;

    for (int i = n; i > 0; i--)
    {
        // Print spaces
        for (int j = 1; j <= n - i; j++)
        {
            cout << " ";
        }
        // Print stars
        for (int k = 1; k <= i; k++)
        {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}
