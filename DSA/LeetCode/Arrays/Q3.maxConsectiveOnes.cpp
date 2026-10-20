#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int current = 0;
        int maxCount = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 1)
            {
                current++;
                maxCount = max(maxCount, current);
            }
            else
            {
                current = 0;
            }
        }
        return maxCount;
    }
};
int main()
{
    vector<int> array;

    array.push_back(2);
    array.push_back(2);
    array.push_back(3);
    array.push_back(1);
    array.push_back(1);
    array.push_back(1);

    Solution *sol = new Solution();
    int ans = sol->findMaxConsecutiveOnes(array);

    cout << ans << " ";
}
