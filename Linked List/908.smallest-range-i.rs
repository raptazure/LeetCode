/*
 * @lc app=leetcode.cn id=908 lang=rust
 *
 * [908] 最小差值 I
 */

// @lc code=start
impl Solution {
    pub fn smallest_range_i(a: Vec<i32>, k: i32) -> i32 {
        let max = a.iter().max().unwrap();
        let min = a.iter().min().unwrap();
        let result = max - min - 2 * k;
        if result < 0 {
            return 0
        }
        return result;
    }
}
// @lc code=end

