/*
 * @lc app=leetcode id=725 lang=cpp
 *
 * [725] Split Linked List in Parts
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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        int len = 0;
        for(ListNode* head = root; head; head = head->next) len++;
        vector<ListNode*> ans(k, nullptr);
        int l = len / k;
        int r = len % k;
        ListNode* head = root;
        ListNode* prev = nullptr;
        for(int i = 0; i < k; i++, --r)
        {
            ans[i] = head;
            for(int j = 0; j < l + (r > 0); ++j)
            {
                prev = head;
                head = head->next;
            }
            if(prev) prev->next = nullptr;
        }
        return ans;
    }
};
// @lc code=end

