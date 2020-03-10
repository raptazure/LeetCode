/*
 * @lc app=leetcode.cn id=543 lang=javascript
 *
 * [543] 二叉树的直径
 */

// @lc code=start
// 将直径转换为二叉树的每个节点的左右子树的高度和的最大值
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */
var diameterOfBinaryTree = function(root) {
  let res = 0;
  depth(root);
  return res;

  function depth(root) {
    if (!root) return -1;
    let left = root.left ? depth(root.left) + 1 : 0;
    let right = root.right ? depth(root.right) + 1 : 0;

    res = Math.max(left + right, res);
    return Math.max(left, right);
  }
};
// @lc code=end

