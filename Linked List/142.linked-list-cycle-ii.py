#
# @lc app=leetcode id=142 lang=python3
#
# [142] Linked List Cycle II
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def detectCycle(self, head: ListNode) -> ListNode:
        if not head or not head.next:
            return None
        first, second = head, head
        while second:
            first = first.next
            second = second.next
            if second:
                second = second.next
            else:
                return None
            if second == first:
                first = head
                while first != second:
                    first = first.next
                    second = second.next
                return first
        return None    
# @lc code=end

