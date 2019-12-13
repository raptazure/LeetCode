/*
 * @lc app=leetcode id=96 lang=cpp
 *
 * [96] Unique Binary Search Trees
 */

// @lc code=start
class Solution {
public:
    int numTrees(int n) {
        // integer overflow
        long long c = 1;
        // catalan
        for(int i = 0; i < n; i++) {
            c = c * 2 * (2 * i + 1) / (i + 2);
        }
        return c;
    }
};
// @lc code=end

