#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> getConcatenation(vector<int> &nums)
    {
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++)
        {
            ans.push_back(nums[i]);
        }
        for (int j = 0; j < nums.size(); j++)
        {
            ans.push_back(nums[j]);
        }

        return ans;
    }
};
int main()
{
    vector<int> array;
    array.push_back(1);
    array.push_back(2);
    Solution *sol = new Solution();
    vector<int> ans = sol->getConcatenation(array);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}