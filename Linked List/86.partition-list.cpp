/*
 * @lc app=leetcode id=86 lang=cpp
 *
 * [86] Partition List
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
    ListNode* partition(ListNode* head, int x) {
        auto dummy1 = new ListNode(-1);
        auto dummy2 = new ListNode(-1);
        auto p = head;
        auto cur1 = dummy1, cur2 = dummy2;
        while(p)
        {
            if(p->val < x)
            {
                cur1->next = p;
                cur1 = cur1->next;
            }
            else
            {
                cur2->next = p;
                cur2 = cur2->next;
            }
            p = p->next;
        }
        cur2->next = NULL;
        cur1->next = dummy2->next;
        return dummy1->next; 
    }
};
// @lc code=end

