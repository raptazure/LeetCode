/*
 * @lc app=leetcode id=148 lang=cpp
 *
 * [148] Sort List
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
    ListNode* sortList(ListNode* head) {
        // space O(1)
        if(!head || !head->next) return head;
        
        int len = 1;
        auto cur = head;
        while(cur = cur->next) len++;
        
        ListNode dummy(0);
        dummy.next = head;
        ListNode* l;
        ListNode* r;
        ListNode* tail;
        for(int n = 1; n < len; n *= 2) 
        {
            cur = dummy.next;
            tail = &dummy;
            while(cur)
            {
                l = cur;
                r = split(l, n);
                cur = split(r, n);
                auto merged = merge(l, r);
                tail->next = merged.first;
                tail = merged.second;
            }
        }
        return dummy.next;
    }
    ListNode* split(ListNode* head, int n)
    {
        while(--n && head) head = head->next;
        ListNode* rest = head ? head->next : nullptr;
        if(head) head->next = nullptr;
        return rest; 
    }
    pair<ListNode*, ListNode*> merge(ListNode* l1, ListNode* l2)
    {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        while(l1 && l2){
            if(l1->val > l2->val) swap(l1, l2);
            tail->next = l1;
            l1 = l1->next;
            tail = tail->next;
        }
        tail->next = l1 ? l1 : l2;
        while(tail->next) tail = tail->next;
        return {dummy.next, tail};
    }
};
// @lc code=end

