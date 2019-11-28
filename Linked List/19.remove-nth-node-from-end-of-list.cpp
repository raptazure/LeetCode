/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       auto dummy = new ListNode(-1);
       dummy->next = head;
       auto first = dummy, second =dummy;
       while(n--) first = first->next;
       while(first->next)
       {
           first = first->next;
           second = second->next;
       }
       second->next = second->next->next;
       return dummy->next;
    }
};
// @lc code=end

