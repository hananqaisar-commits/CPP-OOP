#include <iostream>
#include <vector>
#include <algorithm>
class Solution
{
public:
    int firstMissingPositive(std::vector<int> &nums)
    {
        int target = 1;

        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == target)
            {
                target++;
            }
        }
        return target;
    }
};
int main()
{
    Solution *sol = new Solution();
    std::vector<int> array = {1, 3, 4};
    std::cout << sol->firstMissingPositive(array);
}