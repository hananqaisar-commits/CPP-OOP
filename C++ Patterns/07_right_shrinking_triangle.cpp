// Pattern 07 - Right Aligned Shrinking Triangle
// Output (n=5):
// *****
//  ****
//   ***
//    **
//     *

#include<iostream>
using namespace std;
int main(){

    int n;
    cout << "Enter number: ";
    cin >> n;

    for (int i = n; i > 0; i--)
    {
        for (int j = 1; j <= n - i; j++)
            cout << " ";
        for (int k = 1; k <= i; k++)
            cout << "*";
        cout << endl;
    }

    return 0;
}
