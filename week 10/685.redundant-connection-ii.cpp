/*
 * @lc app=leetcode id=685 lang=cpp
 *
 * [685] Redundant Connection II
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();      // number of nodes          
        vector<int> dad(n + 1, 0);  // parent of each node          
        vector<int> bad1, bad2;     // first and second bad edges          
        
        // First pass: find the first bad edge
        for (auto& e : edges) {
            int from = e[0], to = e[1];
            // if the node already has a parent
            if (dad[to] == 0) {               
                dad[to] = from;
            } else { // if the node has two parents                         
                bad1 = {dad[to], to};         
                bad2 = e;                     
                e[1] = 0;                     
            }
        }
        // Second pass: find the second bad edge
        vector<int> root(n + 1); // root[i] = i
        for (int i = 0; i <= n; ++i) root[i] = i;
        auto findRoot = [&](auto self, int x) -> int {
            // path compression
            return root[x] == x ? x : root[x] = self(self, root[x]); 
        };
        // union-find
        auto unite = [&](int a, int b) -> bool {  
            int ra = findRoot(findRoot, a);// find root of a
            int rb = findRoot(findRoot, b);// find root of b
            if (ra == rb) return false; // already in the same set      
            root[rb] = ra;
            return true;
        };
        // check if the graph is a tree
        for (auto& e : edges) {
            if (e[1] == 0) continue; // skip the second bad edge          
            if (!unite(e[0], e[1])) { // if the edge creates a cycle        
                return bad1.empty() ? e : bad1;
            }
        }
        // if the graph is a tree, return the second bad edge
        return bad2;
    }
};

// @lc code=end

