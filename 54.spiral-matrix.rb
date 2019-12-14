#
# @lc app=leetcode id=54 lang=ruby
#
# [54] Spiral Matrix
#

# @lc code=start
# @param {Integer[][]} matrix
# @return {Integer[]}
def spiral_order(matrix)
    matrix[0] ? matrix.shift + spiral_order(matrix.transpose.reverse) : []  
end
# @lc code=end

