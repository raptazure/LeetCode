#
# @lc app=leetcode id=86 lang=python3
#
# [86] Partition List
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def partition(self, head: ListNode, x: int) -> ListNode:
        dummy1 = ListNode(-1)
        dummy2 = ListNode(-2)
        p, cur1, cur2 = head, dummy1, dummy2
        while p:
            if p.val < x:
                cur1.next = p
                cur1 = cur1.next
            else:
                cur2.next = p
                cur2 = cur2.next
            p = p.next
        cur1.next = dummy2.next
        cur2.next = None
        return dummy1.next
# @lc code=end

