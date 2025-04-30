/*
 * @lc app=leetcode id=435 lang=cpp
 *
 * [435] Non-overlapping Intervals
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Main function to compute minimum number of intervals to remove
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;

        // Step 1: Sort intervals by end time (ascending)
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int removeCount = 0; // Number of intervals to remove
        int prevEndTime = intervals[0][1]; // End time of the last selected interval

        // Step 2: Iterate from second interval to check for overlaps
        for (int i = 1; i < intervals.size(); ++i) {
            int currStart = intervals[i][0];
            int currEnd = intervals[i][1];

            // If current start is before previous end, we have an overlap
            if (currStart < prevEndTime) {
                removeCount++; // Need to remove this interval
            } else {
                prevEndTime = currEnd; // Update the end time
            }
        }

        return removeCount;
    }
};

// @lc code=end

