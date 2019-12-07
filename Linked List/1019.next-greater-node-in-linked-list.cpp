/*
 * @lc app=leetcode id=1019 lang=cpp
 *
 * [1019] Next Greater Node In Linked List
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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> nums;
        while(head) {
            nums.push_back(head->val);
            head = head->next;
        }
        stack<int> s;
        vector<int> ans(nums.size());
        for(int i = nums.size() - 1; i >= 0; --i) {
            while(!s.empty() && s.top() <= nums[i]) s.pop();
            ans[i] = s.empty() ? 0 : s.top();
            s.push(nums[i]);
        }
        return ans;
    }
};
// @lc code=end

