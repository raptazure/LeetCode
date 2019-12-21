/*
 * @lc app=leetcode.cn id=690 lang=cpp
 *
 * [690] 员工的重要性
 */

// @lc code=start
/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        for(auto e : employees) {
            if(e->id == id) {
                if(e->subordinates.size() == 0) {
                    return e->importance;
                }
                for(auto subID : e->subordinates) {
                    e->importance += getImportance(employees, subID);
                }
                return e->importance;
            }
        }
        return 0;
    }
};
// @lc code=end

