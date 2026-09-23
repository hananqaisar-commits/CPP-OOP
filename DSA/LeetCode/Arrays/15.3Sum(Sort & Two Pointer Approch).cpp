#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    std::vector<std::vector<int>> threeSum(std::vector<int> &nums)
    {
        std::vector<std::vector<int>> allTriplets;
        std::vector<int> triplets;

        int first, last;

        std::sort(nums.begin(), nums.end()); // sorting i took all elements of triplet and sort to check duplicates

        for (int i = 0; i < nums.size(); i++)
        {
            first = i + 1; // move every time first to very next element of i
            last = nums.size() - 1;

            while (first < last) // jab tak first is less then last hai sara pairs check kro
            {
                int sum = nums[i] + nums[first] + nums[last];

                if (sum == 0)
                {
                    triplets = {nums[i], nums[first], nums[last]};

                    bool duplicate = false;
                    for (int l = 0; l < allTriplets.size(); l++) // check ke pehlay se alltriplets mei triple exist klrta hai ya nai
                    {
                        if (allTriplets[l][0] == triplets[0] &&
                            allTriplets[l][1] == triplets[1] &&
                            allTriplets[l][2] == triplets[2])
                        {
                            duplicate = true;
                            break;
                        }
                    }

                    if (!duplicate)
                        allTriplets.push_back(triplets);

                    // now move the pointers
                    first++;
                    last--;
                }
                else if (sum > 0)
                {
                    last--;
                }
                else if (sum < 0)
                {
                    first++;
                }
            }
        }

        return allTriplets;
    }
};

int main()
{
    Solution *sol = new Solution();

    std::vector<int> sample = {
        1, 2, 3, 4, 5, 5, 6,
        -5, -4, -3, -2, -1};

    std::vector<std::vector<int>> calculated = sol->threeSum(sample);

    for (std::vector<int> x : calculated)
    {
        for (int value : x)
        {
            std::cout << value << " ";
        }

        std::cout << std::endl;
    }

    delete sol;
}