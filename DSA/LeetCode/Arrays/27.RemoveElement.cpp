#include <iostream>
#include <vector>
class Solution
{
public:
    int removeElement(std::vector<int> &nums, int val)
    {
        int k = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != val)
            {
                nums[k] = nums[i]; // which valkue is not equal to val then add that value to nums[k] and increase k counter
                k++;
            }
        }
        return k;
    }
};
int main()
{
    Solution *sol = new Solution();
    std::vector<int> array = {1, 2, 4, 4, 2, 3, 42, 1, 4, 5};
    int k = sol->removeElement(array, 4);
    for (int i = 0; i < k; i++)
    {
        std::cout << array[i] << std::endl;
    }

    return 0;
}