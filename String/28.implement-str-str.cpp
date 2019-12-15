/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Implement strStr()
 */

// @lc code=start
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.length() < needle.length()) return -1;
        if(!needle.length()) return 0;
        int i = 0, j = 0;
        while(i < haystack.length()) {
            if(haystack[i] == needle[j]) {
                i++; j++;
                if(j >= needle.length()) return i - j;
            }
            else {
                if(j < needle.length()) {
                    i = i - j + 1; j = 0;
                }
                else i++;
            }
        }
        return -1;
    }
};
// @lc code=end

