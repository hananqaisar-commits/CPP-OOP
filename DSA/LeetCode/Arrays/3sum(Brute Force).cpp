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

        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                for (int k = j + 1; k < nums.size(); k++)
                {
                    if (nums[i] + nums[j] + nums[k] == 0)
                    {
                        triplets = {nums[i], nums[j], nums[k]};

                        std::sort(triplets.begin(), triplets.end()); // sorting i took all elements of triplet and sort to check duplicates

                        bool duplicate = false;

                        for (int l = 0; l < allTriplets.size(); l++)
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
                        {
                            allTriplets.push_back(triplets);
                        }
                    }
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