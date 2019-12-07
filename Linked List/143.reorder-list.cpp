/*
 * @lc app=leetcode id=143 lang=cpp
 *
 * [143] Reorder List
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
    ListNode* reorderList(ListNode* head) {
       if (!head) return NULL;
       ListNode* mid = findMiddle(head);
       ListNode* l2 = mid->next;
       auto l1 = head;
       mid->next = NULL;
       l2 = reverse(l2);
       while(l1 && l2)
       {
           auto next = l1->next;
            l1->next = l2;
            l2 = l2->next;
            l1->next->next = next;
            l1 = next;
       }
       return head;
    }
    ListNode* findMiddle(ListNode* head){
        auto fast = head;
        auto slow = head;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* reverse(ListNode* head)
    {
        ListNode* prev = nullptr;
        auto cur = head;
        while(cur)
        {
            auto next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
};
// @lc code=end

