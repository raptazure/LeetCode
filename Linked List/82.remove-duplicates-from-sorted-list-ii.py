#
# @lc app=leetcode id=82 lang=python3
#
# [82] Remove Duplicates from Sorted List II
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        p = ListNode(0)
        p.next, head = head, p
        while p.next:
            left = p.next
            right = left
            while right.next and right.next.val == left.val:
                right = right.next
            if left == right:
                p = p.next
            else:
                p.next = right.next
        return head.next
# @lc code=end

