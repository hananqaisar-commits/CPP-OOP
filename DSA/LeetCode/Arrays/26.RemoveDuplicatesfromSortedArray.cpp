#include <iostream>
#include <vector>

class Solution
{
public:
    int removeDuplicatesFromSorted(std::vector<int> &nums)
    {
        if (nums.empty())
        {
            std::cout << "Empty\n";
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
    std::vector<int> array = {1, 1, 1, 1, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3};
    int upto = sol->removeDuplicatesFromSorted(array);
    std::cout << upto << std::endl;
    std::cout << "Now array remians:\n";

    for (int i = 0; i < upto; i++)
    {
        if (array.empty())
        {
            std::cout << "No element";
            break;
        }
        else
        {
            std::cout << array[i] << std::endl;
        }
    }

    return 0;
}