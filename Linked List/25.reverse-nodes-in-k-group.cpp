/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL) return NULL;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* pretail = dummy;
        while(head != NULL) {
            ListNode* tmp = head;
            head = reverseK(pretail, head, k);
            pretail = tmp;
        }
        return dummy->next;
    }
    ListNode* reverseK(ListNode* pretail, ListNode* cur, int k) {
        ListNode* pre = NULL, *next = cur->next;
        for(int i = 1; i <= k; i++) {
            cur->next = pre;
            if(i == k) break;
            if(next == NULL) return reverseK(pretail, cur, i);
            pre =  cur;
            cur = next;
            next = next->next;
        }
        pretail->next = cur;
        return next;
    }
};
// @lc code=end

