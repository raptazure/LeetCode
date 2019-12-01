/*
 * @lc app=leetcode id=61 lang=cpp
 *
 * [61] Rotate List
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
    ListNode* rotateRight(ListNode* head, int k) {
        auto first = head, second = head;
        int n = 1;
        if(!head) return head;
        for(auto p = head; p->next; p = p->next)
            n++;
        k %= n;
        while(k--)
            first = first->next;
        while(first->next)
        {
            second = second->next;
            first = first->next;
        }
        first->next = head;
        head = second->next;
        second->next = NULL;
        return head;
    }
};
// @lc code=end

