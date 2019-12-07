#
# @lc app=leetcode id=817 lang=python3
#
# [817] Linked List Components
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def numComponents(self, head: ListNode, G: List[int]) -> int:
        Gset = set(G)
        cur, ans = head, 0
        while cur:
            if (cur.val in Gset and getattr(cur.next, 'val', None) not in Gset):
                ans += 1
            cur = cur.next
        return ans
# @lc code=end

