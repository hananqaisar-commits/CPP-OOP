#include <iostream>
#include <vector>

class Solution
{
public:
    double findMedianSortedArrays(std::vector<int> &nums1, std::vector<int> &nums2)
    {
        std::vector<int> mergedArray;
        int i = 0; // this is counter for nums1
        int j = 0; // this is counter for just nums2
        while (i < nums1.size() && j < nums2.size())
        {
            if (nums1[i] <= nums2[j]) // idf nums[i] is less then or wqual to the nums[j] then add in mergedarray and increase i counter and same in else condition increase counter of j
            {
                mergedArray.push_back(nums1[i]);
                i++;
            }
            else
            {
                mergedArray.push_back(nums2[j]);
                j++;
            }
        }
        while (i < nums1.size()) // remaining elements of nums1
        {
            mergedArray.push_back(nums1[i]);
            i++;
        }
        while (j < nums2.size()) // now remaining elements of nums2
        {
            mergedArray.push_back(nums2[j]);
            j++;
        }
        double median = 0.0;
        int centre, leftCentre, size;

        size = mergedArray.size() / 2;
        if (mergedArray.size() % 2 == 0)
        {

            // centre will access the value of merged array e.g:8 mean assign 4th index value to centre and then 3 index value to left centre
            centre = mergedArray[size];
            leftCentre = mergedArray[size - 1];
            return (centre + leftCentre) / 2.0;
        }
        else
        {
            return mergedArray[size];
        }
    }
};
int main()
{

    Solution *sol = new Solution();
    std::vector<int> nums1 = {1, 3};
    std::vector<int> nums2 = {2, 4};

    std::cout << sol->findMedianSortedArrays(nums1, nums2);
}