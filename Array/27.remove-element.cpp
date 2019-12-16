/*
 * @lc app=leetcode id=27 lang=cpp
 *
 * [27] Remove Element
 */

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != val) len++;
        }
        int l2 = len;
        for(int l1 = 0; l1 < len; l1++) {
            while(nums[l1] == val && l2 < nums.size()) {
                if(nums[l2] != val) swap(nums[l1], nums[l2]);
                else l2++;
            }
        }
        return len;
    }
};

// class Solution {
// public:
//     int removeElement(vector<int>& nums, int val) {
//         int k = 0;
//         for(auto i : nums) {
//             if(i != val) nums[k++] = i;
//         }
//         return k;
//     }
// };

// @lc code=end

