/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int res = INT_MIN;
        int fn = -1;
        for(int i = 0; i < nums.size(); i++) {
            fn = max(nums[i], fn + nums[i]);
            res = max(fn, res);
        }
        return res;
    }
};
// @lc code=end

