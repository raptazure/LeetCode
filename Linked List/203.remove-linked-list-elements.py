#
# @lc app=leetcode id=203 lang=python3
#
# [203] Remove Linked List Elements
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeElements(self, head: ListNode, val: int) -> ListNode:
        dummy = ListNode(val + 1)
        dummy.next = head
        cur, pre = head, dummy
        while cur:
            if cur.val != val:
                cur = cur.next
                pre = pre.next
            else:
                next = cur.next
                pre.next = cur.next
                cur = next
        return dummy.next

# @lc code=end

