/*
 * @lc app=leetcode id=747 lang=cpp
 *
 * [747] Largest Number At Least Twice of Others
 */

// @lc code=start
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        if(nums.size() <= 1) return 0;
        int max = nums[0], maxi = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > max) {
                max = nums[i];
                maxi = i;
            }
        }
        int res = -1;
        sort(nums.begin(), nums.end());
        if(max >= nums[nums.size() - 2] * 2) res = maxi;
        return res;
    }
};
// @lc code=end

