// Pattern 02 - Continuous Alphabet Grid
// Output (n=3):
// ABC
// DEF
// GHI

#include <iostream>
using namespace std;

int main()
{
    int n;
    char ch = 'A';
    cout << "Enter any no to print pattern of characters: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << ch;
            ch++;
        }
        cout << endl;
    }

    return 0;
}