// Pattern 04 - Inverted Star Triangle
// Output (n=5):
// *****
// ****
// ***
// **
// *

#include<iostream>
using namespace std;
int main(){

    int n;
    cout << "Enter number: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = n; j > i; j--)
            cout << "*";
        cout << endl;
    }

    return 0;
}
