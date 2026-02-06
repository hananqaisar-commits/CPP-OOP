#include <iostream>
#include <string>
using namespace std;

int main()
{
    // char word[1000];
    // cin.getline(word, 1000);
    
    string word;
    cout << "Enter word: ";
    getline(cin, word);
    
    int count = 1;
    for (int i = 0; word[i] != '\0'; i++)
    {
        if (word[i] == ' ')
        {
            ++count;
        }
    }
    cout << "There are " << count << " words" << endl;

    return 0;
}