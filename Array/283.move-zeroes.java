/*
 * @lc app=leetcode.cn id=283 lang=java
 *
 * [283] 移动零
 */

// @lc code=start
class Solution {
    public void moveZeroes(int[] nums) {
        int index = 0;
        for(int num : nums) {
            if(num != 0) {
                nums[index++] = num;
            }
        }
        while(index < nums.length) {
            nums[index++] = 0;
        }
    }
}
// @lc code=end

