/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return head;
        auto ptr = head;
        while(ptr)
        {
            auto new_node = new Node(ptr->val, nullptr, nullptr);
            new_node->next = ptr->next;
            ptr->next = new_node;
            ptr = new_node->next;
        }
        ptr = head;
        while(ptr)
        {
            if(ptr->random) ptr->next->random = ptr->random->next;
            ptr = ptr->next->next;
        }
        auto ptr_old_list = head;
        auto ptr_new_list = head->next;
        auto head_new = head->next;
        while(ptr_old_list)
        {
            ptr_old_list->next = ptr_old_list->next->next;
            if(ptr_new_list->next)
                ptr_new_list->next = ptr_new_list->next->next;
            else ptr_new_list->next = NULL;
            ptr_old_list = ptr_old_list->next;
            ptr_new_list = ptr_new_list->next;
        }
        return head_new;
    }
};
// @lc code=end

