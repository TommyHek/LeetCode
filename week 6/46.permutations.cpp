/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
private:
    void backtrack(const vector<int>& nums,
                vector<bool>& used,
                vector<int>& path,
                vector<vector<int>>& result)
    {
        if (path.size() == nums.size()) {
            result.push_back(path); 
            return;
        }

        for (int i = 0; i < (int)nums.size(); i++) {
            if (used[i]) {
                continue;
            }

            path.push_back(nums[i]);
            used[i] = true;

            backtrack(nums, used, path, result);
            path.pop_back();
            used[i] = false;
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;

        vector<bool> used(nums.size(), false);

        vector<int> path;

        backtrack(nums, used, path, result);

        return result;
    }
};
// @lc code=end

