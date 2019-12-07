/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
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
    bool isPalindrome(ListNode* head) {
        if(!head) return true;
        auto p = head;
        int size = 1;
        while(p->next) {
            p = p->next;
            size++;
        }
        auto fast = head->next;
        auto slow = head;
        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        slow = slow->next;
        auto cur = head;
        ListNode* prev = nullptr;
        while(cur != slow) {
            auto next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        if(size % 2 != 0) prev = prev->next;
        while(prev && slow) {
            if(slow->val != prev->val) return false;
            prev = prev->next;
            slow = slow->next;
        }
        return true;
    }
};
// @lc code=end

