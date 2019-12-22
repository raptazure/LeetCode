/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */

// @lc code=start
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if(m < 1 || n < 1) return 0;
        long dp[m][n];
        if(obstacleGrid[0][0] == 1) return 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0 && j == 0) dp[i][j] = 1;
                else if(i == 0 && j != 0) dp[i][j] = (1 == obstacleGrid[i][j] ? 0 : dp[i][j - 1]);
                else if(i != 0 && j == 0) dp[i][j] = (1 == obstacleGrid[i][j] ? 0 : dp[i - 1][j]);
                else dp[i][j] = (1 == obstacleGrid[i][j] ? 0 : dp[i][j - 1] + dp[i - 1][j]);
            }
        }
        return dp[m - 1][n - 1];
    }
};
// @lc code=end

