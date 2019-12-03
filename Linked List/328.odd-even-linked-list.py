#
# @lc app=leetcode id=328 lang=python3
#
# [328] Odd Even Linked List
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def oddEvenList(self, head: ListNode) -> ListNode:
        dummy1 = ListNode(-1)
        dummy2 = ListNode(-1)
        p, cur1, cur2 = head, dummy1, dummy2
        cnt = 1
        while p:
            if cnt % 2 != 0:
                cur1.next = p
                cur1 = cur1.next
            else:
                cur2.next = p
                cur2 = cur2.next
            p = p.next
            cnt += 1
        cur1.next = dummy2.next
        cur2.next = None
        return dummy1.next
# @lc code=end

