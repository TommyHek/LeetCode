/*
 * @lc app=leetcode id=2366 lang=cpp
 *
 * [2366] Minimum Replacements to Sort the Array
 */

// @lc code=start
#include <vector>
#include <cmath>
using namespace std;
class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long steps = 0;
        int limit = nums.back();  // the maximum number in the array (from right to left)

        // from right to left
        for(int i = nums.size() - 2; i >= 0; i--) {
            // if nums[i] <= limit, no need to replace
            if(nums[i] <= limit) {
                limit = nums[i];
            } else {
                // how many times we need to replace
                long long p = ((long long)nums[i] + (long long)limit - 1) / (long long)limit; // get the ceil of nums[i] / limit
                steps += (p - 1);  // need to replace p - 1 times
                // update the limit
                limit = nums[i] / p;
            }
        }
        return steps;
    }
};
// @lc code=end

