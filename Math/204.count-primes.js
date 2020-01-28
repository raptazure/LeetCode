/*
 * @lc app=leetcode.cn id=204 lang=javascript
 *
 * [204] 计数质数
 */

// @lc code=start
/**
 * @param {number} n
 * @return {number}
 */
var countPrimes = function (n) {
  const isPrime = (m) => {
    if (m < 2) return false;
    for (let i = 2; i * i <= m; i++) {
      if (m % i == 0) return false;
    }
    return true;
  }

  let cnt = 0;
  for (let i = 0; i < n; i++) {
    if (isPrime(i)) cnt++;
  }
  return cnt;
};
// @lc code=end