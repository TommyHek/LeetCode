/*
 * @lc app=leetcode id=2742 lang=cpp
 *
 * [2742] Painting the Walls
 */

// @lc code=start
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        const int INF = INT_MAX / 2;  // Use a large value to avoid overflow   
        vector<int> minCost(n + 1, INF); // Initialize minCost with INF      
        minCost[0] = 0;                       

        for (int i = 0; i < n; ++i) {
            int cover = time[i] + 1;        
            int fee   = cost[i];
            // Iterate backwards to avoid overwriting values in the same iteration
            for (int k = n; k >= 0; --k) {
                if (minCost[k] == INF) continue;               
                int newK = min(n, k + cover); // Calculate the new index after painting  
                // Update the minimum cost for the new index           
                minCost[newK] = min(minCost[newK], minCost[k] + fee);
            }
        }
        return minCost[n]; 
    }
};

// @lc code=end

