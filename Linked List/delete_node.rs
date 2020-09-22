// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
//
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }
impl Solution {
    pub fn delete_node(head: Option<Box<ListNode>>, val: i32) -> Option<Box<ListNode>> {
        let mut head = Some(Box::new(ListNode { 
            next: head,
            val: 0
        }));
        let mut p = &mut head;

        while p.as_ref().unwrap().next != None {
            if p.as_ref().unwrap().next.as_ref().unwrap().val == val {
                p.as_mut().unwrap().next = p.as_mut().unwrap().next.take().unwrap().next;
                break;
            }
            p = &mut p.as_mut().unwrap().next;
        }
        head.unwrap().next
    }
}