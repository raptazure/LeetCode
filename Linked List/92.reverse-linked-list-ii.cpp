/*
 * @lc app=leetcode id=92 lang=cpp
 *
 * [92] Reverse Linked List II
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m == n) return head;
        auto dummy = new ListNode(-1);
        dummy->next = head;
        auto a = dummy, d = dummy;
        for(int i = 0; i < m - 1; i++) a = a->next;
        for(int i = 0; i < n; i++) d = d->next;
        auto b = a->next, c = d->next, pre = b, cur = pre->next;
        while(cur != c)
        {
            auto next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        b->next = c;
        a->next = d;
        return dummy->next;   
    }
};
// @lc code=end

