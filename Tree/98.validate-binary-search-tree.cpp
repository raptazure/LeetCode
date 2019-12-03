/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return dfs(root, INT_MIN, INT_MAX);
    }
    bool dfs(TreeNode* root, long long minv, long long maxv) {
        if(!root) return true;
        if(root->val < minv || root->val > maxv) return false;
        return dfs(root->left, minv, root->val - 1ll) && dfs(root->right, root->val + 1ll, maxv);
    }
};
// @lc code=end

