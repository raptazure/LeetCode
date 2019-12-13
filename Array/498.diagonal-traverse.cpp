/*
 * @lc app=leetcode id=498 lang=cpp
 *
 * [498] Diagonal Traverse
 */

// @lc code=start
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if(matrix.empty()) return {};
        vector<int> res;
        int n = matrix.size(), m = matrix[0].size();
        for(int i = 0; i < n + m - 1; i++) {
            if(1 & i) {
                for(int j = min(i, m - 1); j >= max(i - n + 1, 0); j--)
                    res.push_back(matrix[i - j][j]);
            } else {
                for(int j = max(i - n + 1, 0); j <= min(i, m - 1); j++)
                    res.push_back(matrix[i - j][j]);
            }
        }
        return res;
    }
};
// @lc code=end

