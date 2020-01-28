/*
 * @lc app=leetcode.cn id=204 lang=cpp
 *
 * [204] ????
 */

// @lc code=start
class Solution
{
public:
    int countPrimes(int n)
    {
        int count = 0;
        vector<bool> signs(n, true);
        for (int i = 2; i < n; i++)
        {
            if (signs[i])
            {
                count++;
                for (int j = i + i; j < n; j += i)
                {
                    signs[j] = false;
                }
            }
        }
        return count;
    }
};
// @lc code=end
