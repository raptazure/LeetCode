/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 */

// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res;
        int t = 0;
        for(int i = digits.size() - 1; i >= 0; i--) {
            t += digits[i];
            if(i == digits.size() - 1) t += 1;
            res.push_back(t % 10);
            t /= 10;
        }
        if(t) res.push_back(1);
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end

