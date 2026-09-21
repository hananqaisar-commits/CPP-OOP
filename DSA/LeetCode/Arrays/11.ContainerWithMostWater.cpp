#include <iostream>
#include <vector>
#include <algorithm>
class Solution
{
public:
    int maxArea(std::vector<int> &height)
    {
        int width = 0;
        int lenght = 0;

        int first = 0;
        int last = height.size() - 1;

        int max = 0;
        while (first < last)
        {
            height[first] > height[last] ? lenght = height[last] : lenght = height[first]; // tenght will count of min side bcz water will not overflow
            width = last - first;
            if (lenght * width > max)
            {
                max = lenght * width; // then assign max area
            }

            if (height[first] > height[last]) // if first ione is greater then last then move last side otherwise right side
            {
                last--; // move last pointer
            }
            else
            {
                first++; // now move if first is less then or equal to then move first pointer
            }
        }
        return max;
    }
};
int main()
{

    Solution *sol = new Solution();
    std::vector<int> array = {1, 1};
    std::cout << sol->maxArea(array);
    return 0;
}