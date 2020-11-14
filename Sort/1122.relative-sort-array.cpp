/*
 * @lc app=leetcode.cn id=1122 lang=cpp
 *
 * [1122] 数组的相对排序
 */

// @lc code=start
class Solution
{
public:
    vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
    {
        unordered_map<int, int> rank;
        for (int i = 0; i < arr2.size(); ++i)
        {
            rank[arr2[i]] = i;
        }
        auto mycmp = [&](int x) -> pair<int, int> {
            return rank.count(x) ? pair{0, rank[x]} : pair{1, x};
        };
        sort(arr1.begin(), arr1.end(), [&](int x, int y) {
            return mycmp(x) < mycmp(y);
        });
        return arr1;
    }
};
// @lc code=end
