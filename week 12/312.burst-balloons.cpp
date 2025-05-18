/*
 * @lc app=leetcode id=312 lang=cpp
 *
 * [312] Burst Balloons
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1); // Add 1 at the beginning
        nums.push_back(1); // Add 1 at the end
        int n = nums.size();
        // dp[i][j] represents the maximum coins we can get from bursting balloons between i and j
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Iterate over the length of the subarray
        for (int len = 3; len <= n; ++len) {
            // Iterate over the starting index of the subarray
            for (int left = 0; left + len - 1 < n; ++left) {
                int right = left + len - 1; 
                // Iterate over the last balloon to burst in the subarray
                for (int mid = left + 1; mid < right; ++mid) {
                    // Calculate the coins obtained by bursting the mid balloon last
                    int coins = nums[left] * nums[mid] * nums[right]; 
                    // Add the coins obtained from bursting the left and right subarrays
                    coins += dp[left][mid] + dp[mid][right];   
                    // Update the maximum coins for the current subarray       
                    dp[left][right] = max(dp[left][right], coins);
                }
            }
        }
        // The answer is stored in dp[0][n - 1], which represents the maximum coins we can get from bursting all balloons
        return dp[0][n - 1];
    }
};
// @lc code=end

