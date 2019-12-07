/*
 * @lc app=leetcode id=430 lang=java
 *
 * [430] Flatten a Multilevel Doubly Linked List
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
    public int val;
    public Node prev;
    public Node next;
    public Node child;

    public Node() {}

    public Node(int _val,Node _prev,Node _next,Node _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
    private Node prev = null;
    public Node flatten(Node head) {
        dfs(head);
        return head;
    }

    private void dfs(Node head) {
        if(head == null) return;
        Node next = head.next;
        if(prev != null) {
            prev.next = head;
            head.prev = prev;
        }
        prev = head;
        dfs(head.child);
        head.child = null;
        dfs(next);
    }
}
// @lc code=end

