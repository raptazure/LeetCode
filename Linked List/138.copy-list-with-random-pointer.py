#
# @lc app=leetcode id=138 lang=python3
#
# [138] Copy List with Random Pointer
#

# @lc code=start
"""
# Definition for a Node.
class Node:
    def __init__(self, val, next, random):
        self.val = val
        self.next = next
        self.random = random
"""
"""
# Definition for a Node.
class Node:
    def __init__(self, val, next, random):
        self.val = val
        self.next = next
        self.random = random
"""
class Solution:
    def copyRandomList(self, head: 'Node') -> 'Node':
        dummy = Node(0, None, None)
        mapO2N = {}
        i = head
        j = dummy
        while i:
            # parallel
            j.next = Node(i.val, None, None)
            j = j.next
            # update map
            mapO2N[i] = j
            i = i.next
        i, j = head, dummy.next
        while i:
            if i.random:
                j.random = mapO2N[i.random]
            i, j = i.next, j.next
        return dummy.next

# @lc code=end

