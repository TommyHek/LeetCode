/*
 * @lc app=leetcode id=834 lang=cpp
 *
 * [834] Sum of Distances in Tree
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
private:
    vector<vector<int>> graph; // for tree representation 
    vector<int> subCnt; //for subtree count 
    vector<int> ans; //for answer           

    // dfs to count subtree size and calculate initial answer for root node
    void dfsCount(int node, int parent)
    {
        for (int nxt : graph[node])
        {
            if (nxt == parent) continue;
            dfsCount(nxt, node);// dfs to child node
            subCnt[node] += subCnt[nxt];// count subtree size
            ans[node]   += ans[nxt] + subCnt[nxt];// calculate initial answer for root node
        }
    }

    // dfs to re-root the tree and calculate answer for each node
    void dfsReRoot(int node, int parent, int n)
    {
        for (int nxt : graph[node])//
        {
            if (nxt == parent) continue;
            ans[nxt] = ans[node] - subCnt[nxt] + (n - subCnt[nxt]); // re-rooting the tree
            dfsReRoot(nxt, node, n);// dfs to child node
        }
    }
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges)
    {
        graph.assign(n, {});// initialize graph with n nodes
        // build the graph from edges
        for (auto &e : edges) 
        {   
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        subCnt.assign(n, 1); // initialize subtree count with 1 (itself)
        ans.assign(n, 0);// initialize answer with 0

        dfsCount(0, -1);
        dfsReRoot(0, -1, n);

        return ans;
    }
};
// @lc code=end

