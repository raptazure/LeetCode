/*
 * @lc app=leetcode id=147 lang=java
 *
 * [147] Insertion Sort List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode insertionSortList(ListNode head) {
        ListNode dummy = new ListNode(0);
        ListNode pre;
        dummy.next = head;
        while(head != null && head.next != null)
        {
            if(head.val <= head.next.val){
                head = head.next;
                continue;
            }
            pre = dummy;
            while(pre.next.val < head.next.val) pre = pre.next;
            ListNode cur = head.next;
            head.next = cur.next;
            cur.next = pre.next;
            pre.next = cur;
        }
        return dummy.next;
    }
}
// @lc code=end

