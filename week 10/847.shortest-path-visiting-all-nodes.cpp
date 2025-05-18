/*
 * @lc app=leetcode id=847 lang=cpp
 *
 * [847] Shortest Path Visiting All Nodes
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        const int n = graph.size();// get the number of nodes
        if (n == 1) return 0;   // if only one node, return 0          

        const int FULL = (1 << n) - 1; // all nodes visited
                
        queue<pair<int,int>> q; // queue to store (node, visitedMask) 
        // dist[node][mask] = steps to reach (node, mask)
        vector<vector<int>> dist(n, vector<int>(1 << n, -1)); 

        // Initialize the queue with all nodes and their respective masks
        for (int node = 0; node < n; ++node) {
            int mask = 1 << node; 
            dist[node][mask] = 0;
            q.emplace(node, mask); 
        }

        // BFS to find the shortest path
        while (!q.empty()) {
            auto [cur, mask] = q.front(); q.pop();
            int curSteps = dist[cur][mask]; 
            // Iterate through all neighbors of the current node
            for (int nxt : graph[cur]) {          
                int nxtMask = mask | (1 << nxt);  // update the mask to include the next node
                if (dist[nxt][nxtMask] != -1) continue;   

                dist[nxt][nxtMask] = curSteps + 1; // update the distance for the next node and mask
                if (nxtMask == FULL)  // if all nodes are visited            
                    return dist[nxt][nxtMask]; 
                q.emplace(nxt, nxtMask); // add the next node and mask to the queue
            }
        }
        // If we reach here, it means we couldn't visit all nodes
        return -1;   
    }
};
// @lc code=end

