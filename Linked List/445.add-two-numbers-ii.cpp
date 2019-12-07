/*
 * @lc app=leetcode id=445 lang=cpp
 *
 * [445] Add Two Numbers II
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
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1 && !l2) return l1 == NULL ? l2 : l1;
        stack<int> s1, s2;
        while(l1)
        {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while(l2)
        {
            s2.push(l2->val);
            l2 = l2->next;
        }
        int carry = 0;
        auto dummy = new ListNode(-1);
        while(!s1.empty() || !s2.empty() || carry)
        {
            if(!s1.empty()) 
            {
                carry += s1.top();
                s1.pop();
            }
            if(!s2.empty()) 
            {
                carry += s2.top();
                s2.pop();
            }
            // 需要头插，否则还要翻转链表
            auto node = new ListNode(carry % 10);
            node->next = dummy->next;
            dummy->next = node;
            carry /= 10;
        }
        return dummy->next;
    }
};
// @lc code=end

