#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> shuffle(vector<int> &nums, int n)
    {
        vector<int> ans;
        int k = n;
        for (int i = 0; i < nums.size(); i++)
        {
            // nums = [2,5,1,3,4,7], n = 3
            // 1. 2,3
            // 2. 5,4
            // 3. 1,7
            // mean ans: 2,3,5,4,1,7
            if (k < nums.size())
            {

                ans.push_back(nums[i]);
                ans.push_back(nums[k]);
                k++;
            }
            else
                break;
        }
        return ans;
    }
};
int main()
{
    vector<int> array;
    // nums = [2,5,1,3,4,7], n = 3
    array.push_back(2);
    array.push_back(5);
    array.push_back(1);
    array.push_back(3);
    array.push_back(4);
    array.push_back(7);
    Solution *sol = new Solution();
    vector<int> ans = sol->shuffle(array, 3);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}