/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        auto cmp = [](ListNode* a, ListNode* b) { return a->val > b->val; };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> q(cmp);
        
        for(ListNode* list : lists)
            if(list) q.push(list);
        while(!q.empty()) {
            tail->next = q.top(); q.pop();
            tail = tail->next;
            if(tail->next) q.push(tail->next);
        }
        return dummy.next;
    }
};
// @lc code=end

