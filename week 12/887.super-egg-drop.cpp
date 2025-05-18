/*
 * @lc app=leetcode id=887 lang=cpp
 *
 * [887] Super Egg Drop
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int superEggDrop(int eggs, int floors) {
        // Base cases
        // If there are no floors, we need 0 moves.
        if (floors <= 1 || eggs == 1) return floors;   

        vector<long long> dp(eggs + 1, 0); // dp[i] = number of moves with i eggs

        int moves = 0;
        // We need to find the minimum number of moves such that we can check all floors
        while (dp[eggs] < floors) {
            ++moves;                       
            // For each egg, we can drop it from the current floor
            for (int e = eggs; e >= 1; --e)
            // we can use the result of the previous egg
                dp[e] = dp[e] + dp[e - 1] + 1;
        }
        // The number of moves needed to find the critical floor
        return moves;
    }
};

// @lc code=end

