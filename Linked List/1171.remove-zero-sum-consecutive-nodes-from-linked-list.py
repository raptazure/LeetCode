#
# @lc app=leetcode id=1171 lang=python3
#
# [1171] Remove Zero Sum Consecutive Nodes from Linked List
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeZeroSumSublists(self, head: ListNode) -> ListNode:
        dummy = ListNode(0)
        dummy.sum = 0
        dummy.next = head
        cur_sum = 0
        p = head
        while p:
            cur_sum += p.val
            p.sum = cur_sum
            p = p.next
        start = dummy
        while start:
            cur = start.next
            while cur:
                range_sum = cur.sum - start.sum
                if range_sum == 0:
                    start.next = cur.next
                cur = cur.next
            start = start.next
        return dummy.next
# @lc code=end

