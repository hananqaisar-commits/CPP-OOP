// Pattern 06 - Right Aligned Growing Triangle
// Output (n=6):
//       *
//      **
//     ***
//    ****
//   *****
//  ******

#include<iostream>
using namespace std;
int main(){

    int n;
    cout << "Enter number: ";
    cin >> n;

    for (int i = n; i > 0; i--)
    {
        for (int j = 1; j <= i; j++)
            cout << " ";
        for (int k = i; k <= n; k++)
            cout << "*";
        cout << endl;
    }

    return 0;
}
