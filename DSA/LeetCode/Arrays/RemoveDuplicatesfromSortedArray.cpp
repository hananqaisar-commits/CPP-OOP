#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int removeDuplicatesFromSorted(vector<int> &nums)
    {
        if (nums.empty())
        {
            cout << "Empty\n";
        }
        int current = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[current] != nums[i])
            {
                ++current;
                nums[current] = nums[i];
            }
        }
        return current + 1;
    }
};
int main()
{
    Solution *sol = new Solution();
    vector<int> array = {1, 1, 1, 1, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3};
    int upto = sol->removeDuplicatesFromSorted(array);
    cout << upto << endl;
    cout << "Now array remians:\n";

    for (int i = 0; i < upto; i++)
    {
        if (array.empty())
        {
            cout << "No element";
            break;
        }
        else
        {
            cout << array[i] << endl;
        }
    }

    return 0;
}