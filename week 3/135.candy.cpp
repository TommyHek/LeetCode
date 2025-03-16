/*
 * @lc app=leetcode id=135 lang=cpp
 *
 * [135] Candy
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n, 1);

        // left to right
        for(int i = 1; i < n; i++){
            if(ratings[i] > ratings[i-1]){
                candies[i] = candies[i-1] + 1;
            }
        }

        // right to left
        for(int i = n-2; i >= 0; i--){
            if(ratings[i] > ratings[i+1]){
                candies[i] = max(candies[i], candies[i+1] + 1);
            }
        }

        //  sum up
        int ans = 0;
        for(int c : candies){
            ans += c;
        }
        return ans;
    }
};
// @lc code=end

