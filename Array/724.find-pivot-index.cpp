/*
 * @lc app=leetcode id=724 lang=cpp
 *
 * [724] Find Pivot Index
 */

// @lc code=start
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0, lsum = 0, result = -1;
        for(int i = 0; i < nums.size(); i++) sum += nums[i];
        for(int i = 0; i < nums.size(); i++) {
            lsum += nums[i];
            if(lsum - nums[i] == sum - lsum) {
                result = i;
                break;
            }
        }
        return result;
    }
};
// @lc code=end

