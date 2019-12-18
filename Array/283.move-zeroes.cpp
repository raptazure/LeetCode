/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int len = 0;
        vector<int> tmp;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != 0) {
                len++;
                tmp.push_back(nums[i]);
            }
        }
        for(int i = 0; i < len; i++) nums[i] = tmp[i];
        for(int i = len; i < nums.size(); i++) nums[i] = 0;
    }
};
// @lc code=end

