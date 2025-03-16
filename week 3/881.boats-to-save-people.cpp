/*
 * @lc app=leetcode id=881 lang=cpp
 *
 * [881] Boats to Save People
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int left = 0, right = (int)people.size() - 1;
        int boats = 0;

        while(left <= right) {
            // if the lightest person can pair with the heaviest person
            if(people[left] + people[right] <= limit) {
                left++;
            }
            // heaviest person can't pair with anyone, so he has to go alone
            right--;
            boats++;
        }
        return boats; 
    }
};
// @lc code=end

