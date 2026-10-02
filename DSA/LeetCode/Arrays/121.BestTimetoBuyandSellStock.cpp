#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int buy = 10000000;
        int sell = -1;
        int max = 0;
        int maxProfit = 0;
        for (int i = 0; i < prices.size() - 1; i++)
        {
            if (prices[i] < buy)
            {
                buy = prices[i];
            }
            if (prices[i + 1] > buy)
            {
                sell = prices[i + 1];
                max = sell - buy;
            }
            if (max > maxProfit)
            {
                maxProfit = max;
            }
        }
        return maxProfit;
    }
};
int main()
{
    vector<int> prices = {7, 5, 3, 2, 1};
    Solution *obj = new Solution();
    int result = obj->maxProfit(prices);

    cout << "Maximum Profit: " << result << endl;

    return 0;
}