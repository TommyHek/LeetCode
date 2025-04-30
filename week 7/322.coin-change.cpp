/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        //if amount is 0, return 0
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0; 

        //interate through each amount from 1 to amount
        for (int i = 1; i <= amount; ++i) {
            // iterate through each coin
            for (int coin : coins) {
                if (i >= coin) {
                    //try to use less coins to make up the amount
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }

        // if dp[amount] is greater than amount, it means we can't make up the amount
        return (dp[amount] > amount) ? -1 : dp[amount];
    }
};
// @lc code=end

