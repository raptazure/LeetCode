/*
 * @lc app=leetcode id=104 lang=java
 *
 * [104] Maximum Depth of Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    int depth = 1;
    public int maxDepth(TreeNode root) {
        if(root == null) return 0;      
        if(root.left == null && root.right == null) return depth;
        return 1 + Math.max(maxDepth(root.left), maxDepth(root.right));
    }
}
// @lc code=end

