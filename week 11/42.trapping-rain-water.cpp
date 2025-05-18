/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();  // Get the size of the height vector
        if (n < 3) return 0;          

        int left  = 0;     // Initialize left pointer           
        int right = n - 1; // Initialize right pointer           
        int leftMax  = 0;  // Maximum height to the left of the left pointer           
        int rightMax = 0;  // Maximum height to the right of the right pointer           
        int water = 0;     // Initialize water trapped to 0           

        // Use two pointers to traverse the height array from both ends
        while (left < right) {
            if (height[left] < height[right]) {
                // If the left height is less than the right height
                leftMax = max(leftMax, height[left]); 
                water  += leftMax - height[left]; // Add water trapped at the left pointer
                ++left; // Move the left pointer right
            } else {
                // If the right height is less than or equal to the left height
                rightMax = max(rightMax, height[right]); 
                water   += rightMax - height[right]; // Add water trapped at the right pointer
                --right; // Move the right pointer left
            }
        }
        // Return the total water trapped
        return water;
    }
};
// @lc code=end

