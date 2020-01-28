/*
 * @lc app=leetcode.cn id=202 lang=javascript
 *
 * [202] 快乐数
 */

// @lc code=start
/**
 * @param {number} n
 * @return {boolean}
 */
var isHappy = function (n) {
  let fast = n;
  let slow = n;

  const squareSum = (m) => {
    let sum = 0;
    while (m != 0) {
      sum += (m % 10) ** 2;
      m = parseInt(m / 10);
    }
    return sum;
  }
  do {
    slow = squareSum(slow);
    fast = squareSum(fast);
    fast = squareSum(fast);
  } while (slow != fast);
  return slow == 1;
};
// @lc code=end