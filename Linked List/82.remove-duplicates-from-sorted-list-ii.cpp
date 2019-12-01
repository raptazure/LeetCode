/*
 * @lc app=leetcode id=82 lang=cpp
 *
 * [82] Remove Duplicates from Sorted List II
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
    ListNode* deleteDuplicates(ListNode* head) {
        auto dummy = new ListNode(-100);
        dummy->next = head;
        auto fast = dummy, slow = dummy;
        while(fast && fast->next)
        {
            if(fast->val != fast->next->val){
                fast = fast->next;
                if(fast && fast->next && fast->val != fast->next->val)
                    slow = fast;
            }
            else{
                while(fast && fast->next && fast->val == fast->next->val)
                    fast = fast->next;
                fast = fast->next;
                slow->next = fast;
                if(fast && fast->next && fast->next->val != fast->val) slow = fast;
            }
            
        }   
        return dummy->next;
    }
};
// @lc code=end

