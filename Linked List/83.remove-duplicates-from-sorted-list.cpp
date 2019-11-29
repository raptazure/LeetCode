/*
 * @lc app=leetcode id=83 lang=cpp
 *
 * [83] Remove Duplicates from Sorted List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        auto cur = head;
        while(cur)
        {
            if(cur->next && cur->next->val == cur->val)
                cur->next = cur->next->next;
            else cur = cur->next;
        }
        return head;
    }
};
// @lc code=end

