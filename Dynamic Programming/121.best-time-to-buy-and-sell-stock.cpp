/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.size() <= 1) return 0;
        int minInput = prices[0];
        int maxProfit = 0;
        for (int i = 0; i < prices.size(); i++) {
            minInput = min(prices[i], minInput);
            maxProfit = max(maxProfit, prices[i] - minInput);
        }
        return maxProfit;
    }
};
// @lc code=end
