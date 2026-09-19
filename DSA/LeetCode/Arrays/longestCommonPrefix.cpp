#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string prefix = "";
        for (int i = 0; i < strs[0].size(); i++)
        {
            char current = strs[0][i];            // took first char of first string
            for (int j = 1; j < strs.size(); j++) // start from index 1 and end at last
            {
                if (i > strs[j].size() || current != strs[j][i]) // must check bounds of bounds of checking and target strings
                {
                    return prefix;
                }
            }
            prefix += current;
        }
        return prefix;
    }
};
int main()
{
    cout << "======Longest Common Prefix=======\n";

    vector<string> words = {"Hello", "Hey", "Hew", "Hell"};
    Solution *lcp = new Solution();
    cout << lcp->longestCommonPrefix(words);
}