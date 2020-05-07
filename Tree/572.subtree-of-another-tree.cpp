/*
 * @lc app=leetcode.cn id=572 lang=cpp
 *
 * [572] 另一个树的子树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    bool isSubtree(TreeNode *s, TreeNode *t)
    {
        if (s == nullptr)
            return false;
        if (dfs(s, t))
            return true;
        return (isSubtree(s->left, t) || isSubtree(s->right, t));
    }

    bool dfs(TreeNode *s, TreeNode *t)
    {
        if (s == nullptr && t == nullptr)
            return true;
        if (s == nullptr || t == nullptr)
            return false;
        if (s->val != t->val)
            return false;
        return (dfs(s->left, t->left) && dfs(s->right, t->right));
    }
};
// @lc code=end
