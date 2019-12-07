#
# @lc app=leetcode id=234 lang=python3
#
# [234] Palindrome Linked List
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        if not head or not head.next:
            return True
        slow, fast, pre, prepre = head, head, head, None
        while fast and fast.next:
            pre = slow
            slow = slow.next
            fast = fast.next.next
            pre.next = prepre
            prepre = pre
        if fast:
            slow = slow.next
        while pre and slow:
            if pre.val != slow.val:
                return False
            pre = pre.next
            slow = slow.next
        return True
# @lc code=end

