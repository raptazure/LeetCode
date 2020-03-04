/*
 * @lc app=leetcode.cn id=994 lang=javascript
 *
 * [994] 腐烂的橘子
 */

// @lc code=start
/**
 * @param {number[][]} grid
 * @return {number}
 */
var orangesRotting = function (grid) {
  let q = [];
  let newFresh = 0;
  let minutes = 0;
  // Push rotten oranges to the stack and count fresh oranges
  for (let i = 0; i < grid.length; i++) {
    for (let j = 0; j < grid[i].length; j++) {
      if (grid[i][j] === 2) q.push([i, j]);
      if (grid[i][j] === 1) newFresh++;
    }
  }

  while (q.length && newFresh) {
    let newQ = []; // queue for next minute
    while (q.length) {
      let badOrange = q.shift();
      let newRottens = infectOthers(grid, badOrange[0], badOrange[1], newQ);
      newFresh -= newRottens;
    }
    minutes++;
    q = newQ;
  }
  if (newFresh !== 0) return -1;
  return minutes;
};

// Infect surrounding oranges
// Return the number of newly infected oranges
var infectOthers = function (grid, i, j, q) {
  let infected = 0;
  if (i > 0 && grid[i - 1][j] === 1) {
    grid[i - 1][j]++;
    infected++;
    q.push([i - 1, j]);
  }
  if (j > 0 && grid[i][j - 1] === 1) {
    grid[i][j - 1]++;
    infected++;
    q.push([i, j - 1]);
  }
  if (i < grid.length - 1 && grid[i + 1][j] === 1) {
    grid[i + 1][j]++;
    infected++;
    q.push([i + 1, j]);
  }
  if (j < grid[0].length - 1 && grid[i][j + 1] === 1) {
    grid[i][j + 1]++;
    infected++;
    q.push([i, j + 1]);
  }

  return infected;
}
// @lc code=end