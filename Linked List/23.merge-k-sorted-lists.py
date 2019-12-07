#
# @lc app=leetcode id=23 lang=python3
#
# [23] Merge k Sorted Lists
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        return self.merge(lists, 0, len(lists) - 1)
    def merge(self, lists, l, r):
        if l > r:
            return None
        if l == r:
            return lists[l]
        if l + 1 == r:
            return self.mergeTwoLists(lists[l], lists[r])
        m = l + (r - l) // 2
        l1 = self.merge(lists, l, m)
        l2 = self.merge(lists, m + 1, r)
        return self.mergeTwoLists(l1, l2)
    def mergeTwoLists(self, l1, l2):
        dummy = ListNode(-1)
        cur = dummy
        while l1 and l2:
            if l1.val < l2.val:
                cur.next = l1
                cur = l1
                l1 = l1.next
            else:
                cur.next = l2
                cur = l2
                l2 = l2.next
        if l1:
            cur.next = l1
        else:
            cur.next = l2
        return dummy.next
# @lc code=end

