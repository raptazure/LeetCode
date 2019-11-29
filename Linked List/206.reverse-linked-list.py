#
# @lc app=leetcode id=206 lang=python3
#
# [206] Reverse Linked List
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:   # Iterative
        pre, cur = None, head
        while cur:
            next = cur.next
            cur.next = pre
            pre = cur
            cur = next
        return pre
    def reverseList_1(self, head):   # Recursive
        if not head or not head.next:
            return head
        tail = self.reverseList_1(head.next)
        head.next.next = head
        head.next = None
        return tail
# @lc code=end

