/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input array is sorted
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size() - 1;
        while(l < r) {
            if(numbers[l] + numbers[r] == target) return {l + 1, r  +1 };
            else if(numbers[l] + numbers[r] < target) l++;
            else r--;
        }
        return {-1, -1};
    }
};
// @lc code=end

