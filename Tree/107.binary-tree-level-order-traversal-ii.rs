/*
 * @lc app=leetcode.cn id=107 lang=rust
 *
 * [107] 二叉树的层次遍历 II
 */

// @lc code=start
// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
// 
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use std::rc::Rc;
use std::cell::RefCell;
impl Solution {
    pub fn level_order_bottom(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<Vec<i32>> {
        let (mut root, mut arr, mut res) = (root, Vec::new(), Vec::new());
        if root.is_some() { arr.push(root); }
        while !arr.is_empty() {
            let (mut children, mut values) = (Vec::new(), Vec::new());
            for mut node in arr {
                let mut node = node.as_mut().unwrap().borrow_mut();
                values.push(node.val);
                if node.left.is_some() { children.push(node.left.take()); }
                if node.right.is_some() { children.push(node.right.take()); }
            }
            arr = children;
            res.push(values);
        }
        res.into_iter().rev().collect()
    }
}
// @lc code=end

