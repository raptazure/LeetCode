/*
 * @lc app=leetcode id=109 lang=cpp
 *
 * [109] Convert Sorted List to Binary Search Tree
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    ListNode* findMiddle(ListNode* head)
    {
        auto fast = head;
        auto slow = head;
        ListNode* prev = NULL;
        while(fast && fast->next)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if(prev) prev->next = NULL;
        return slow;
    }
    TreeNode* sortedListToBST(ListNode* head)
    {
        if(!head) return NULL;
        auto mid = findMiddle(head);
        auto node = new TreeNode(mid->val);
        if(head == mid) return node;
        node->left = sortedListToBST(head);
        node->right = sortedListToBST(mid->next);
        return node;
    }
};

// @lc code=end

