/*
 * @lc app=leetcode.cn id=402 lang=cpp
 *
 * [402] 移掉K位数字
 */

// @lc code=start
class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        vector<char> stk;
        for (auto &digit : num)
        {
            while (stk.size() > 0 && stk.back() > digit && k)
            {
                stk.pop_back();
                k -= 1;
            }
            stk.push_back(digit);
        }

        for (; k > 0; --k)
        {
            stk.pop_back();
        }

        string ans = "";
        bool isLeadingZero = true;
        for (auto &digit : stk)
        {
            if (isLeadingZero && digit == '0')
            {
                continue;
            }
            isLeadingZero = false;
            ans += digit;
        }
        return ans == "" ? "0" : ans;
    }
};
// @lc code=end
