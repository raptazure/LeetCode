/*
 * @lc app=leetcode.cn id=695 lang=javascript
 *
 * [695] 岛屿的最大面积
 */

// @lc code=start
/**
 * @param {number[][]} grid
 * @return {number}
 */
var maxAreaOfIsland = function(grid) {
  let row = grid.length, col = grid[0].length;
  let max = 0;
  for (let i = 0; i < row; i++) {
    for (let j = 0; j < col; j++) {
      if (grid[i][j] === 1) {
        max = Math.max(max, cntArea(grid, i, j, row, col));
      }
    }
  }
  return max;
};

const cntArea = (grid, i, j, row, col) => {
  if (i < 0 || i>= row || j < 0 || j >= col || grid[i][j] === 0) {
    return 0;
  }
  let cnt = 1;
  grid[i][j] = 0;
  cnt += cntArea(grid, i + 1, j, row, col);
  cnt += cntArea(grid, i - 1, j, row, col);
  cnt += cntArea(grid, i, j + 1, row, col);
  cnt += cntArea(grid, i, j - 1, row, col);
  return cnt;
}
// @lc code=end

