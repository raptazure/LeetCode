#
# @lc app=leetcode id=61 lang=python3
#
# [61] Rotate List
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def rotateRight(self, head: ListNode, k: int) -> ListNode:
        cur, first, second = head, head, head
        n = 1
        if not head:
            return head
        while cur.next:
            n += 1
            cur = cur.next
        k %= n
        while k:
            first = first.next
            k -= 1
        while first.next:
            first = first.next
            second = second.next
        first.next = head
        head = second.next
        second.next = None
        return head
# @lc code=end

