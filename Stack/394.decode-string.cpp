/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码
 */

// @lc code=start
class Solution
{
public:
    string decodeString(string s)
    {
        int len = s.size();
        int num = 0;
        stack<int> numstack;
        stack<string> strstack;
        string cur = "";
        string result = "";
        for (int i = 0; i < len; ++i)
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                num = 10 * num + s[i] - '0';
            }
            else if (s[i] == '[')
            {
                numstack.push(num);
                strstack.push(cur);
                num = 0;
                cur.clear();
            }
            else if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
                cur += s[i];
            else if (s[i] == ']')
            {
                int k = numstack.top();
                numstack.pop();
                for (int j = 0; j < k; ++j)
                    strstack.top() += cur;
                cur = strstack.top();
                strstack.pop();
            }
        }
        result = result + cur;
        return result;
    }
};
// @lc code=end