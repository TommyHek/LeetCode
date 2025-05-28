/*
 * @lc app=leetcode id=875 lang=cpp
 *
 * [875] Koko Eating Bananas
 */

// @lc code=start
#include <vector>
#include <algorithm>    
#include <cmath>        
using namespace std;
class Solution {
private:
    // to check if Koko can finish eating all bananas in h hours at a given speed
    bool canFinish(const vector<int>& piles, int h, int speed) {
        long long hoursNeeded = 0; // total hours needed (to avoid overflow)     
        // iterate through each pile and calculate the hours needed                
        for (int pile : piles) {
            hoursNeeded += (pile + speed - 1) / speed; // this is equivalent to ceil(pile / speed)  
            // this is equivalent to ceil(pile / speed)
            if (hoursNeeded > h) return false;          
        }
        // if total hours needed is less than or equal to h, return true
        return hoursNeeded <= h; 
    }

public:
    // main function to find the minimum eating speed
    int minEatingSpeed(vector<int>& piles, int h) {
        // binary search for the minimum speed
        
        int left  = 1;   // left is the minimum speed (1 banana per hour)   
        // right is the maximum speed (max pile size)                        
        int right = *max_element(piles.begin(), piles.end()); 

        // binary search to find the minimum speed
        while (left < right) {
            // calculate the mid speed
            int midSpeed = left + (right - left) / 2; 
            // check if Koko can finish eating all bananas in h hours at mid speed  
            if (canFinish(piles, h, midSpeed)) {
                right = midSpeed;                       
            } else { // if Koko cannot finish, increase the speed
                left = midSpeed + 1;                   
            }
        }
        // return the minimum speed
        return left;    
    }
};

// @lc code=end

