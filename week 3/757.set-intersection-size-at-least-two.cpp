/*
 * @lc app=leetcode id=757 lang=cpp
 *
 * [757] Set Intersection Size At Least Two
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        // if the intervals is empty, return 0
        sort(intervals.begin(), intervals.end(), 
             [](const vector<int> &a, const vector<int> &b){
                 if(a[1] == b[1]) return a[0] > b[0];
                 return a[1] < b[1];
             });

        
        
        int lastOne = -1, lastTwo = -1; // to store the last two points 
        int result = 0; // to store the result

        // iterate through the intervals
        for(const auto &interval : intervals){
            int start = interval[0];
            int end   = interval[1];

            // count how many points are in the interval
            int countIn = 0;
            if(lastTwo >= start && lastTwo <= end) countIn++;
            if(lastOne >= start && lastOne <= end) countIn++;

            // if countIn == 0, we need to add 2 points
            if(countIn == 0) {
                result += 2;
                lastOne = end - 1;
                lastTwo = end;
            } 
            else if(countIn == 1) {
                // if countIn == 1, we need to add 1 point
                result += 1;
                
                
                if(lastTwo < start || lastTwo > end) {
                    // if lastTwo is not in the interval, we need to update lastOne and lastTwo
                    lastTwo = end;
                } else {
                    // if lastTwo is in the interval, we need to update lastOne and lastTwo
                    lastOne = lastTwo;
                    lastTwo = end;
                }
            }
            // if countIn == 2, we don't need to add any points
        }

        return result;
    }
};
// @lc code=end

