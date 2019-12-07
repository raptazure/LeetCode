/*
 * @lc app=leetcode id=430 lang=cpp
 *
 * [430] Flatten a Multilevel Doubly Linked List
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
public:
    Node* flatten(Node* head) {
        if(!head) return nullptr;
        Node *cur;
        stack<Node*> stk;
        stk.push(head);
        Node *pre = nullptr;
        while(!stk.empty()) 
        {
            cur = stk.top();
            stk.pop();
            if(cur->next){
                stk.push(cur->next);
            }
            if(cur->child){
                stk.push(cur->child);
                cur->child = nullptr;
            }
            if(pre){
                pre->next = cur;
                cur->prev = pre;
            }
            pre = cur;
        }
        return head;
    }
};
// @lc code=end

