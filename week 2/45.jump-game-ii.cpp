/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
int jump(vector<int>& nums) {
    if(nums.size() == 1) return 0;
    
    int jumps = 0;
    int currentFar = 0;
    int nextFar = 0;

    for(int i = 0; i < nums.size()-1; i++){
        nextFar = max(nextFar, i + nums[i]); //find the farthest point we can reach
        if(i == currentFar){
            jumps++;
            currentFar = nextFar;
        }
    }
    return jumps;
}
};
// @lc code=end

