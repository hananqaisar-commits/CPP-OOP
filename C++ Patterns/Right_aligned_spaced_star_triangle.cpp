// Pattern 08 - Right Aligned Spaced Star Triangle
// Output (n=6):
//       * 
//      * *
//     * * *
//    * * * *
//   * * * * *
//  * * * * * *

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
        // Print stars with spaces between them
        for (int k = i; k <= n; k++)
        {
            cout << "* ";
        }
        cout << endl;
    }

    return 0;
}
