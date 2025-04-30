/*
 * @lc app=leetcode id=752 lang=cpp
 *
 * [752] Open the Lock
 */

// @lc code=start
#include <iostream>
#include <string>
#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(), deadends.end());
        unordered_set<string> visited;
        queue<string> q;
        
        string start = "0000";
        if (dead.count(start)) return -1;

        q.push(start);
        visited.insert(start);
        int steps = 0;
        // BFS to find the shortest path to the target
        while (!q.empty()) {
            int levelSize = q.size();
            // Check if we have reached the target at this level
            for (int i = 0; i < levelSize; ++i) {
                string curr = q.front(); q.pop();

                if (curr == target) return steps;

                // Try all possible next states by turning each wheel
                for (int pos = 0; pos < 4; ++pos) {
                    for (int dir = -1; dir <= 1; dir += 2) {
                        string next = curr;
                        next[pos] = (curr[pos] - '0' + dir + 10) % 10 + '0';
                        //if the next state is not visited and not in deadends, add it to the queue
                        if (!visited.count(next) && !dead.count(next)) { 
                            q.push(next); 
                            visited.insert(next);
                        }
                    }
                }
            }
            steps++;
    }

    return -1; // If we exhaust the queue without finding the target, return -1.
    }
};

// @lc code=end

