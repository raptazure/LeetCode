/*
 * @lc app=leetcode.cn id=771 lang=javascript
 *
 * [771] 宝石与石头
 */

// @lc code=start
/**
 * @param {string} J
 * @param {string} S
 * @return {number}
 */
var numJewelsInStones = function (J, S) {
  let cnt = 0
  for (let i = 0; i < S.length; i++) {
    if (J.includes(S[i])) {
      cnt++
    }
  }
  return cnt
};
// @lc code=end