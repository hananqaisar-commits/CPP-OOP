// Pattern 06 - Right Aligned Growing Triangle (Spaces + Stars)
// Output (n=6):
//       *
//      **
//     ***
//    ****
//   *****
//  ******

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
        for (int j = 1; j <= i; j++)
        {
            cout << " ";
        }
        // Print stars
        for (int k = i; k <= n; k++)
        {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}
