#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

class Solution
{
public:
    int threeSumClosest(std::vector<int> &nums, int target)
    {
        std::vector<int> allTripletsSum;
        int tripletsSum;

        int first, last;
        int closest = -99999999;
        int sum;
        std::sort(nums.begin(), nums.end()); // sorting i took all elements of triplet and sort to check duplicates

        for (int i = 0; i < nums.size(); i++)
        {
            first = i + 1; // move every time first to very next element of i
            last = nums.size() - 1;
            while (first < last) // jab tak first is less then last hai sara pairs check kro for i in next loop i will i+1 anf then we will again check all pairs for i+1 and soo until i<size
            {
                tripletsSum = nums[i] + nums[first] + nums[last];
                allTripletsSum.push_back(tripletsSum);
                if (tripletsSum >= target)
                {
                    last--;
                }
                else if (tripletsSum < target)
                {
                    first++;
                }
            }
        }
        // for (int i = 0; i < allTripletsSum.size(); i++)
        // {
        //     if (allTripletsSum[i] < target && allTripletsSum[i] > closest)
        //     {
        //         closest = allTripletsSum[i];
        //     }
        //     else if (allTripletsSum[i] > target && allTripletsSum[i] < closest)
        //     {
        //         closest = allTripletsSum[i];
        //     }
        // }

        int difference = INT_MAX;

        for (int i = 0; i < allTripletsSum.size(); i++)
        {
            if (difference > std::abs(allTripletsSum[i] - target)) // abs mean absolute it like mode no sign of positive or negatve
            {
                difference = std::abs(allTripletsSum[i] - target);
                closest = allTripletsSum[i];
            }
        }

        return closest;
    }
};

int main()
{
    Solution *sol = new Solution();

    std::vector<int> sample = {
        1, 2, 3, 4, 5, 5, 6,
        -5, -4, -3, -2, -1};
    int calculated = sol->threeSumClosest(sample, 4);

    std::cout << calculated << std::endl;

    delete sol;
}