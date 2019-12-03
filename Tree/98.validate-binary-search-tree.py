#
# @lc app=leetcode id=98 lang=python3
#
# [98] Validate Binary Search Tree
#

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        return self.dfs(root, float('-inf'), float('inf'))
    def dfs(self, root, minv, maxv):
        if not root:
            return True
        if root.val > maxv or root.val < minv:
            return False
        return self.dfs(root.left, minv, root.val - 1) and self.dfs(root.right, root.val + 1, maxv)
    
# @lc code=end

