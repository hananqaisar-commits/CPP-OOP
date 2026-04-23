// Pattern 01 - Alphabet Triangle
// Output (n=4):
// A
// AB
// ABC
// ABCD

#include<iostream>
using namespace std;
int main(){

    int n;
    cout << "Enter any number: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        char alpha = 'A';
        for (int j = 0; j < (i + 1); j++)
        {
            cout << alpha;
            alpha++;
        }
        cout << endl;
    }

    return 0;
}
