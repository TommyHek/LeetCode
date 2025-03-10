/*
 * @lc app=leetcode id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 */

// @lc code=start
#include <vector>
#include <deque>
using namespace std;

class Solution {
private:

public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        deque<int> dq;
        //if k is 1, return the array
        if(k==1)
            return nums;
        //k != 1
        for(int i = 0; i < nums.size(); i++){//iterate through the array
            //if the front of the deque is out of the window, pop it
            if(!dq.empty() && dq.front() < i - k + 1)
                dq.pop_front();
            //if the back of the deque is smaller than the current element, pop it
            while(!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();

            //push the current element
            dq.push_back(i);
            
            //if the window is full, push the front of the deque to the result
            if(i >= k - 1)
                result.push_back(nums[dq.front()]);
        }
        return result;
    }
};
// @lc code=end

