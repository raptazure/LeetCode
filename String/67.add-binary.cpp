/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 */

// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        vector<int> A, B;
        for(int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');
        for(int i = b.size() - 1; i >= 0; i--) B.push_back(b[i] - '0');
        vector<int> res;
        int t = 0;
        for(int i = 0; i < A.size() || i < B.size(); i++) {
            if(i < A.size()) t += A[i];
            if(i < B.size()) t += B[i];
            res.push_back(t % 2);
            t /= 2;
        }
        if(t) res.push_back(1);
        reverse(res.begin(), res.end());
        for(int& i:res) ans.push_back(i + '0');
        return ans;
    }
};
// @lc code=end

