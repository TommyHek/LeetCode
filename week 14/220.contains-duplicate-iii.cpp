/*
 * @lc app=leetcode id=220 lang=cpp
 *
 * [220] Contains Duplicate III
 */

// @lc code=start
#include <vector>
#include <set>
#include <cmath>
using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums,
                                       int indexDiff,
                                       int valueDiff)
    {
        if (indexDiff <= 0 || valueDiff < 0) return false;

        // Balanced-BST that stores the last `indexDiff` elements (as long long to avoid overflow)
        multiset<long long> window;

        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            long long cur = nums[i];

            // Find the first element ≥ (cur - valueDiff)
            auto it = window.lower_bound(cur - valueDiff);

            // If such element exists and |cur - *it| ≤ valueDiff, we found a valid pair
            if (it != window.end() && llabs(*it - cur) <= valueDiff)
                return true;

            // Put current number into the sliding window
            window.insert(cur);

            // Keep at most `indexDiff` elements in the window
            if (static_cast<int>(window.size()) > indexDiff)
                window.erase(window.find(nums[i - indexDiff]));
        }
        return false; // No pair satisfies both conditions
    }
};


// @lc code=end

