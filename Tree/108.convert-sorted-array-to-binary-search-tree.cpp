/*
 * @lc app=leetcode id=108 lang=cpp
 *
 * [108] Convert Sorted Array to Binary Search Tree
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArray2BST(nums, 0, nums.size() - 1);
    }
    TreeNode* sortedArray2BST(vector<int>& nums, int l, int r) {
        if(r < l) return NULL;
        int mid = l + r >> 1;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = sortedArray2BST(nums, l, mid - 1);
        root->right = sortedArray2BST(nums, mid + 1, r);
        return root;
    }
};
// @lc code=end

