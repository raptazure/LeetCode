#
# @lc app=leetcode id=24 lang=python3
#
# [24] Swap Nodes in Pairs
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        dummy = ListNode(-1)
        dummy.next = head
        p = dummy
        while p.next and p.next.next:
            first = p.next
            second = p.next.next
            p.next = second
            first.next = second.next
            second.next = first
            p = first
        return dummy.next
# @lc code=end

