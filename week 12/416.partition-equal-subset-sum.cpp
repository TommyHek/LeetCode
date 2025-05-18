/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 */

// @lc code=start
#include <vector>
#include <numeric>   
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // Check if the total sum is odd
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if (totalSum % 2 != 0) return false;          

        // Initialize a DP array to track reachable sums
        int halfSum = totalSum / 2;                   
        vector<bool> canReach(halfSum + 1, false); // Initialize all sums as unreachable   
        canReach[0] = true;                           

        // Iterate through each number in the array
        for (int num : nums) {                        
            for (int s = halfSum; s >= num; --s) { 
                // Update the DP array for the current number   
                canReach[s] = canReach[s] || canReach[s - num]; 
            }
        }
        // The target is to check if we can reach half of the total sum
        return canReach[halfSum];
    }
};

// @lc code=end

