/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<vector<int>> dirs{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<int> res;
        int nr = matrix.size(); if(nr == 0) return res;
        int nc = matrix[0].size(); if(nc == 0) return res;
        vector<int> nSteps {nc, nr - 1};
        int iDirs = 0;
        int ir = 0, ic = -1;
        while(nSteps[iDirs % 2]) {
            for(int i = 0; i < nSteps[iDirs % 2]; ++i) {
                ir += dirs[iDirs][0];
                ic += dirs[iDirs][1];
                res.push_back(matrix[ir][ic]);
            }
            nSteps[iDirs % 2]--;
            iDirs = (iDirs + 1) % 4;
        }
        return res;
    }
};
// @lc code=end

