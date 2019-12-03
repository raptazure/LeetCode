/*
 * @lc app=leetcode id=203 lang=cpp
 *
 * [203] Remove Linked List Elements
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
    ListNode* removeElements(ListNode* head, int val) {
        auto dummy = new ListNode(-8);
        dummy->next  = head;
        auto cur = dummy, pre = dummy;
        while(cur->next)
        {
            if(cur->val != val)
                pre = cur;
            cur = cur->next;
            if(cur->val == val)
                pre->next = cur->next;
        }
        return dummy->next;
    }
};
// @lc code=end

